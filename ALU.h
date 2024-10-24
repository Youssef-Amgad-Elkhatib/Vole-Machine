#ifndef VOLE_MACHINE_ALU_H
#define VOLE_MACHINE_ALU_H
#include "Memory.h"
#include "Registers.h"
#include <bits/stdc++.h>
using namespace std;

class ALU {
public:
    void operate(Memory &m1,Registers &r1);
};


#endif //VOLE_MACHINE_ALU_H
