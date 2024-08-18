/*
 * Created by Randy Truong on 8/15/24.
 */

#include "executor.h"

#include <iostream>

#include "hashmap.h"
#include "debug.h"

#define DEBUG_HEADER "[DEBUG] "
#define ERROR_HEADER "[ERROR] "
#define UNEXPECTED_ERROR_HEADER "[UNEXPECTED ERROR] "

#define DUMMY "test"

Executor::Executor(Parser parser, HashMap map): parser(parser), map(map) {}

void Executor::executeQueries() {
 std::vector<AbstractSyntaxTree> queries = this->parser.getQueries();
 size_t n = queries.size();

 for (size_t i = 0; i < n; i++) {
  AbstractSyntaxTree ast = queries[i];
  OperatorType op = ast.getOperatorType();

  switch (op) {
   case OperatorType::GET:
    //
    // GET <IDENTIFIER>
    //
    if (!this->map.keyExists(ast.getGetQuery().getIdentifier().getName())) {
     std::cout << ERROR_HEADER
       << "GET Operation failed. Unable to find requested key '"
       << ast.getGetQuery().getIdentifier().getName()
       << "'."
       << std::endl;

     if (!DEBUG_MODE) std::exit(1);
    }

    std::cout << this->map.getValue(ast.getGetQuery().getIdentifier().getName()) << std::endl;
    break;
   case OperatorType::SET:
    //
    // SET <IDENTIFIER> <LITERAL>
    //
    if (this->map.keyExists(ast.getSetQuery().getIdentifier().getName())) {
     std::cout << ERROR_HEADER
     << "SET Operation failed. Requested key already exists. Did you mean "
     << "to UPDATE?"
     << std::endl;

     if (!DEBUG_MODE) std::exit(1);
    } else {
     this->map.addKey(ast.getSetQuery().getIdentifier().getName(),
                      DUMMY);

     if (DEBUG_MODE) std::cout << DEBUG_HEADER << "Successfully added <" << ast.getSetQuery().getIdentifier().getName() << ", " << DUMMY << "> " << std::endl;
    }
    break;
   case OperatorType::UPDATE:
    //
    // UPDATE <IDENTIFIER> <LITERAL>
    //
    if (!this->map.keyExists(ast.getUpdateQuery().getIdentifier().getName())) {
     std::cout << ERROR_HEADER
       << "UPDATE operation failed. Requested key does not exist. Did you "
       << "mean to SET?"
       << std::endl;

     if (!DEBUG_MODE) std::exit(1);
    } else {
     this->map.updateKey(ast.getSetQuery().getIdentifier().getName(),
                      DUMMY);

     if (DEBUG_MODE) std::cout << DEBUG_HEADER << "Successfully updated '" << ast.getSetQuery().getIdentifier().getName()
                     << "'. " << std::endl;
    }
    break;
   case OperatorType::DELETE:
    //
    // UPDATE <IDENTIFIER> <LITERAL>
    //
    if (!this->map.keyExists(ast.getUpdateQuery().getIdentifier().getName())) {
     std::cout << ERROR_HEADER
       << "DELETE operation failed. Requested key does not exist."
       << std::endl;

     if (!DEBUG_MODE) std::exit(1);
    } else {
     this->map.deleteKey(ast.getSetQuery().getIdentifier().getName());

     if (DEBUG_MODE)
      std::cout << DEBUG_HEADER
        << "Successfully deleted '"
        << ast.getSetQuery().getIdentifier().getName()
        << "'. " << std::endl;
    }
    break;
   case OperatorType::VOID:
    std::cout << UNEXPECTED_ERROR_HEADER << "An error occurred. Operator is VOID. Aborting." << std::endl;

    if (DEBUG_MODE) std::exit(1);
    break;
   default:
    break;
  }
 }
}
