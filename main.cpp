#include <iostream>
#include "Instructions.h"
#include <bits/stdc++.h>
#include "Memory.h"
#include "Registers.h"
#include "ALU.h"
using namespace std;
int main() {
Instructions i1;
Memory m1;
Registers r1;
ALU a1;
cout<<"      <<<<Vole Machine>>>>"<<endl;
fstream f("tests.txt",ios::in);
    if (!f) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
i1.load_file( f,m1);
f.close();
a1.operate(m1,r1);
m1.print();
r1.print();
}
