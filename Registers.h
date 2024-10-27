#ifndef REGISTERS_H
#define REGISTERS_H

#include "memory.h"

class Registers : public Memory {
public:
    Registers() {
        memory.resize(16, "00");
    }

    void print() override;
    int get_size() const override { return 16; }
};

#endif