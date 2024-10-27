#include "ram.h"
using namespace std;

void RAM::print() {
    cout << "\n----\n";
    cout << "Memory    Hexa    Binary\n";
    cout << "----\n";

    for (int i = 0; i < memory.size(); i++) {
        cout << "M" << decimalToHexadecimal(i)
             << setw(11) << setfill(' ') << memory[i]
             << setw(17) << setfill(' ')
             << decimalToBinary(stoi(memory[i], nullptr, 16)) << endl;
    }
    cout << "----\n";
}