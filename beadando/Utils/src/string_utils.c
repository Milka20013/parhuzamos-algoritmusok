#include "../include/string_utils.h"

#include "stdlib.h"

void build_empty_string(String *str, int length)
{
    str->content = malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++)
    {
        str->content[i] = '@';
    }

    str->length = length;
}

void constrain_string(String *str)
{
    int i = 0;
    while (str->content[i] != '@' && str->content[i] != '\0')
    {
        i++;
    }
    str->content[i] = '\0';
    str->length = i;
}

void build_string(String *str, char *array)
{
    int length = 0;
    while (array[length] != '\0')
    {
        length++;
    }

    build_empty_string(str, length);
    int i = 0;
    for (i = 0; i < length; i++)
    {
        str->content[i] = array[i];
    }
    str->content[i] = '\0';
}

void copy_string(String *source, String *destination)
{
    for (int i = 0; i < source->length; i++)
    {
        destination->content[i] = source->content[i];
    }
}

int contains(String *str, char c)
{
    for (int i = 0; i < str->length; i++)
    {
        if (str->content[i] == c)
        {
            return i;
        }
    }
    return -1;
}