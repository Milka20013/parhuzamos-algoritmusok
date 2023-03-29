#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int GenerateRandomBetween(int a, int b);
double GenerateRandomDBetween(double a, double b);

int main()
{

    srand(time(NULL));
    int min = 500, max = 1000;
    int number1 = GenerateRandomBetween(min, max);
    int number2 = GenerateRandomBetween(min, max);
    printf("What is %d + %d ? \n", number1, number2);
    int ans;
    clock_t start = clock();
    scanf("%d", &ans);
    clock_t end = clock();
    if (ans == number1 + number2)
    {
        printf("Nice, it took %lf s", (double)(end - start) / CLOCKS_PER_SEC);
    }
    else
    {
        printf("Nope, it was %d it took %lf s", number1 + number2, (double)(end - start) / CLOCKS_PER_SEC);
    }

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