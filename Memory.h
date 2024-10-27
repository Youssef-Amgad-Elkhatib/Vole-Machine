#ifndef MEMORY_H
#define MEMORY_H

#include <bits/stdc++.h>

using namespace std;
class Memory {
protected:
    vector<string> memory;

    // Common utility functions for all memory types
    string decimalToBinary(int decimal);
    string decimalToHexadecimal(int decimal);

public:
    virtual void print() = 0;
    virtual int get_size() const = 0;
    virtual void set_cell(int index, string value);
    virtual string get_cell(int index);

    friend class Instructions;
    friend class ALU;
    friend class MainUI;

};

#endif