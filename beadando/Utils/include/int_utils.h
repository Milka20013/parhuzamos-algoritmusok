#ifndef INT_UTILS_H
#define INT_UTILS_H

#include "string_utils.h"

int hash_index(char c);
void init_int_array(String *letters, int *array);
void build_int_array(String *letters, int *array);
void rebuild_int_array(String *letters, int *array, int *source);

#endif