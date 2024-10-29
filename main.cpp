#include "Instructions.h"
#include "ram.h"
#include "Registers.h"
#include "CPU.h"
#include <bits/stdc++.h>

class MainUI {
private:
    Instructions instructions;
    RAM ram;
    Registers registers;
    CPU cpu;
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (!valid) {
            cout << prompt << endl;
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

        cpu = CPU();

        for (int i = 0; i < registers.get_size(); i++) {
            registers.set_cell(i, "00");
        }

    }

    void run_new_program() {
        reset_memory();
        bool step=false;
        string file_path = getFilePath("Enter the file path of your program :");
        fstream f(file_path,ios::in);
        int counter = 0;
        cout << "Where do you want to load the program in the memory ?" << endl;
        cout << "(enter a number from 1 to 255)" << endl;
        counter = take_valid_input("Error: Invalid input", 0, 255);
        bool it_is_loadable = instructions.load_file(f, ram, counter,step,registers);
        if(!it_is_loadable){
            return;
        }
        f.close();
        cpu.operate(ram, registers, counter, step);
        ram.print();
        registers.print();
    }

    void run_step_by_step() {
        bool step=true;
        string file_path = getFilePath("Enter the file path of your program :");
        fstream f(file_path,ios::in);
        int counter = 0;
        cout << "Where do you want to load the program in the memory ?" << endl;
        cout << "(enter a number from 1 to 255)" << endl;
        counter = take_valid_input("Error: Invalid input", 1, 255);
        instructions.load_file(f, ram, counter,step,registers);
        f.close();

    }



public:
    MainUI() : is_running(true) {
        cout << "      <<<<Vole Machine>>>>" << endl;
    }

    void run_menu() {
        while (is_running) {
            cout << "\nVOLE Machine Main Menu\n"
                 << "Please select an option:\n"
                 << "1) Run Program as a Whole\n"
                 << "2) Run Program Step by Step\n"
                 << "3) Exit\n";

            int choice = take_valid_input("Invalid choice. Please try again.", 1, 3);

            switch(choice) {
                case 1:
                    run_new_program();
                    break;
                case 2:
                    run_step_by_step();
                    break;
                case 3:
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