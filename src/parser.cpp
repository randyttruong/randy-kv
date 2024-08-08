//
// Created by Randy Truong on 7/31/24.
//

#include "parser.h"
#include <iostream>
#include <set>

#include "debug.h"
#include "node.h"

#define GET_OP_FAILURE_MESSAGE      "[ERROR] GET operation failed: "
#define SET_OP_FAILURE_MESSAGE      "[ERROR] SET operation failed: "
#define DEL_OP_FAILURE_MESSAGE      "[ERROR] DELETE operation failed: "
#define UPDATE_OP_FAILIURE_MESSAGE  "[ERROR] UPDATE operation failed: "
#define UNEXPECTED_FAILURE_MESSAGE  "[ERROR] Unexpected failure: "
#define DEBUG_MODE 0


debug debug;

Parser::Parser(std::vector<Token> TokenStream): TokenStream(TokenStream), ast() {
  this->ast = AbstractSyntaxTree();
}

void Parser::parseTokenStream() {
  for (Token currToken: TokenStream) {
    const auto &[type, tokenType, value] = currToken;

    switch (type) {
      case TokenType::KEYWORD:

        // Check if operator is already defined
        if (this->ast.getOperatorType() != OperatorType::VOID) {
          std::cout << UNEXPECTED_FAILURE_MESSAGE
              << "Operator already defined. Failing."
              << std::endl;
        }

        if (value == "get") {
          GET getQuery = GET();
          this->ast.setGetQuery(getQuery);
        } else if (value == "set") {
          SET setQuery = SET();
          this->ast.setSetQuery(setQuery);
        } else if (value == "update") {
          UPDATE updateQuery = UPDATE();
          this->ast.setUpdateQuery(updateQuery);
        } else if (value == "delete") {
          DELETE delQuery = DELETE();
          this->ast.setDeleteQuery(delQuery);
        }
        break;

      case TokenType::IDENTIFIER:
        // If no operator, then fail
        if (this->ast.getOperatorType() == OperatorType::VOID) {
          std::cout << UNEXPECTED_FAILURE_MESSAGE
              << "No operator defined, failing." << std::endl;
          debug.exit(DEBUG_MODE);
        }
        switch (this->ast.getOperatorType()) {
          case OperatorType::GET:

            //
            // Check to see if an IDENTIFIER has already been
            // defined. If it is defined, then break due to
            // invalid syntax.
            if (this->ast.getGetQuery().getIdSetFlag() == 1) {
              std::cout << GET_OP_FAILURE_MESSAGE
                  << "IDENTIFIER already specified."
                  << "\nUsage: GET <KEY>"
                  << std::endl;
              debug.exit(DEBUG_MODE);
            } else {
              this->ast.getGetQuery().setIdentifier(currToken);
              break;
            }
          case OperatorType::SET:

            //
            // Check to see if IDENTIFIER has already been defined.
            // If it is defined, then break due to double IDENTIFIERs.
            if (this->ast.getSetQuery().getIdSetFlag() == 1) {
              std::cout << SET_OP_FAILURE_MESSAGE
                  << "IDENTIFIER already specified. Did you mean "
                  << "to make \"" << currToken.value << "\" a LITERAL?"
                  << "\nUsage: SET <KEY> <VALUE>"
                  << std::endl;
              debug.exit(DEBUG_MODE);
            }
          //
          // If LITERAL has already been defined, then break due to
          // invalid syntax.
            else if (this->ast.getSetQuery().getLitSetFlag() == 1) {
              std::cout << SET_OP_FAILURE_MESSAGE
                  << "IDENTIFIER undefined."
                  << "\nUsage: SET <KEY> <VALUE>"
                  << std::endl;
              debug.exit(DEBUG_MODE);
            }
            else {
              this->ast.getSetQuery().setIdentifier(currToken);
              break;
            }
          case OperatorType::UPDATE:
            /*
             * TODO: Define logic for UPDATE
             * probably should have the same as SET
             */
            //
            // Check to see if IDENTIFIER has already been defined.
            // If it is defined, then break due to double IDENTIFIERs.
            if (this->ast.getSetQuery().getIdSetFlag() == 1) {
              std::cout << SET_OP_FAILURE_MESSAGE
                  << "IDENTIFIER already specified. Did you mean "
                  << "to make \"" << currToken.value << "\" a LITERAL?"
                  << "\nUsage: SET <KEY> <VALUE>"
                  << std::endl;
              debug.exit(DEBUG_MODE);
            }
          //
          // If LITERAL has already been defined, then break due to
          // invalid syntax.
            else if (this->ast.getSetQuery().getLitSetFlag() == 1) {
              std::cout << SET_OP_FAILURE_MESSAGE
                  << "IDENTIFIER undefined."
                  << "\nUsage: SET <KEY> <VALUE>"
                  << std::endl;
              debug.exit(DEBUG_MODE);
            }
            else {
              this->ast.getSetQuery().setIdentifier(currToken);
              break;
            }

          case OperatorType::DELETE:
            this->ast.getDeleteQuery().setIdentifier(currToken);
            break;
          default:
            break;
        }
        break;

      case TokenType::LITERAL:
        // If no operator, then fail
        if (this->ast.getOperatorType() == OperatorType::VOID) {
          std::cout << UNEXPECTED_FAILURE_MESSAGE
              << "No operator defined, failing." << std::endl;
          debug.exit(DEBUG_MODE);
        }

        switch (this->ast.getOperatorType()) {
          case OperatorType::GET:
            std::cout << GET_OP_FAILURE_MESSAGE
                << "cannot consume literal."
                << std::endl;
            debug.exit(DEBUG_MODE);
            break;
          case OperatorType::DELETE:
            std::cout << DEL_OP_FAILURE_MESSAGE
                << "DELETE must consume a variable, literal was specified."
                << std::endl;
            debug.exit(DEBUG_MODE);
            break;
          default:
            break;
        }

      // Check for correct ordering-- if an identifier has
      // not been specified yet, then break.
        if (!this->ast.getSetQuery().getIdSetFlag()) {
          std::cout << SET_OP_FAILURE_MESSAGE
              << "Unspecified identifier, given literal instead."
              << std::endl;
          debug.exit(DEBUG_MODE);
        } else if (!this->ast.getUpdateQuery().getIdSetFlag()) {
          std::cout <<  UPDATE_OP_FAILIURE_MESSAGE
              << "Unspecified identifier, given literal instead."
              << std::endl;
          debug.exit(DEBUG_MODE);
        } else {
          this->ast.getSetQuery().setLiteral(currToken);
          break;
        }
      default:
        break;
    }
  }
}
