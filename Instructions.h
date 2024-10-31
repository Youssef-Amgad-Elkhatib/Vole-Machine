#ifndef VOLE_MACHINE_INSTRUCTIONS_H
#define VOLE_MACHINE_INSTRUCTIONS_H

#include <bits/stdc++.h>
#include "ram.h"
#include "Registers.h"
using namespace std;
class Instructions {
public:
    bool load_file(fstream& file, RAM& m1, int program_counter);

    bool isHexChar(char c) const;
    bool check_op(char c) const;
};

#endif // VOLE_MACHINE_INSTRUCTIONS_H