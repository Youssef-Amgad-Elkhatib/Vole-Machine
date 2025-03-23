# 💻 Vole Machine Simulator

## 	📖 Overview
The **Vole Machine Simulator** is a virtual representation of a Vole Machine using C++, a simple computing system that executes instructions using a simulated CPU, RAM, and registers. This project provides an environment for executing Vole Machine instructions, manipulating memory, and simulating computational processes.

</br>

## ✨ Features
- **Instruction Execution**: Implements Vole Machine instruction set.
- **Memory Management**: 16x16 RAM matrix for storing data.
- **Registers**: 16 registers for temporary storage and calculations.
- **CPU Simulation**: Fetch-Decode-Execute cycle for running instructions.

</br>

## 📜 Supported Instructions
| Instruction | Description |
|------------|-------------|
| `LOAD Rx, Addr` | Load value from memory address into register |
| `STORE Rx, Addr` | Store value from register into memory address |
| `ADD Rx, Ry` | Add values in two registers and store in Rx |
| `SUB Rx, Ry` | Subtract Ry from Rx |
| `MUL Rx, Ry` | Multiply values in two registers and store in Rx |
| `DIV Rx, Ry` | Divide Rx by Ry and store the result in Rx |
| `MOD Rx, Ry` | Compute modulus of Rx by Ry and store in Rx |
| `AND Rx, Ry` | Perform bitwise AND between two registers and store in Rx |
| `OR Rx, Ry` | Perform bitwise OR between two registers and store in Rx |
| `XOR Rx, Ry` | Perform bitwise XOR between two registers and store in Rx |
| `NOT Rx` | Perform bitwise NOT on register Rx |
| `SHL Rx, N` | Shift register Rx left by N bits |
| `SHR Rx, N` | Shift register Rx right by N bits |
| `JMP Addr` | Jump to instruction at address |
| `CMP Rx, Ry` | Compare two registers |
| `JE Addr` | Jump if equal |
| `JNE Addr` | Jump if not equal |
| `JG Addr` | Jump if greater |
| `JL Addr` | Jump if less |
| `JGE Addr` | Jump if greater or equal |
| `JLE Addr` | Jump if less or equal |
| `PUSH Rx` | Push register value onto stack |
| `POP Rx` | Pop value from stack into register |
| `CALL Addr` | Call subroutine at address |
| `RET` | Return from subroutine |
| `HLT` | Halt execution |

</br>

## ✍️ Authors

- [Youssef Amgad Elkhatib](https://github.com/Youssef-Amgad-Elkhatib)
- [Youssef Sami George](https://github.com/YoussefSamiGeorges)

