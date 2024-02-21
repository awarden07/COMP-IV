// Copyright 2023 Adam Warden

#include "FibLFSR.hpp"
#include <stdexcept>
#include <string>

class Error {};

FibLFSR::FibLFSR(std::string seed) {
  // check if seed is empty
  if (seed.empty()) {
    throw std::invalid_argument("seed cannot be empty");
  }
  // check if seed is not binary
  for (size_t i = 0; i < seed.length(); i++) {
    if (seed[i] != '0' && seed[i] != '1') {
      throw std::invalid_argument("seed must be binary");
    }
  }
  // check if seed is not 16 bits
  if (seed.length() != 16) {
    throw std::invalid_argument("seed must be 16 bits");
  }
  // set seed
  this->seed = seed;
}

int FibLFSR::step() {
    // Calculate the new output bit
    int index_output = seed[0] ^ seed[2] ^ seed[3] ^ seed[5];

    // Shift the bits to the left
    for (int i = 0; i < 15; i++) {
        seed[i] = seed[i + 1];
    }

    // Set the rightmost bit based on the calculated output
    seed[15] = (index_output == 0) ? '0' : '1';

    return index_output;
}

int FibLFSR::generate(int k) {
  // check if k is less than 0
  if (k < 0) {
    throw std::invalid_argument("k must be greater than 0");
  }
  // initialize variable to 0
  int result = 0;
  for (int i = 0; i < k; i++) {
    result = result * 2 + step();
  }
  // return result
  return result;
}

std::ostream& operator<<(std::ostream& output, const FibLFSR& fib) {
    output << fib.seed;
    return output;
}
