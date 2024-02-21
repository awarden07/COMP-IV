// Copyright Adam Warden 2023

#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <iostream>

class EDistance {
 public:
    EDistance();
    EDistance(std::string seq1, std::string seq2);
    ~EDistance();

    static int penalty(char a, char b);
    static int min3(int a, int b, int c);
    int optDistance();
    std::string alignment();
    static int calculateDifference(char a, char b);

 private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
};
