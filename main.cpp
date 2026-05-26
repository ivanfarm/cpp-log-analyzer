#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct LogStats {
    int totalLines = 0;
    int infoCount = 0;
    int warningCount = 0;
    int errorCount = 0;
    std::vector<std::string> errorMessages;
};

bool contains(const std::string& line, const std::string& keyword) {
    return line.find(keyword) != std::string::npos;
}

LogStats analyzeLogFile(const std::string& fileName) {
    std::ifstream file(fileName);
    LogStats stats;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << fileName << std::endl;
        return stats;
    }

    while (std::getline(file, line)) {
        stats.totalLines++;

        if (contains(line, "INFO")) {
            stats.infoCount++;
        } else if (contains(line, "WARNING")) {
            stats.warningCount++;
        } else if (contains(line, "ERROR")) {
            stats.errorCount++;
            stats.errorMessages.push_back(line);
        }
    }

    return stats;
}

void printReport(const LogStats& stats) {
    std::cout << "==============================" << std::endl;
    std::cout << "      Log Analysis Report      " << std::endl;
    std::cout << "==============================" << std::endl;

    std::cout << "Total log lines: " << stats.totalLines << std::endl;
    std::cout << "INFO messages:   " << stats.infoCount << std::endl;
    std::cout << "WARNING messages:" << stats.warningCount << std::endl;
    std::cout << "ERROR messages:  " << stats.errorCount << std::endl;

    std::cout << std::endl;

    if (!stats.errorMessages.empty()) {
        std::cout << "Detected errors:" << std::endl;
        for (const auto& error : stats.errorMessages) {
            std::cout << "- " << error << std::endl;
        }
    } else {
        std::cout << "No errors detected." << std::endl;
    }

    std::cout << "==============================" << std::endl;
}

int main(int argc, char* argv[]) {
    std::string fileName = "sample.log";

    if (argc > 1) {
        fileName = argv[1];
    }

    LogStats stats = analyzeLogFile(fileName);
    printReport(stats);

    return 0;
}
