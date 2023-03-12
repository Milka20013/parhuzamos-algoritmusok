#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int GenerateRandomBetween(int a, int b);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Not exactly 2 arguments were given.");
        return 0;
    }

    srand(time(NULL));
    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    int number1 = GenerateRandomBetween(min, max);
    printf("%d", number1);
    return 0;
}

int GenerateRandomBetween(int min, int max)
{
    if (min >= max)
    {
        return min - 1;
    }
    return rand() % (max - min + 1) + min;
}