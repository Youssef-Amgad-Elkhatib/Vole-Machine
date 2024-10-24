#ifndef VOLE_MACHINE_REGISTERS_H
#define VOLE_MACHINE_REGISTERS_H
#include <bits/stdc++.h>
using namespace std;

class Registers {
    vector<string> registers;
    friend class ALU;
    string decimalToHexadecimal(int decimal);
    string decimalToBinary(int decimal);
public:
    Registers():registers(16,"00"){}
    void print();
};


#endif //VOLE_MACHINE_REGISTERS_H
