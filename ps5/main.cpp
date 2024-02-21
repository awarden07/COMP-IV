// Copyright Adam Warden 2023

#include <iostream>
#include "EDistance.hpp"

int main() {
    std::string sequence1, sequence2;

    do {
        std::cout << "Enter sequence 1: ";
        std::cin >> sequence1;

        if (sequence1.empty()) {
            std::cout << "Sequence cannot be empty. Please try again.\n";
        }
    } while (sequence1.empty());

    do {
        std::cout << "Enter sequence 2: ";
        std::cin >> sequence2;

        if (sequence2.empty()) {
            std::cout << "Sequence cannot be empty. Please try again.\n";
        }
    } while (sequence2.empty());

    EDistance sequenceDistance(sequence1, sequence2);

    int optimalDistance = sequenceDistance.optDistance();

    std::cout << "\nOptimal Distance: " << optimalDistance << std::endl;

    std::string alignment = sequenceDistance.alignment();
    std::cout << "\nAlignment:\n" << alignment;

    return 0;
}
