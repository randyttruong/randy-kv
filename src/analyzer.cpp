//
// Created by Randy Truong on 8/2/24.

#include "analyzer.h"

/*
 * Constructor
 */
Analyzer::Analyzer() {}

/*
 * Basic analysis engine.
 */
void Analyzer::analyze() {
  OperatorType currentOperatorType = this->ast.getOperatorType();
  // switch (currentOperatorType) {
    /*
     * GET Semantic Analysis
     * Make sure that this is a semantically sound operation:
     */
    // case OperatorType::GET:
    //   GET getQuery = this->ast.getGetQuery();
    //   if (getQuery) {
    //
    //   }
    // /*
    //  * SET Semantic Analysis
    //  * Make sure that this is a semanti
    //  */
    // case OperatorType::SET:
    //  SET setQuery = this->ast.getSetQuery();
    //  if () {
    //
    //  }
    // /*
    //  * DELETE Semantic Analysis
    //  */
    // case OperatorType::DELETE:
    //  DELETE delQuery = this->ast.getDeleteQuery();
    //  if () {
    //
    //  }
    // default:

  // }


  return;
}
