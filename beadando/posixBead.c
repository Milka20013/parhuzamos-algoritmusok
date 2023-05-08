#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

void init_array(int *array, int length);
void print_array(int *array, int length);

typedef struct
{
    char *content;
    int length;
} String;

void build_string(String *str, char *array);
void build_empty_string(String *str, int length);
void search_string(String *text, String *str, int *indices);

int main()
{
    srand(time(NULL));

    int numberOfLetters = 50000;
    String *textPtr = malloc(sizeof(String));
    build_empty_string(textPtr, numberOfLetters);

    FILE *fp = fopen("lorem.txt", "r");
    if (fp == 0)
    {
        printf("Couldn't open the file");
        return 0;
    }
    char tmp;
    for (int i = 0; i < numberOfLetters; i++)
    {
        tmp = fgetc(fp);
        textPtr->content[i] = tmp;
    }

    fclose(fp);
    char strToFind[] = "Lorem";
    String *str = malloc(sizeof(String));
    build_string(str, strToFind);
    int length = 200;
    int indices[length];
    init_array(indices, length);
    search_string(textPtr, str, indices);
    print_array(indices, length);

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

void search_string(String *text, String *str, int *indices)
{
    int tester = 0;
    int indexOfIndex = 0;
    for (int i = 0; i < text->length - str->length; i++)
    {
        for (int j = 0; j < str->length; j++)
        {
            if (str->content[j] != text->content[i + j])
            {
                break;
            }
            else
            {
                tester++;
            }
        }
        if (tester == str->length)
        {
            indices[indexOfIndex] = i;
            indexOfIndex++;
        }
        tester = 0;
    }
}

void build_empty_string(String *str, int length)
{
    str->content = malloc(sizeof(char) * length);
    str->length = length;
}

void build_string(String *str, char *array)
{
    int length = 0;
    while (array[length] != '\0')
    {
        length++;
    }

    build_empty_string(str, length);

    for (int i = 0; i < length; i++)
    {
        str->content[i] = array[i];
    }
}
