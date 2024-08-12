/*
 * fileparser.h
 *
 * This is a file-parsing object that accepts.
 *
 * Created by Randy Truong on 8/9/24.
 */

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
