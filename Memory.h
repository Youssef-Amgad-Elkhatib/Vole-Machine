#ifndef VOLE_MACHINE_MEMORY_H
#define VOLE_MACHINE_MEMORY_H
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Memory {
    vector<string> memory;
    friend class Instructions;
    friend class ALU;
    string decimalToBinary2(int decimal);
    string decimalToHexadecimal2(int decimal);
public:
    Memory() : memory(256, "00") {}
    void print();

};



#endif //VOLE_MACHINE_MEMORY_H
