// Copyright Adam Warden 2023

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <unordered_map>
#include "RandWriter.hpp"

RandWriter::RandWriter(std::string text, size_t order, int length) : text(text), order(order), length(length) {
    initializeAlphabet();
    initializeNgram();
    initializeMapping();
}

size_t RandWriter::getOrder() const {
    return order;
}

void RandWriter::initializeAlphabet() {
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~\x7F\x00\x01\x02\x03\x04\x05\x06\x07\x08\t\n\x0B\x0C\r\x0E\x0F\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1A\x1B\x1C\x1D\x1E\x1F";
}

void RandWriter::initializeNgram() {
    srand(time(NULL));
    if (order > 0) {
        size_t randFirstChar = rand() % (text.length() - order);
        ngram = text.substr(randFirstChar, order);
    }
    else {
        ngram = "";
    }
}

void RandWriter::initializeMapping() {
    if (order > 0) {
        for (auto textScanner = text.begin(); textScanner <= text.end() - order - 1; textScanner++) {
            std::string ngram_found(textScanner, textScanner + order);
            char next_char = textScanner[order];
            map_struct[ngram_found].push_back(next_char);
        }
    }
}

std::string RandWriter::getCurrentNgram() const {
    return ngram;
}

std::string RandWriter::getAlphabet() const {
    return alphabet;
}

int RandWriter::getFrequency(std::string ngram) const {
    if (ngram.length() != order) {
        throw std::invalid_argument("Sorry, the length of ngram does not match the order.");
    }
    int ngramCounter = 0;
    for (auto textScanner = text.begin(); textScanner <= text.end() - order; textScanner++) {
        if (std::string(textScanner, textScanner + order) == ngram) {
            ngramCounter++;
        }
    }
    return ngramCounter;
}

int RandWriter::getFrequency(std::string ngram, char c) const {
    if (ngram.length() != order) {
        throw std::invalid_argument("Sorry, the length of ngram does not match the order.");
    }
    int ngramCounter = 0;
    for (auto textScanner = text.begin(); textScanner <= text.end() - order - 1; textScanner++) {
        if (std::string(textScanner, textScanner + order + 1) == ngram + c) {
            ngramCounter++;
        }
    }
    return ngramCounter;
}

int RandWriter::countK1grams() const{
    int k1Counter = 0;

    for (size_t i = 0; i < text.length() - getOrder() - 1; i++) {
        std::string ngram = text.substr(i, getOrder());
        char next_char = text[i + getOrder()];

        if (text.substr(i + 1, getOrder()) == ngram + next_char) {
            k1Counter++;
        }
    }

    return k1Counter;
}

char RandWriter::getRandomChar(std::string ngram) {
    if (ngram.length() != order) {
        throw std::invalid_argument("Sorry, the length of ngram does not match the order.");
    }

    auto textScanner = map_struct.find(ngram);
    if (textScanner == map_struct.end()) {
        throw std::runtime_error("Sorry, no characters follow the given ngram.");
    }

    std::vector<char>& rChar = map_struct[ngram];

    srand(time(NULL));
    int rIndex = rand() % rChar.size();

    return rChar[rIndex];
}

std::string RandWriter::generateText(std::string ngram, int L) {
    if (ngram.length() != order) {
        throw std::invalid_argument("Sorry, the length of ngram does not match the order.");
    }
    if (L < static_cast<int>(getOrder())) {
        throw std::invalid_argument("Sorry, the value of L must be greater than or equal to order.");
    }

    std::string genText = ngram;
    for (size_t i = 0; i < L - getOrder(); ++i) {
        char nextChar;

        if (getOrder() == 0) {
            nextChar = text[rand() % text.size()];
        }
        else {
            nextChar = getRandomChar(ngram);
            for (size_t j = 0; j < ngram.length() - 1; ++j) {
                ngram[j] = ngram[j + 1];
            }
            ngram[ngram.length() - 1] = nextChar;
        }
        genText += nextChar;
    }

    return genText;
}

std::ostream& operator<<(std::ostream& os, const RandWriter& rw) {
    os << "Order: " << rw.order << std::endl;
    os << "Length: " << rw.length << std::endl;
    os << "Alphabet: " << rw.alphabet << std::endl;
    os << "Current Ngram: " << rw.ngram << std::endl;
    os << "Mapping: " << std::endl;
    for (const auto& entry : rw.map_struct) {
        std::string ngram = entry.first;
        const std::vector<char>& charVector = entry.second;
        os << ngram << ": ";
        for (char c : charVector) {
            os << c << " ";
        }
        os << std::endl;
    }
    return os;
}
