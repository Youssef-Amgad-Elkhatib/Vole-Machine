#include "Instructions.h"
#include <bits/stdc++.h>

using namespace std;
bool Instructions::isHexChar(char c) const {
    static const std::vector<char> hexChars = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F',
            'a', 'b', 'c', 'd', 'e', 'f'
    };
    return find(hexChars.begin(), hexChars.end(), toupper(c)) != hexChars.end();
}

bool Instructions::load_file(fstream& file, RAM& m1, int program_counter,bool step,Registers &r1) {
    string x;
    while (file >> x) {
        // Validate 4-character length and hex content
        if (x.length() != 4 ||
            !(isHexChar(x[0]) && isHexChar(x[1]) && isHexChar(x[2]) && isHexChar(x[3]))) {
            continue;
        }
        if(program_counter + 1 >= m1.memory.size()){
            cout << "\033[1;31mError: There is not enough memory to run this program.\033[0m\n";
            return false;
        }

        string cell1 = x.substr(0, 2);
        string cell2 = x.substr(2, 2);

        m1.memory[program_counter] = cell1;
        m1.memory[program_counter + 1] = cell2;
        if(step) {
            cout << "Current Instruction: " << cell1 << cell2 << "   " << "Current Program Counter: " << program_counter
                 << endl << endl;
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
                    int reg_index = IR[1] - '0';

                    if (mem_index < m1.memory.size() && reg_index < 16) {
                        m1.memory[mem_index] = r1.memory[reg_index];
                        if(mem_index == 0){
                            cout<<"Current Output: " << m1.memory[mem_index] << endl<<endl;
                        }
                    }
                    break;
                }
                case '4': {  // MOVE
                    int reg_source = IR[1] - '0';
                    int reg_dest = IR[2] - '0';

                    if (reg_source < 16 && reg_dest < 16) {
                        r1.memory[reg_dest] = r1.memory[reg_source];
                    }
                    break;
                }
                case '5': {  // ADD two's complement
                    int r_index = IR[1] - '0';
                    int s_index = IR[2] - '0';
                    int t_index = IR[3] - '0';

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
                    int r_index = IR[1] - '0';
                    int s_index = IR[2] - '0';
                    int t_index = IR[3] - '0';

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
                    int reg_index = IR[1] - '0';
                    string jump_address = string(1, IR[2]) + string(1, IR[3]);

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
                    return true;
                }
                default:
                    continue;
            }
            m1.print();
            r1.print();

        }
        program_counter += 2;
    }
    return true;
}