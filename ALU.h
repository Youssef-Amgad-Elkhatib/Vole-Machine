#ifndef VOLE_MACHINE_ALU_H
#define VOLE_MACHINE_ALU_H
#include "ram.h"
#include "Registers.h"
#include <bits/stdc++.h>
using namespace std;

class ALU {
private:
    int program_counter = 1;
public:
    void operate(RAM &m1, Registers &r1, int counter) ;
    int get_pc();
};

#endif //VOLE_MACHINE_ALU_H