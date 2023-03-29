#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int PrimeCheck(int number);

int main()
{
    int n;
    printf("Prime counter to n = ");
    scanf("%d", &n);
    int counter = 0;
    clock_t start = clock();
    for (int j = 0; j < n; j++)
    {
        counter += PrimeCheck(j);
    }
    clock_t end = clock();
    printf("\nPrime numbers in range : %d", counter);
    printf("\n %lf s", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

int PrimeCheck(int number)
{
    if (number == 0 || number == 1)
    {
        return 0;
    }

    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}