#ifndef ANAGRAMMA_H
#define ANAGRAMMA_H

#include "../../Utils/include/string_utils.h"

void anagramma_algorithm_contains(String *words, char *chars_to_analyze, int lines, int num_threads, int multiplier, int write);

void anagramma_algorithm_int(String *words, char *chars_to_analyze, int lines, int num_threads, int multiplier, int write);

#endif