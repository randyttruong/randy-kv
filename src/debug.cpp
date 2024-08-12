//
// Created by Randy Truong on 8/2/24.
//

#include "debug.h"


debug::debug() {}

void debug::exit(int DEBUG_MODE) {
  if (DEBUG_MODE != 0) exit(1);
}
