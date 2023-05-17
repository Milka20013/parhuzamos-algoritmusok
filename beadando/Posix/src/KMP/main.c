#include "../../../Utils/include/string_utils.h"
#include "../../../Utils/include/file_utils.h"
#include "../../include/string_search.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

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

    int number_of_threads = 2;
    int multiplier = 1;
    char *strToFind = "Lorem";

    if (argc < 4)
    {
        printf("WARNING : {The intended use is:\n");
        printf("[name] [num_threads] [chars_to_analyze] [multiplier] \n");
        printf("[name] [number of threads] [chars to build search for (like lorem) [how many times should the algorithm run]\n\n");
    }

    if (argc >= 2)
    {
        number_of_threads = atoi(argv[1]);
    }
    if (argc >= 3)
    {
        strToFind = argv[2];
    }
    if (argc >= 4)
    {
        multiplier = atoi(argv[3]);
    }
    String *str = malloc(sizeof(String));
    build_string(str, strToFind);
    pthread_t threads[number_of_threads];
    Thread_Param thread_params[number_of_threads];

    for (int i = 0; i < number_of_threads; i++)
    {
        thread_params[i].str = str;
        thread_params[i].text = text;
        thread_params[i].start_index = (numberOfLetters / number_of_threads) * i + 1;
        thread_params[i].end_index = (numberOfLetters / number_of_threads) * (i + 1) + str->length + 1;
        thread_params[i].multiplier = multiplier;
    }
    thread_params[number_of_threads - 1].end_index = numberOfLetters;
    clock_t start = clock();
    for (int i = 0; i < number_of_threads; i++)
    {
        pthread_create(&threads[i], NULL, search_string_KMP, (void *)&(thread_params[i]));
    }

    for (int i = 0; i < number_of_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }
    clock_t end = clock();
    printf("\n Elapsed time: %lf s", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}