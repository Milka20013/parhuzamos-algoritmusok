#include "../../Utils/include/string_utils.h"
#include "../../Utils/include/file_utils.h"
#include "../include/string_search.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

const int MULTIPLIER = 500;

void init_array(int *array, int length);
void print_array(int *array, int length);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    char *filename = "text.txt";
    int numberOfLetters;
    int error = count_chars_in_file(filename, &numberOfLetters);
    if (error == 0)
    {
        return 0;
    }

    String *text = malloc(sizeof(String));
    build_empty_string(text, numberOfLetters);
    store_file_in_string(text, filename);

    char *strToFind = "Lorem";
    int max_number_of_indices = 200;
    if (argc >= 2)
    {
        strToFind = argv[1];
    }
    if (argc >= 3)
    {
        max_number_of_indices = atoi(argv[2]);
    }
    String *str = malloc(sizeof(String));
    build_string(str, strToFind);

    int indices[max_number_of_indices];
    init_array(indices, max_number_of_indices);

    clock_t start = clock();
    for (int i = 0; i < MULTIPLIER; i++)
    {
        search_string_naiv(text, str, indices);
    }

    clock_t end = clock();
    print_array(indices, max_number_of_indices);
    printf("\n Elapsed time: %lf s", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

void init_array(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = -1;
    }
}

void print_array(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] != -1)
        {
            printf(" %d ", array[i]);
        }
    }
}