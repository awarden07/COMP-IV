// Copyright 2023 Adam Warden

#pragma once

#include <string>
#include <iostream>

class FibLFSR {
 public:
    // constructor to create LFSR with the given initial seed
    explicit FibLFSR(std::string seed);

    // simulate one step and return the new bit as 0 or 1
    int step();

    // simulate k steps and return k-bit integer
    int generate(int k);

    // friend function to output the state of the LFSR as 16-bit integer
    friend std::ostream& operator<<(std::ostream& output, const FibLFSR& fib);

 private:
    std::string seed;
};
