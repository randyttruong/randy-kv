//
// Created by Randy Truong on 8/9/24.
//

#include "fileparser.h"

#include <fstream>
#include <iostream>

#include "debug.h"

#define FILE_ERROR_MSG "[ERROR] File Exception: "

FileParser::FileParser() { }

void FileParser::setInput(const std::string filename) { this->input = filename; }
void FileParser::parseFile() {
  std::cout << this->input << std::endl;
  std::ifstream file(this->input);

  if (!file.is_open()) {
    std::cerr
        << FILE_ERROR_MSG
        << "Something went wrong, file not open.";
    std::exit(1);
  }

  std::string line;

  while (std::getline(file, line)) {
    if (DEBUG_MODE) std::cout << line << std::endl;
    inputStreamPushBack(line);
  }

  file.close();
}

void FileParser::inputStreamPushBack(std::string line) { this->inputStream.push_back(line); }

std::vector<std::string> FileParser::getInputStream() { return this->inputStream; }
