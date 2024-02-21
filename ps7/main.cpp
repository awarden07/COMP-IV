// Copyright Adam Warden 2023

#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;
using boost::regex;
using boost::regex_match;
using boost::regex_error;
using boost::regex_constants::error_bad_pattern;
using boost::regex_constants::error_collate;
using boost::regex_constants::error_ctype;
using boost::regex_constants::error_escape;
using boost::regex_constants::error_backref;
using boost::regex_constants::error_brack;
using boost::regex_constants::error_paren;
using boost::regex_constants::error_brace;
using boost::regex_constants::error_badbrace;
using boost::smatch;

struct BootReport {
    string fileName;
    int linesScanned;
    int bootsScanned;
    int bootsCompleted;
};

void generateBootReport(ostream& os, const BootReport& report);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <inputFileName>" << endl;
        return 1;
    }

    string inputFileName = argv[1];
    string outputFileName = inputFileName + ".rpt";
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file" << endl;
        return 1;
    }

    ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        cerr << "Unable to open output file" << endl;
        return 1;
    }

    int lineCount = 0;
    int matchCount = 0;
    int completed = 0;

    string line;
    regex startSequence(".*\\(log\\.c\\.166\\) server started.*");
    string successSequencePattern =
    ".*oejs\\.AbstractConnector:Started SelectChannelConnector@0\\.0\\.0\\.0:9080.*";
    regex successSequence(successSequencePattern);

    while (getline(inputFile, line)) {
        if (regex_match(line, startSequence)) {
            matchCount++;
        } else if (regex_match(line, successSequence)) {
            completed++;
        }
        lineCount++;
    }

    BootReport report{inputFileName, lineCount, matchCount, completed};
    generateBootReport(outputFile, report);

    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);
    lineCount = 0;
    bool isComplete = true;
    boost::posix_time::ptime startTime;

    while (getline(inputFile, line)) {
        if (regex_match(line, startSequence)) {
            if (!isComplete) {
                outputFile << "**** Incomplete boot ****" << endl << endl;
            }
            outputFile << endl;
            outputFile << "=== Device boot ===" << endl;
            outputFile << (lineCount + 1) << "(" << inputFileName << "): "
                        << line.substr(0, 19);
            outputFile << " Boot Start" << endl;
            isComplete = false;
            startTime = boost::posix_time::time_from_string(line.substr(0, 19));

        } else if (regex_match(line, successSequence)) {
            outputFile << (lineCount + 1) << "(" << inputFileName << "): "
                        << line.substr(0, 19);
            outputFile << " Boot Completed" << endl;
            boost::posix_time::ptime endTime =
                boost::posix_time::time_from_string(line.substr(0, 19));
            const auto duration = (endTime - startTime).total_milliseconds();
            outputFile << "   Boot Time: " << duration << "ms" << endl;
            isComplete = true;
        }
        lineCount++;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

void generateBootReport(ostream& os, const BootReport& report) {
    os << "Device Boot Report" << endl << endl;
    os << "InTouch log file: " << report.fileName << endl;
    os << "Lines Scanned: " << report.linesScanned << endl << endl;
    os << "Device boot count: initiated = " << report.bootsScanned
       << ", completed: " << report.bootsCompleted;
    os << endl << endl;
}
