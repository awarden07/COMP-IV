// Copyright Adam Warden 2023

#include <iostream>
#include <fstream>
#include "RandWriter.hpp"

int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <order> <length>" << std::endl;
        return 1;
    }

    // Extract command-line arguments
    std::string inputFileName = argv[1];
    size_t order = std::stoul(argv[2]);
    int length = std::stoi(argv[3]);

    // Read the contents of the input file
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the input file." << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    // Create a RandWriter instance
    RandWriter randWriter(text, order, length);

    // Print information about the RandWriter instance
    std::cout << randWriter << std::endl;

    return 0;
}
