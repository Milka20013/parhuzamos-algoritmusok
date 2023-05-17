#include "../../Utils/include/int_utils.h"
#include "../include/anagramma.h"

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void anagramma_algorithm_contains(String *words, char *chars_to_analyze, int lines, int num_threads, int multiplier, int write)
{
#pragma omp parallel num_threads(num_threads)
    {
        String *letters = malloc(sizeof(String));
        build_string(letters, chars_to_analyze);
        String *temp = malloc(sizeof(String));
        build_empty_string(temp, letters->length);
        int tester = 0;
        int index = -1;

#pragma omp for
        for (int j = 0; j < multiplier; j++)
        {
            for (int i = 0; i < lines; i++)
            {
                copy_string(letters, temp);
                if (words[i].length > temp->length)
                {
                    continue;
                }
                for (int j = 0; j < words[i].length; j++)
                {
                    index = contains(temp, words[i].content[j]);
                    if (index >= 0)
                    {
                        temp->content[index] = '@';
                        tester++;
                    }
                }
                if (tester == words[i].length && write && j == multiplier - 1)
                {
                    printf("word: %s can be constructed from %s\n", words[i].content, letters->content);
                }
                tester = 0;
            }
        }
    }
}

void anagramma_algorithm_int(String *words, char *chars_to_analyze, int lines, int num_threads, int multiplier, int write)
{
    String *distinct_chars = malloc(sizeof(String));
    build_empty_string(distinct_chars, strlen(chars_to_analyze));
    int k = 0;
    for (int i = 0; i < distinct_chars->length; i++)
    {
        if (contains(distinct_chars, chars_to_analyze[i]) == -1)
        {
            distinct_chars->content[k] = chars_to_analyze[i];
            k++;
        }
    }
    constrain_string(distinct_chars);
#pragma omp parallel num_threads(num_threads)
    {
        String *letters = malloc(sizeof(String));
        build_string(letters, chars_to_analyze);
        constrain_string(letters);
        int source[256];
        init_int_array(letters, source);
        build_int_array(letters, source);
        int temp[256];
        init_int_array(letters, temp);
        rebuild_int_array(distinct_chars, temp, source);

        int tester = 1;
        int index = -1;
#pragma omp for
        for (int j = 0; j < multiplier; j++)
        {
            for (int i = 0; i < lines; i++)
            {
                rebuild_int_array(distinct_chars, temp, source);
                if (words[i].length > letters->length)
                {
                    continue;
                }
                for (int j = 0; j < words[i].length; j++)
                {
                    index = hash_index(words[i].content[j]);
                    if (temp[index] > -1)
                    {
                        temp[index]--;
                        if (temp[index] < 0)
                        {
                            tester = 0;
                            break;
                        }
                    }
                    else
                    {
                        tester = 0;
                    }
                }
                if (tester == 1 && write && j == multiplier - 1)
                {
                    printf("word: %s can be constructed from %s\n", words[i].content, letters->content);
                }
                tester = 1;
            }
        }
    }
}