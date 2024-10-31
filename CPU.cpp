#include "CPU.h"
#include <bits/stdc++.h>
using namespace std;

int CPU::hexCharToInt(char hexChar) {
    string hexString(1, hexChar);
    return stoi(hexString, nullptr, 16);
}
void CPU::operate(RAM &m1, Registers &r1, int counter,bool step) {
    cout << "The output of this program is:" << endl;
    program_counter = counter;
    while(program_counter < m1.memory.size()) {
        string IR = m1.memory[program_counter] + m1.memory[program_counter + 1];

        // Add bounds checking
        if (program_counter + 1 >= m1.memory.size()) {
            break;
        }

        switch (IR[0]) {
            case '1': {  // LOAD from memory
                string xy = string(1, IR[2]) + string(1, IR[3]);
                int mem_addr = stoi(xy, nullptr, 16);
                if (mem_addr < m1.memory.size()) {
                    r1.memory[IR[1] - '0'] = m1.memory[mem_addr];
                }
                break;
            }
            case '2': {  // LOAD immediate
                string xy = string(1, IR[2]) + string(1, IR[3]);
                r1.memory[IR[1] - '0'] = xy;  // Load XY directly into register
                break;
            }
            case '3': {  // STORE
                string mem_cell_location = string(1, IR[2]) + string(1, IR[3]);
                int mem_index = stoi(mem_cell_location, nullptr, 16);
                int reg_index = hexCharToInt(IR[1]);

                if (mem_index < m1.memory.size() && reg_index < 16) {
                    m1.memory[mem_index] = r1.memory[reg_index];
                    if(mem_index == 0){
                        cout <<"Output: "<< m1.memory[mem_index] << endl;
                    }
                }
                break;
            }
            case '4': {  // MOVE
                int reg_source = hexCharToInt(IR[1]);
                int reg_dest = hexCharToInt(IR[2]);

                if (reg_source < 16 && reg_dest < 16) {
                    r1.memory[reg_dest] = r1.memory[reg_source];
                }
                break;
            }
            case '5': {  // ADD two's complement
                int r_index = hexCharToInt(IR[1]);
                int s_index = hexCharToInt(IR[2]);
                int t_index = hexCharToInt(IR[3]);

                if (r_index < 16 && s_index < 16 && t_index < 16) {
                    int s_value = stoi(r1.memory[s_index], nullptr, 16);
                    int t_value = stoi(r1.memory[t_index], nullptr, 16);
                    int result = s_value + t_value;

                    stringstream ss;
                    ss << uppercase << hex << setw(2) << setfill('0') << (result & 0xFF);
                    r1.memory[r_index] = ss.str();
                }
                break;
            }
            case '6': {  // ADD floating-point
                int r_index = hexCharToInt(IR[1]);
                int s_index = hexCharToInt(IR[2]);
                int t_index = hexCharToInt(IR[3]);

                auto hex_to_float = [](string hex_string){
                    unsigned long value = stol(hex_string, nullptr, 16);
                    bitset<8> bits(value);
                    // Extract sign bit
                    unsigned int sign_bit = bits[7];
                    // Extract exponent bits
                    unsigned int exponent_bits = (bits[6] << 2) | (bits[5] << 1) | bits[4];
                    // Extract mantissa bits
                    unsigned int mantissa_bits = (bits[3] << 3) | (bits[2] << 2) | (bits[1] << 1) | bits[0];
                    // Compute exponent
                    int E = static_cast<int>(exponent_bits) - 4;
                    // Compute mantissa
                    float Mantissa = float(mantissa_bits) / 16.0;
                    // Compute sign
                    float sign = (sign_bit == 0) ? 1.0 : -1.0;
                    // Compute final value
                    float result = sign * Mantissa * pow(2, E);
                    return result;
                };

                float s_value = hex_to_float(r1.memory[s_index]);
                float t_value = hex_to_float(r1.memory[t_index]);
                float result = s_value + t_value;

                auto float_to_hex = [](float num) -> string{
                    // Handle zero case
                    if (num == 0) return "00";

                    // Get sign bit
                    unsigned int sign_bit = (num < 0) ? 1 : 0;
                    num = abs(num);

                    // Calculate exponent
                    int exponent = 0;
                    float normalized_num = num;

                    // Normalize number to be between 0.5 and 1
                    while (normalized_num > 1.0) {
                        normalized_num /= 2.0;
                        exponent++;
                    }
                    while (normalized_num < 0.5) {
                        normalized_num *= 2.0;
                        exponent--;
                    }

                    // Add bias (4) and clamp to valid range (0-7)
                    int E = exponent + 4;
                    if (E < 0) E = 0;
                    if (E > 7) E = 7;

                    // Calculate mantissa (4 bits)
                    float normalized = num / pow(2, E - 4);
                    int mantissa = round(normalized * 16);
                    if (mantissa >= 16) {
                        mantissa = 15;  // Max 4-bit value
                    }

                    // Combine bits into final value
                    unsigned int final_value = (sign_bit << 7) | (E << 4) | mantissa;

                    // Convert to hex string
                    stringstream ss;
                    ss << uppercase << hex << setw(2) << setfill('0') << final_value;
                    return ss.str();
                };
                string r = float_to_hex(result);
                r1.memory[r_index] = r;
                break;
            }
            case '7':{ // ORing
                int r_index = hexCharToInt(IR[1]);
                int s_index = hexCharToInt(IR[2]);
                int t_index = hexCharToInt(IR[3]);

                int s_value = stoi(r1.memory[s_index], nullptr, 16);
                int t_value = stoi(r1.memory[t_index], nullptr, 16);
                int result = s_value | t_value;

                stringstream ss;
                ss << uppercase << hex << setw(2) << setfill('0') << (result & 0xFF);
                r1.memory[r_index] = ss.str();
                break;
            }
            case '8': { // ANDing
                int r_index = hexCharToInt(IR[1]);
                int s_index = hexCharToInt(IR[2]);
                int t_index = hexCharToInt(IR[3]);

                int s_value = stoi(r1.memory[s_index], nullptr, 16);
                int t_value = stoi(r1.memory[t_index], nullptr, 16);
                int result = s_value & t_value;

                stringstream ss;
                ss << uppercase << hex << setw(2) << setfill('0') << (result & 0xFF);
                r1.memory[r_index] = ss.str();
                break;
            }
            case '9': { // XORing
                int r_index = hexCharToInt(IR[1]);
                int s_index = hexCharToInt(IR[2]);
                int t_index = hexCharToInt(IR[3]);

                int s_value = stoi(r1.memory[s_index], nullptr, 16);
                int t_value = stoi(r1.memory[t_index], nullptr, 16);
                int result = s_value ^ t_value;

                stringstream ss;
                ss << uppercase << hex << setw(2) << setfill('0') << (result & 0xFF);
                r1.memory[r_index] = ss.str();
                break;
            }
            case'A': {//ROTATE
                auto convert = [](const string &number, int fromBase, int toBase)-> string {
                    // Convert to decimal
                    long long decimal = 0;
                    for (char c : number) {
                        int digit = isdigit(c) ? c - '0' : toupper(c) - 'A' + 10;
                        if (digit < 0 || digit >= fromBase) return "Invalid input";
                        decimal = decimal * fromBase + digit;
                    }

                    // Convert decimal to target base
                    string result;
                    do {
                        int remainder = decimal % toBase;
                        result += remainder < 10 ? remainder + '0' : remainder - 10 + 'A';
                        decimal /= toBase;
                    } while (decimal > 0);

                    reverse(result.begin(), result.end());
                    return result;
                };
                int r_index = hexCharToInt(IR[1]);
                string binary_value = convert(r1.memory[r_index],16,2);
                int k = stoi(r1.memory[IR[3]], nullptr, 16);
                string result = binary_value.substr(k) + binary_value.substr(0, k);
                r1.memory[r_index] = convert(result,2,16);
                break;
            }
            case 'B': { // JUMP
                int reg_index = hexCharToInt(IR[1]);
                string jump_address = string(1, IR[2]) + string(1, IR[3]);

                if (reg_index >= 0 && reg_index < 16) {
                    if (r1.memory[reg_index] == r1.memory[0]) {
                        int new_pc = stoi(jump_address, nullptr, 16);
                        if (new_pc >= 0 && new_pc < m1.memory.size()) {
                            program_counter = new_pc;
                            continue;
                        }
                    }
                }
                break;
            }
            case 'D': { // JUMP if R > 0 (two's complement)
                int reg_index = hexCharToInt(IR[1]);
                string jump_address = string(1, IR[2]) + string(1, IR[3]);

                if (reg_index >= 0 && reg_index < 16) {
                    // Compare as two's complement integers
                    int reg_val = stoi(r1.memory[reg_index], nullptr, 16);
                    int zero_val = stoi(r1.memory[0], nullptr, 16);

                    if (reg_val > zero_val) {
                        int new_pc = stoi(jump_address, nullptr, 16);
                        if (new_pc >= 0 && new_pc < m1.memory.size()) {
                            program_counter = new_pc;
                            continue;
                        }
                    }
                }
                break;
            }
            case 'C': {  // HALT
                return;
            }
            default:
                continue;
        }
        if(step){
            cout<<"Current Instruction: "<<IR<<"   "<<"Current Counter: "<<counter<<endl;
            m1.print();
            r1.print();
        }
        program_counter += 2;
    }
}

int CPU::get_pc(){
    return program_counter;
}


