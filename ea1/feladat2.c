#include <stdio.h>

int main()
{
    for (int i = 0; i < 7; i++)
    {
        printf("%d", i);
    }
    printf("\n");
    int length = 3;
    int numbers[length];
    for (int i = 0; i < length; i++)
    {
        numbers[i] = i;
    }
    char fill = ' ';
    for (int i = 0; i < 7 - length; i++)
    {
        printf("%c", fill);
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d", numbers[i]);
    }

    return 0;
}