#include "A1_T4_S17,18_20230482_20230497_Instructions.h"
#include "A1_T4_S17,18_20230482_20230497_ram.h"
#include "A1_T4_S17,18_20230482_20230497_Registers.h"
#include "A1_T4_S17,18_20230482_20230497_CPU.h"
#include <bits/stdc++.h>
int counter=0;
bool step=false;
bool loaded=false;
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
                if ((num < min || num > max) || invalid ||(max==254 && num%2!=0)) {
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

    void load_program(){
        loaded= true;
        reset_memory();
        string file_path = getFilePath("Enter the file path of your program :");
        fstream f(file_path,ios::in);
        cout << "Where do you want to load the program in the memory ?" << endl;
        cout << "(enter a number from 2 to 254)" << endl;
        counter = take_valid_input("Error: Invalid input", 2, 254);
        instructions.load_file(f,ram,counter);
        f.close();
        loaded= true;

    }
    void run_new_program() {
        step=false;
        cpu.operate(ram, registers, counter, step);
        cout << endl;
        ram.print();
        registers.print();
        cpu.display();
    }

    void run_step_by_step() {
        step=true;
        cpu.operate(ram, registers, counter, step);
    }



public:
    MainUI() : is_running(true) {
        cout << "      <<<<Vole Machine>>>>" << endl;
    }

    void run_menu() {
        while (is_running) {
            cout << "\nVOLE Machine Main Menu\n"
                 << "Please select an option:\n"
                 << "1) Load a new program\n"
                 << "2) Run Program as a Whole\n"
                 << "3) Run Program Step by Step\n"
                 << "4) Exit\n";

            int choice = take_valid_input("Invalid choice. Please try again.", 1, 4);

            switch(choice) {
                case 1:
                    load_program();
                    break;
                case 2:
                    if(loaded)
                    run_new_program();
                    else{
                        cout<<"PLease load a program first"<<endl;
                        run_menu();
                    }
                    break;
                case 3:
                    if(loaded)
                    run_step_by_step();
                    else{
                        cout<<"PLease load a program first"<<endl;
                        run_menu();
                    }
                    break;
                case 4:
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