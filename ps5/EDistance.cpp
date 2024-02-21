// Copyright Adam Warden 2023

#include "EDistance.hpp"

EDistance::EDistance() {
    seq1 = "";
    seq2 = "";
}

EDistance::EDistance(std::string sequence1, std::string sequence2) {
    this->seq1 = sequence1;
    this->seq2 = sequence2;
}

EDistance::~EDistance() {
    seq1 = "";
    seq2 = "";
    matrix.clear();
}

int EDistance::min3(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else if (c <= a && c <= b) {
        return c;
    }
    return -1;
}

int EDistance::calculateDifference(char a, char b) {
    return (a == b) ? 0 : 1;
}


int EDistance::optDistance() {
    const int length1 = seq1.length();
    const int length2 = seq2.length();

    matrix.resize(length2 + 1, std::vector<int>(length1 + 1, 0));

    for (int i = 0; i <= length2; ++i) {
        matrix[i][length1] = (length2 - i) * 2;
    }

    for (int j = 0; j <= length1; ++j) {
        matrix[length2][j] = (length1 - j) * 2;
    }

    for (int i = length2 - 1; i >= 0; --i) {
        for (int j = length1 - 1; j >= 0; --j) {
            int a = matrix[i + 1][j + 1] +
            calculateDifference(seq1[j], seq2[i]);
            int b = matrix[i + 1][j] + 2;
            int c = matrix[i][j + 1] + 2;

            matrix[i][j] = min3(a, b, c);
        }
    }

    // Return the cost at the top-left corner of the matrix
    return matrix[0][0];
}


std::string EDistance::alignment() {
    std::ostringstream output;

    int length2 = seq2.length();
    int length1 = seq1.length();

    int i = 0, j = 0;
    int difference, a, b, c;

    while (i < length2 && j < length1) {
        difference = calculateDifference(seq1[j], seq2[i]);
        a = matrix[i + 1][j + 1] + difference;
        b = matrix[i + 1][j] + 2;
        c = matrix[i][j + 1] + 2;

        if (matrix[i][j] == a) {
            output << seq1[j] << " " << seq2[i] << " " <<
            difference << std::endl;
            ++i;
            ++j;
        } else if (matrix[i][j] == b) {
            output << "- " << seq2[i] << " 2" << std::endl;
            ++i;
        } else if (matrix[i][j] == c) {
            output << seq1[j] << " - 2" << std::endl;
            ++j;
        }
    }

    while (i < length2) {
        output << "- " << seq2[i] << " 2" << std::endl;
        ++i;
    }

    while (j < length1) {
        output << seq1[j] << " - 2" << std::endl;
        ++j;
    }

    return output.str();
}

int EDistance::penalty(char a, char b) {
    if (a == b) {
        return 0;
    } else if (a != b) {
        return 1;
    }
    return -1;
}
