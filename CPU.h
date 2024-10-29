#ifndef VOLE_MACHINE_CPU_H
#define VOLE_MACHINE_CPU_H
#include "ram.h"
#include "Registers.h"
#include <bits/stdc++.h>
using namespace std;

class CPU {
private:
    int program_counter = 1;
    int hexCharToInt(char hexChar);
public:
    void operate(RAM &m1, Registers &r1, int counter,bool step) ;
    int get_pc();
};

#endif //VOLE_MACHINE_ALU_H