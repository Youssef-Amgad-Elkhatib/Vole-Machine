#include "Instructions.h"
#include <bits/stdc++.h>

using namespace std;
bool Instructions::isHexChar(char c) const {
    static const vector<char> hexChars = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F'
    };
    return find(hexChars.begin(), hexChars.end(), toupper(c)) != hexChars.end();
}
bool Instructions::check_op(char c) const {
    static const vector<char> hexChars = {
            '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D'
    };
    return find(hexChars.begin(), hexChars.end(), toupper(c)) != hexChars.end();
}

bool Instructions::load_file(fstream& file, RAM& m1, int program_counter) {
    string x;
    while (file >> x) {
        // Validate 4-character length and hex content
        if (x.length() != 4 ||
            !(check_op(x[0]) && isHexChar(x[1]) && isHexChar(x[2]) && isHexChar(x[3]))) {
            continue;
        }
        if(program_counter + 1 >= m1.memory.size()){
            cout << "\033[1;31mError: There is not enough memory to run this program.\033[0m\n";
            return false;
        }

        string cell1 = x.substr(0, 2);
        string cell2 = x.substr(2, 2);

        m1.memory[program_counter] = cell1;
        m1.memory[program_counter + 1] = cell2;
        program_counter += 2;
        }
    return true;
    }



