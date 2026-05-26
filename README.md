# C++ Log Analyzer

A command-line C++ tool for analyzing software log files and generating a simple debugging report.

## Project Overview

This project reads a log file, counts different types of log messages and prints a summary report. It is designed as a small software engineering practice project focused on C++, file handling, debugging and command-line tools.

The program currently detects:

- INFO messages
- WARNING messages
- ERROR messages
- Full error lines for debugging

## Technologies Used

- C++
- Standard Template Library
- File input/output
- Command-line arguments

## Project Structure

cpp-log-analyzer/

- main.cpp
- sample.log
- report_example.txt
- README.md
- LICENSE
- .gitignore

## How to Run

Run with the default sample log file:

`./log-analyzer`

Or provide a custom log file:

`./log-analyzer sample.log`

You can also specify both input and output files:

`./log-analyzer sample.log analysis_report.txt`

On Windows PowerShell:

`g++ main.cpp -o log-analyzer.exe`

`.\log-analyzer.exe sample.log`

## Example Output

Log Analysis Report

Total log lines: 9  
INFO messages: 5  
WARNING messages: 2  
ERROR messages: 2  
System status: Needs attention  

Detected errors:

- 2026-05-26 10:00:15 ERROR Failed to connect to authentication service
- 2026-05-26 10:00:30 ERROR Request failed with status code 500
- 
## What I Practiced

- Reading files in C++
- Working with strings
- Counting and categorizing log entries
- Using command-line arguments
- Creating a simple debugging report
- Writing clear project documentation

## Possible Improvements

- Export report to a separate file
- Add support for more log levels
- Add date filtering
- Add unit tests
- Add JSON or CSV output format
