#ifndef RAM_H
#define RAM_H

#include "memory.h"

class RAM : public Memory {
public:
    RAM() {
        memory.resize(256, "00");  // Initialize 256 memory locations with "00"
    }

    void print() override;
    int get_size() const override { return 256; }
};

#endif