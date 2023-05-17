#include "../include/string_search.h"

#include <stdio.h>
#include <ctype.h>

void *search_string_naiv(void *param)
{
    Thread_Param *thread_param = (Thread_Param *)param;
    String *text = thread_param->text;
    String *str = thread_param->str;
    int start = thread_param->start_index;
    int end = thread_param->end_index;
    int multiplier = thread_param->multiplier;
    int tester = 0;
    for (int k = 0; k < multiplier; k++)
    {
        for (int i = start; i < end; i++)
        {
            for (int j = 0; j < str->length; j++)
            {
                if (tolower(str->content[j]) != tolower(text->content[i + j]))
                {
                    break;
                }
                else
                {
                    tester++;
                }
            }
            if (tester == str->length && k == multiplier - 1)
            {
                printf(" %d ", i);
            }
            tester = 0;
        }
    }
}

void *search_string_KMP(void *param)
{
    Thread_Param *thread_param = (Thread_Param *)param;
    String *text = thread_param->text;
    String *str = thread_param->str;
    int start = thread_param->start_index;
    int end = thread_param->end_index;
    int multiplier = thread_param->multiplier;
    int table[str->length];
    KMP_table(str, table);
    int j = 0;
    for (int k = 0; k < multiplier; k++)
    {
        for (int i = start; i < end; i++)
        {
            while (j > 0 && str->content[j + 1] != text->content[i])
            {
                j = table[j];
            }
            if (str->content[j + 1] == text->content[i])
            {
                j = j + 1;
            }
            if (j == str->length - 1 && k == multiplier - 1)
            {
                printf(" %d ", i - str->length + 1);
                j = table[j];
            }
        }
    }
}

void KMP_table(String *str, int *table)
{
    String prefixes[str->length - 1];
    String suffixes[str->length - 1];
    int m = 0;
    table[0] = 0;
    for (int i = 2; i < str->length + 1; i++)
    {
        prefix_suffix(substring(str, i), prefixes, suffixes);
        for (int j = 0; j < i - 1; j++)
        {
            if (strcmp(prefixes[j].content, suffixes[j].content) == 0)
            {
                m = prefixes[j].length;
            }
        }
        table[i - 1] = m;
        m = 0;
    }
}

void prefix_suffix(String *str, String *prefixes, String *suffixes)
{
    for (int i = 0; i < str->length - 1; i++)
    {
        build_empty_string(&(prefixes[i]), i + 1);
        build_empty_string(&(suffixes[i]), i + 1);

        for (int j = 0; j < i + 1; j++)
        {
            prefixes[i].content[j] = str->content[j];
            suffixes[i].content[j] = str->content[str->length - j - 1];
        }
        reverse_string(&(suffixes[i]));
    }
}