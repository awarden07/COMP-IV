// Copyright Adam Warden 2023

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class RandWriter {
public:
    RandWriter(std::string text, size_t order, int length);
    size_t getOrder() const;
    int getFrequency(std::string ngram) const;
    int getFrequency(std::string ngram, char c) const;
    char getRandomChar(std::string ngram);
    std::string getAlphabet() const;
    std::string getCurrentNgram() const;
    std::string generateText(std::string ngram, int L);
    int countK1grams() const;
    friend std::ostream& operator<<(std::ostream& os, const RandWriter& rw);
    void initializeAlphabet();
    void initializeNgram();
    void initializeMapping();

private:
    std::string text;
    size_t order;
    int length;
    std::string alphabet;
    std::string ngram;
    std::unordered_map<std::string, std::vector<char>> map_struct;
    int k;
    int L;
};

std::ostream& operator<<(std::ostream& os, const RandWriter& rw);
