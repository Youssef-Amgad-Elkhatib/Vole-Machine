#include "Registers.h"
#include <bits/stdc++.h>

void Registers::print() {
    cout<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"Register"<<"   "<<"Hexa"<<"        "<<"Binary"<<endl;
    cout<<"-----------------------------------"<<endl;
for(int i=0; i<registers.size(); i++){
    cout<<"R"<<decimalToHexadecimal(i)<<setw(11)<<setfill(' ')<<registers[i]<<setw(17)<<setfill(' ')<<decimalToBinary(stoi(registers[i],
                                                                                                           nullptr,16))<<endl;
}
    cout<<"-----------------------------------"<<endl;
}

string Registers::decimalToHexadecimal(int decimal) {
    stringstream ss;
    ss << uppercase << hex << setw(2) << setfill('0') << decimal;
    return ss.str();
}

string Registers::decimalToBinary(int decimal) {
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
