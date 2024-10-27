#include "Instructions.h"
#include "ram.h"
#include "Registers.h"
#include "ALU.h"
#include <bits/stdc++.h>

class MainUI {
private:
    Instructions instructions;
    RAM ram;
    Registers registers;
    ALU alu;
    bool is_running;

    // Helper functions
    int take_valid_input(const string& error_msg, int min, int max) {
        while (true) {
            try {
                string text_num;
                cin >> text_num;
                if (text_num == "exit") {
                    cout << "Exiting the program. Thank you!\n";
                    exit(0);
                }
                int num = stoi(text_num);
                bool invalid = false;
                for(char ch : text_num) {
                    if(!isdigit(ch)) {
                        invalid = true;
                        break;
                    }
                }
                if ((num < min || num > max) || invalid) {
                    cout << error_msg << endl;
                    cout << "You can type 'exit' to exit the program." << endl;
                }
                else {
                    return num;
                }
            } catch (...) {
                cout << error_msg << endl;
                cout << "You can type 'exit' to exit the program." << endl;
            }
        }
    }

    string getFilePath(const string& prompt) {
        string filePath;
        bool valid = false;

        while (!valid) {
            cout << prompt << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, filePath);
            ifstream file(filePath);

            if (!file.is_open()) {
                cout << "Error: Could not open the file at '" << filePath << "'. Please try again." << endl;
            } else {
                file.close();
                valid = true;
            }
        }
        return filePath;
    }

    // Core functionality private methods
    void reset_memory() {
        for (int i = 0; i < ram.get_size(); i++) {
            ram.set_cell(i, "00");
        }

        alu = ALU();

        for (int i = 0; i < registers.get_size(); i++) {
            registers.set_cell(i, "00");
        }

    }

    void run_new_program() {
        string file_path = getFilePath("Enter the file path of your program :");
        fstream f(file_path,ios::in);
        int counter = 0;
        cout << "Where do you want to load the program in the memory ?" << endl;
        cout << "(enter a number from 0 to 255)" << endl;
        counter = take_valid_input("Error: Invalid input", 0, 255);
        instructions.load_file(f, ram, counter);
        f.close();
        alu.operate(ram, registers, counter);
    }

    void run_step_by_step() {
        // Implementation will execute program one instruction at a time
    }

    void show_memory_status() {
        cout << "Memory status: "<< endl;
        ram.print();
        registers.print();
    }

    void show_pc_value() {
        cout << "the program counter value is :" << endl;
        cout << alu.get_pc() << endl;
    }

    void show_ir_value() {
        // Implementation will display current instruction register value
    }

public:
    MainUI() : is_running(true) {
        cout << "      <<<<Vole Machine>>>>" << endl;
    }

    void run_menu() {
        while (is_running) {
            cout << "\nVOLE Machine Main Menu\n"
                 << "Please select an option:\n"
                 << "1) Run New Program\n"
                 << "2) Run Program Step by Step\n"
                 << "3) Show Memory Status\n"
                 << "4) Show Program Counter (PC)\n"
                 << "5) Show Instruction Register (IR)\n"
                 << "6) Exit\n";

            int choice = take_valid_input("Invalid choice. Please try again.", 1, 6);

            switch(choice) {
                case 1:
                    run_new_program();
                    break;
                case 2:
                    run_step_by_step();
                    break;
                case 3:
                    show_memory_status();
                    break;
                case 4:
                    show_pc_value();
                    break;
                case 5:
                    show_ir_value();
                    break;
                case 6:
                    cout << "Exiting VOLE Machine. Thank you!\n";
                    is_running = false;
                    break;
            }
        }
    }
};

int main() {
    MainUI vole_machine;
    vole_machine.run_menu();
    return 0;
}