#include "../include/string_search.h"

void search_string_naiv(String *text, String *str, int *indices)
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