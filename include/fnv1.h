/*
 * Implementation of FNV-1 (Fowler/Noll/Vo) Hashing Algorithm
 * by Glenn Fowler, Kiem-Phong Vo, and Landon Curt Noll.
 *
 * Created by Randy Truong on 8/14/24.
 */

#ifndef FNV1_H
#define FNV1_H
#include <cstdint>
#include <iostream>
#include <map>
#include <string>

#define FNV_OFFSET

const std::map<int, uint64_t>FNV_OFFSET_BASES = {
 {32, 0x811c9dc5},
  {64, 0xcbf29ce484222325}
};

const std::map<int, uint64_t>FNV_PRIMES  = {
 {32, 0x01000193},
  {64, 0x00000100000001B3}
};

/**
 *
 * @param input (The string input to be hashed into an integer)
 * @param size (The desired integer size for the FNV Prime)
 * @return
 */
uint64_t hash(std::string input, int size);

/**
 *
 * @param input (The integer array input to be hashed into an integer)
 * @param size (The desired integer size for the FNV Prime)
 * @return
 */
uint64_t hash(std::vector<int> input, int size);

uint64_t hash(int input, int size);



#endif //FNV1_H
