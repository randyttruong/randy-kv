//
// Created by Randy Truong on 8/2/24.
//

#ifndef DEBUG_H
#define DEBUG_H

inline extern bool DEBUG_MODE = false;

class debug {
public:
  debug();
  void static exit(int DEBUG_MODE);
};


#endif //DEBUG_H
