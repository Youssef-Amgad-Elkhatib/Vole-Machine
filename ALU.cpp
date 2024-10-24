
#include "ALU.h"
#include "Memory.h"
#include <bits/stdc++.h>
using namespace std;
void ALU::operate(Memory &m1, Registers &r1) {
for(int i=0; i<m1.memory.size(); i+=2){
    string z=m1.memory[i]+m1.memory[i+1];
    switch (z[0]) {
        case '1':{
            string x=m1.memory[i+1];
            r1.registers[z[1]-'0']=m1.memory[stoi(x, nullptr,16)];
            break;
        }
        case '2': {
            string x=m1.memory[i+1];
            r1.registers[z[1]-'0']=x;
            break;
        }
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case 'B':
            break;
        case 'C':{
            return;
        }

        default:
            continue;
    }
}
}
