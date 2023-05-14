#include "../include/int_utils.h"

int hash_index(char c)
{
    return c + 127;
}

void build_int_array(String *letters, int *array)
{
    int index;
    for (int i = 0; i < letters->length; i++)
    {
        index = hash_index(letters->content[i]);
        if (array[index] <= 0)
        {
            array[index] = 1;
        }
        else
        {
            array[index]++;
        }
    }
}

void rebuild_int_array(String *letters, int *array, int *source)
{
    int index;
    for (int i = 0; i < letters->length; i++)
    {
        index = hash_index(letters->content[i]);
        array[index] = source[index];
    }
}

void init_int_array(String *letters, int *array)
{
    for (int i = 0; i < 256; i++)
    {
        array[i] = -1;
    }

    for (int i = 0; i < letters->length; i++)
    {
        array[hash_index(letters->content[i])] = 0;
    }
}