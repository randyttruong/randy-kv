//
// executor.h
//
// A key-value store query executor in C++.
//
// Created by Randy Truong on 8/15/24.
//

#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "parser.h"
#include "hashmap.h"


class Executor {
private:
  Parser parser;
  HashMap map;

public:
  Executor(Parser parser, HashMap map);
  void executeQueries();
};

#endif //EXECUTOR_H
