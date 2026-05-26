#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct LogStats {
    int totalLines = 0;
    int infoCount = 0;
    int warningCount = 0;
    int errorCount = 0;
    std::vector<std::string> errorMessages;
};

bool containsKeyword(const std::string& line, const std::string& keyword) {
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

        if (containsKeyword(line, "INFO")) {
            stats.infoCount++;
        } else if (containsKeyword(line, "WARNING")) {
            stats.warningCount++;
        } else if (containsKeyword(line, "ERROR")) {
            stats.errorCount++;
            stats.errorMessages.push_back(line);
        }
    }

    return stats;
}

std::string getSystemStatus(const LogStats& stats) {
    if (stats.errorCount == 0) {
        return "Healthy";
    } else if (stats.errorCount <= 2) {
        return "Needs attention";
    } else {
        return "Critical";
    }
}

void printReport(const LogStats& stats) {
    std::cout << "==============================" << std::endl;
    std::cout << "      Log Analysis Report      " << std::endl;
    std::cout << "==============================" << std::endl;

    std::cout << "Total log lines:  " << stats.totalLines << std::endl;
    std::cout << "INFO messages:    " << stats.infoCount << std::endl;
    std::cout << "WARNING messages: " << stats.warningCount << std::endl;
    std::cout << "ERROR messages:   " << stats.errorCount << std::endl;
    std::cout << "System status:    " << getSystemStatus(stats) << std::endl;

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

void saveReportToFile(const LogStats& stats, const std::string& outputFileName) {
    std::ofstream reportFile(outputFileName);

    if (!reportFile.is_open()) {
        std::cerr << "Error: Could not create report file: " << outputFileName << std::endl;
        return;
    }

    reportFile << "==============================" << std::endl;
    reportFile << "      Log Analysis Report      " << std::endl;
    reportFile << "==============================" << std::endl;

    reportFile << "Total log lines:  " << stats.totalLines << std::endl;
    reportFile << "INFO messages:    " << stats.infoCount << std::endl;
    reportFile << "WARNING messages: " << stats.warningCount << std::endl;
    reportFile << "ERROR messages:   " << stats.errorCount << std::endl;
    reportFile << "System status:    " << getSystemStatus(stats) << std::endl;

    reportFile << std::endl;

    if (!stats.errorMessages.empty()) {
        reportFile << "Detected errors:" << std::endl;

        for (const auto& error : stats.errorMessages) {
            reportFile << "- " << error << std::endl;
        }
    } else {
        reportFile << "No errors detected." << std::endl;
    }

    reportFile << "==============================" << std::endl;
}

int main(int argc, char* argv[]) {
    std::string inputFileName = "sample.log";
    std::string outputFileName = "analysis_report.txt";

    if (argc > 1) {
        inputFileName = argv[1];
    }

    if (argc > 2) {
        outputFileName = argv[2];
    }

    LogStats stats = analyzeLogFile(inputFileName);

    printReport(stats);
    saveReportToFile(stats, outputFileName);

    std::cout << std::endl;
    std::cout << "Report saved to: " << outputFileName << std::endl;

    return 0;
}
