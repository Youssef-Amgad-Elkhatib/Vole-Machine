#include "ALU.h"
#include <bits/stdc++.h>
using namespace std;

void ALU::operate(RAM &m1, Registers &r1, int counter) {
    cout << "The output of this program is:" << endl;
    program_counter = counter;
    while(program_counter < m1.memory.size()) {
        string z = m1.memory[program_counter] + m1.memory[program_counter + 1];

        // Add bounds checking
        if (program_counter + 1 >= m1.memory.size()) {
            break;
        }

        switch (z[0]) {
            case '1': {  // LOAD from memory
                string xy = string(1, z[2]) + string(1, z[3]);
                int mem_addr = stoi(xy, nullptr, 16);
                if (mem_addr < m1.memory.size()) {
                    r1.memory[z[1]-'0'] = m1.memory[mem_addr];
                }
                break;
            }
            case '2': {  // LOAD immediate
                string xy = string(1, z[2]) + string(1, z[3]);
                r1.memory[z[1]-'0'] = xy;  // Load XY directly into register
                break;
            }
            case '3': {  // STORE
                string mem_cell_location = string(1, z[2]) + string(1, z[3]);
                int mem_index = stoi(mem_cell_location, nullptr, 16);
                int reg_index = z[1] - '0';

                if (mem_index < m1.memory.size() && reg_index < 16) {
                    m1.memory[mem_index] = r1.memory[reg_index];
                    if(mem_index == 0){
                        cout << m1.memory[mem_index] << endl;
                    }
                }
                break;
            }
            case '4': {  // MOVE
                int reg_source = z[1] - '0';
                int reg_dest = z[2] - '0';

                if (reg_source < 16 && reg_dest < 16) {
                    r1.memory[reg_dest] = r1.memory[reg_source];
                }
                break;
            }
            case '5': {  // ADD two's complement
                int r_index = z[1] - '0';
                int s_index = z[2] - '0';
                int t_index = z[3] - '0';

                if (r_index < 16 && s_index < 16 && t_index < 16) {
                    int8_t s_value = stoi(r1.memory[s_index], nullptr, 16);
                    int8_t t_value = stoi(r1.memory[t_index], nullptr, 16);
                    int8_t result = s_value + t_value;

                    stringstream ss;
                    ss << uppercase << hex << setw(2) << setfill('0') << (static_cast<int>(result) & 0xFF);
                    r1.memory[r_index] = ss.str();
                }
                break;
            }
            case '6': {  // ADD floating-point
                int r_index = z[1] - '0';
                int s_index = z[2] - '0';
                int t_index = z[3] - '0';

                if (r_index < 16 && s_index < 16 && t_index < 16) {
                    float s_value = stoi(r1.memory[s_index], nullptr, 16) / 16.0f;
                    float t_value = stoi(r1.memory[t_index], nullptr, 16) / 16.0f;
                    float result = s_value + t_value;

                    // Convert back to hex format
                    int hex_result = int(round(result * 16)) & 0xFF;

                    stringstream ss;
                    ss << uppercase << hex << setw(2) << setfill('0') << hex_result;
                    r1.memory[r_index] = ss.str();
                }
                break;
            }
            case 'B': {  // JUMP
                int reg_index = z[1] - '0';
                string jump_address = string(1, z[2]) + string(1, z[3]);

                if (reg_index < 16) {
                    if (r1.memory[reg_index] == r1.memory[0]) {
                        int new_pc = stoi(jump_address, nullptr, 16) * 2;
                        if (new_pc < m1.memory.size()) {
                            program_counter = new_pc - 2;
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
        program_counter += 2;
    }
}

int ALU::get_pc(){
    return program_counter;
}