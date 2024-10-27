#include "memory.h"
using namespace std;

string Memory::decimalToBinary(int decimal) {
    if (decimal == 0) return "00000000";
    vector<int> binary;
    while (decimal > 0) {
        binary.push_back(decimal % 2);
        decimal /= 2;
    }
    reverse(binary.begin(), binary.end());
    string binaryStr;
    for (int bit : binary) {
        binaryStr += to_string(bit);
    }
    while (binaryStr.length() < 8) {
        binaryStr = "0" + binaryStr;
    }
    return binaryStr;
}

string Memory::decimalToHexadecimal(int decimal) {
    stringstream ss;
    ss << uppercase << hex << setw(2) << setfill('0') << decimal;
    return ss.str();
}

void Memory::set_cell(int index, string value) {
    if (index >= 0 && index < memory.size()) {
        memory[index] = move(value);
    }
}

string Memory::get_cell(int index){
    return memory[index];
}