#include "Memory.h"
#include <iostream>
#include "Instructions.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void Memory::print() {
    cout<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"Memory"<<"     "<<"Hexa"<<"        "<<"Binary"<<endl;
    cout<<"-----------------------------------"<<endl;
    for (int i = 0; i < memory.size(); i++) {
        cout << "M" << decimalToHexadecimal2(i)
             << setw(11) << setfill(' ') << memory[i]
             << setw(17) << setfill(' ') << decimalToBinary2(stoi(memory[i], nullptr, 16)) << endl;
    }
    cout<<"-----------------------------------"<<endl;
}

string Memory::decimalToBinary2(int decimal) {
    if (decimal == 0) return "000000000";
    vector<int> binary;
    while (decimal > 0) {
        binary.push_back(decimal % 2);
        decimal /= 2;
    }
    reverse(binary.begin(), binary.end());
    string binaryStr = "";
    for (int bit : binary) {
        binaryStr += to_string(bit);
    }
    while (binaryStr.length() < 9) {
        binaryStr = "0" + binaryStr;
    }

    return binaryStr;
}

string Memory::decimalToHexadecimal2(int decimal) {
    stringstream ss;
    ss << uppercase << hex << setw(2) << setfill('0') << decimal;
    return ss.str();
}
