#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int GenerateRandomBetween(int a, int b);
double GenerateRandomDBetween(double a, double b);

int main()
{
    srand(time(NULL));
    int number1 = GenerateRandomBetween(500, 1000);
    double number2 = GenerateRandomDBetween(500, 1000);
    printf("%d , %lf", number1, number2);
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

double GenerateRandomDBetween(double min, double max)
{
    if (min >= max)
    {
        return min - 1;
    }
    double range = RAND_MAX / (max - min);
    return rand() / range + min;
}