#include "registers.h"
using namespace std;

void Registers::print() {
    cout << "\n----\n";
    cout << "Register   Hexa    Binary\n";
    cout << "----\n";

    for (int i = 0; i < memory.size(); i++) {
        cout << "R" << decimalToHexadecimal(i)
             << setw(11) << setfill(' ') << memory[i]
             << setw(17) << setfill(' ')
             << decimalToBinary(stoi(memory[i], nullptr, 16)) << endl;
    }
    cout << "----\n";
}