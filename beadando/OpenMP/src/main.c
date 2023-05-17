#include "../../Utils/include/file_utils.h"
#include "../../Utils/include/string_utils.h"
#include "../include/anagramma.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // determine the length of the file, and the max number of chars in a word
    int max_word_length;
    int lines;
    int error = count_lengths_in_file("dict.txt", &lines, &max_word_length);
    if (error == 0)
    {
        return 0;
    }
    // build Strings according to the lines and word lengths
    String words[lines];
    for (int i = 0; i < lines; i++)
    {
        build_empty_string(&(words[i]), max_word_length);
    }

    error = store_file_in_string_array(words, "dict.txt");
    if (error == 0)
    {
        return 0;
    }

    char *chars_to_analyze = "ALMA";

    int num_threads = 1;
    int multiplier = 1;
    int write = 0;
    if (argc < 4)
    {
        printf("WARNING : {The intended use is:\n");
        printf("[name] [num_threads] [chars_to_analyze] [multiplier] [write*]\n");
        printf("[name] [number of threads] [chars to build anagramma from (like AMLA) [how many times should the algorithm run] [write output or not]\n");
        printf("* the last parameter is optional. If it has any value, then the result is omitted.}\n\n");
    }

    if (argc >= 2)
    {
        num_threads = atoi(argv[1]);
    }
    if (argc >= 3)
    {
        chars_to_analyze = argv[2];
    }
    if (argc >= 4)
    {
        multiplier = atoi(argv[3]);
    }
    if (argc >= 5)
    {
        write = 1;
    }
    printf("Algorithm with contains starts\nthreads: %d\nchars: %s\nmultiplier: %d\nwrite output: %s\n", num_threads, chars_to_analyze, multiplier, write == 1 ? "true" : "false");
    clock_t start = clock();
    anagramma_algorithm_contains(words, chars_to_analyze, lines, num_threads, multiplier, write);
    clock_t end = clock();
    printf("Elapsed time: %lf s\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("\nAlgorithm with int array starts\nthreads: %d\nchars: %s\nmultiplier: %d\nwrite output: %s\n", num_threads, chars_to_analyze, multiplier, write == 1 ? "true" : "false");
    start = clock();
    anagramma_algorithm_int(words, chars_to_analyze, lines, num_threads, multiplier, write);
    end = clock();
    printf("Elapsed time: %lf s", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
