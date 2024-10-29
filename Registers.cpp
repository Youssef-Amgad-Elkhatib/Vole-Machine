#include "registers.h"
using namespace std;

void Registers::print() {
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "| Register |";

    // Print column headers for each register number, in a boxed format
    for (int i = 0; i < memory.size(); i++) {
        cout << " R" << decimalToHexadecimal(i) << setw(3) << setfill(' ');
    }
    cout << " |\n";
    cout << "---------------------------------------------------------------------------------------------\n";

    // Print hexadecimal values of registers
    cout << "| Hexa     |";
    for (int i = 0; i < memory.size(); i++) {
        cout << " " << memory[i] << "  ";
    }
    cout << "|\n";
    cout << "---------------------------------------------------------------------------------------------\n\n";
}