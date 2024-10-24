#include "Instructions.h"
#include <iostream>
#include <bits/stdc++.h>
#include "Memory.h"
using namespace std;
bool isHexChar(char c) {
    vector<char> hexChars = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F'
    };
    return find(hexChars.begin(), hexChars.end(), c) != hexChars.end();
}
void Instructions::load_file(fstream &file,Memory &m1) {
    string x;
    int i=0;
    while (file >> x) {
        if(x.length()>4 || x.empty() || !isHexChar(x[1]) || !isHexChar(x[2]) || !isHexChar(x[3]))continue;
            string cell1 = x.substr(0, 2);
            string cell2 = x.substr(2, 2);
            m1.memory[i] = cell1;
            m1.memory[i + 1] = cell2;
            i += 2;
    }
}
