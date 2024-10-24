#include "ALU.h"
#include "Memory.h"
#include <bits/stdc++.h>
using namespace std;

void ALU::operate(Memory &m1, Registers &r1) {
    for(int i = 0; i < m1.memory.size(); i+=2) {
        string z = m1.memory[i] + m1.memory[i+1];

        switch (z[0]) {
            case '1': {
                string x = m1.memory[i+1];
                r1.registers[z[1]-'0'] = m1.memory[stoi(x, nullptr, 16)];
                break;
            }
            case '2': {
                string x = m1.memory[i+1];
                r1.registers[z[1]-'0'] = x;
                break;
            }
            case '3': {
                string mem_cell_location = string(1, z[2]) + string(1, z[3]);
                string reg_cell_location = string(1, z[1]);

                int mem_index = stoi(mem_cell_location, nullptr, 16);
                int reg_index = stoi(reg_cell_location, nullptr, 16);

                m1.memory[mem_index] = r1.registers[reg_index];
                break;
            }
            case '4': {
                string reg1_cell_location = string(1, z[2]);
                string reg2_cell_location = string(1, z[3]);

                int reg1_index = stoi(reg1_cell_location, nullptr, 16);
                int reg2_index = stoi(reg2_cell_location, nullptr, 16);

                r1.registers[reg2_index] = r1.registers[reg1_index];
                break;
            }
            case '5': {
                string reg_result = string(1, z[1]);
                string reg_s = string(1, z[2]);
                string reg_t = string(1, z[3]);

                int r_index = stoi(reg_result, nullptr, 16);
                int s_index = stoi(reg_s, nullptr, 16);
                int t_index = stoi(reg_t, nullptr, 16);

                int s_value = stoi(r1.registers[s_index], nullptr, 16);
                int t_value = stoi(r1.registers[t_index], nullptr, 16);

                int result = s_value + t_value;

                stringstream ss;
                ss << uppercase << hex << setw(2) << setfill('0') << (result & 0xFF);
                r1.registers[r_index] = ss.str();
                break;
            }
            case '6': {
                string reg_result = string(1, z[1]);
                string reg_s = string(1, z[2]);
                string reg_t = string(1, z[3]);

                int r_index = stoi(reg_result, nullptr, 16);
                int s_index = stoi(reg_s, nullptr, 16);
                int t_index = stoi(reg_t, nullptr, 16);

                float s_value = stoi(r1.registers[s_index], nullptr, 16) / 16.0f;
                float t_value = stoi(r1.registers[t_index], nullptr, 16) / 16.0f;

                float result = s_value + t_value;

                int hex_result = round(result * 16);

                stringstream ss;
                ss << uppercase << hex << setw(2) << setfill('0') << (hex_result & 0xFF);
                r1.registers[r_index] = ss.str();
                break;
            }
            case 'B': {
                string reg_compare = string(1, z[1]);
                string jump_address = string(1, z[2]) + string(1, z[3]);

                int reg_index = stoi(reg_compare, nullptr, 16);

                if (r1.registers[reg_index] == r1.registers[0]) {
                    // Jump
                    i = (stoi(jump_address, nullptr, 16) * 2) - 2;
                }
                break;
            }
            case 'C': {
                return;
            }
            default:
                continue;
        }
    }
}