#include "ram.h"
using namespace std;

void RAM::print() {
    int columns = 16;  // Number of columns per row
    int rows = (memory.size() + columns - 1) / columns;  // Calculate the number of rows required
    cout<<"---------------"<<endl;
    cout<<"|Memory Matrix|"<<endl;
    cout<<"---------------"<<endl;
    // Print the column headers directly above each column
    cout << "    ";  // Offset for row labels
    for (int col = 0; col < columns; col++) {
        cout << setw(6) << setfill(' ')  << decimalToHexadecimal(col);
    }
    cout << "\n   -----------------------------------------------------------------------------------------------------\n";

    // Print memory matrix with row and column indicators
    for (int row = 0; row < rows; row++) {
        // Print row label
        cout  << setw(2) << setfill('0') << decimalToHexadecimal(row) << " |";

        // Print the memory values for this row
        for (int col = 0; col < columns; col++) {
            int index = row * columns + col;
            if (index < memory.size()) {
                cout << setw(6) << setfill(' ') << memory[index];
            } else {
                cout << setw(6) << " ";  // Empty space if memory size isn't a perfect multiple of columns
            }
        }
        cout << "   |\n";  // End of row
    }

    // Print the bottom border
    cout << "   -----------------------------------------------------------------------------------------------------\n";
    cout<<endl<<endl;
}

