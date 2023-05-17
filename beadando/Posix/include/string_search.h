#ifndef STRING_SEARCH_H
#define STRING_SEARCH_H

#include "../../Utils/include/string_utils.h"
#include "string.h"

typedef struct Thread_Param
{
    String *text;
    String *str;
    int start_index;
    int end_index;
    int multiplier;
} Thread_Param;

void *search_string_naiv(void *param);
void KMP_table(String *str, int *table);
void *search_string_KMP(void *param);
void prefix_suffix(String *str, String *prefixes, String *suffixes);
#endif