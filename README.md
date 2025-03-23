# Vole Machine Simulator

## Overview
The **Vole Machine Simulator** is a virtual representation of a Vole Machine, a simple computing system that executes instructions using a simulated CPU, RAM, and registers. This project provides an environment for executing Vole Machine instructions, manipulating memory, and simulating computational processes.

## Features
- **Instruction Execution**: Implements Vole Machine instruction set.
- **Memory Management**: 16x16 RAM matrix for storing data.
- **Registers**: 16 registers for temporary storage and calculations.
- **CPU Simulation**: Fetch-Decode-Execute cycle for running instructions.
- **Graphical Interface**: A Qt-based GUI for interaction (if applicable).

## Installation
### Prerequisites
- C++17 or later
- Qt framework (if using GUI)

### Steps
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/VoleMachineSimulator.git
   cd VoleMachineSimulator
   ```
2. Build the project:
   ```sh
   mkdir build && cd build
   cmake .. && make
   ```
3. Run the simulator:
   ```sh
   ./VoleMachineSimulator
   ```

## Usage
### Loading a Program
- Programs are written using Vole Machine assembly-like instructions.
- Load a program from a file or manually enter instructions.

### Supported Instructions
| Instruction | Description |
|------------|-------------|
| `LOAD Rx, Addr` | Load value from memory address into register |
| `STORE Rx, Addr` | Store value from register into memory address |
| `ADD Rx, Ry` | Add values in two registers and store in Rx |
| `SUB Rx, Ry` | Subtract Ry from Rx |
| `JMP Addr` | Jump to instruction at address |
| `CMP Rx, Ry` | Compare two registers |
| `JE Addr` | Jump if equal |
| `JNE Addr` | Jump if not equal |

### Example Program
```asm
LOAD R1, 0x05
LOAD R2, 0x06
ADD R1, R2
STORE R1, 0x07
```

## Contributing
1. Fork the repository.
2. Create a new branch: `git checkout -b feature-name`
3. Commit your changes: `git commit -m 'Add feature'`
4. Push to the branch: `git push origin feature-name`
5. Create a pull request.

## License
This project is licensed under the MIT License.

## Contact
For issues or suggestions, create an issue or contact [your email].
