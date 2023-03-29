#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fillArray(int array[], int length);
int GenerateRandomBetween(int a, int b);
int contains(int array[], int length, int number);
void printArray(int array[], int length);

int main()
{
    int length = 30000;
    int array[length];
    srand(time(NULL));
    clock_t start = clock();
    printf("Generating array of length %d\n", length);
    fillArray(array, length);
    clock_t end = clock();
    printf("Elapsed time :  %lf s\n", (double)(end - start) / CLOCKS_PER_SEC);
    // printArray(array, length);
    return 0;
}

void fillArray(int array[], int length)
{
    array[length - 1] = 0;
    int i = 0;
    int length2 = length * length;
    while (array[length - 1] == 0)
    {
        int number = GenerateRandomBetween(0, length2);
        if (!contains(array, length, number))
        {
            array[i] = number;
            i++;
        }
    }
}

int GenerateRandomBetween(int min, int max)
{
    if (min >= max)
    {
        return min - 1;
    }
    return rand() % (max - min + 1) + min;
}

int contains(int array[], int length, int number)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == number)
        {
            return 1;
        }
    }
    return 0;
}

void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf(" %d ", array[i]);
    }
}