#ifndef RANDOM_GENERATOR_LIB_H
#define RANDOM_GENERATOR_LIB_H

/**
 * @brief there is some functions help to generate random things
 * such as integer, strings, trees, ... and also shuffling.
 */

// full 32-bit unsigned random number
std::mt19937 rnd_gen(time(0));

int random32(int, int);
long long random64(long long, long long);

void shuffle_rnd(int *, int, int, int);
void shuffle_rnd(long long *, int, int, int);
void shuffle_rnd(std::vector<int> &, int, int);
void shuffle_rnd(std::vector<long long> &, int, int);

std::string random_huge_number(int);

std::string random_string(int);

std::vector<std::pair<int, int>> random_tree(int, int);

#include "random_generator_lib.cpp"

#endif