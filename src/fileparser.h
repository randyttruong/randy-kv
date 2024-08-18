//
// fileparser.h
//
// A fileparser for the .rt key-value file. Introduces the
// `FileParser` object, which has the following fields and
// methods.
//
// Fields:
// - std::string FileParser::input                       (the name of the file being parsed)
// - FILE FileParser::file                               (the FILE object of that file)
// - std::vector<std::string> FileParser::inputStream;   (the contents of the file being parsed)
//
// Getters/Setters
// + FileParser::getInputStream();
// + FileParser::setInput();
//
// Functional Methods
// + FileParser::parseFile();                            (function for parsing the file)
// + FileParser::inputStreamPushBack();                  (function for pushing to FileParser::inputStream)
//
// Created by Randy Truong on 8/9/24.
//

#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <iosfwd>
#include <string>
#include <vector>


class FileParser {
private:
  std::string input;
  FILE file;
  std::vector<std::string> inputStream;

public:
  FileParser();

  void setInput(const std::string filename);
  void parseFile();
  void inputStreamPushBack(std::string line);
  std::vector<std::string> getInputStream();
};



#endif //FILEPARSER_H
