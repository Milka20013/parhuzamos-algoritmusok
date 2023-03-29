#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

const int N_THREADS = 10;
int sums[10];
const int arrayLength = 10000;

int sumCheck(int array[], int start, int end);
void printArray(int array[], int length);
void fillArray(int array[], int length);
int GenerateRandomBetween(int min, int max);

typedef struct
{
    int i;
    int array[];
} ThreadParam;

void *work(void *param)
{

    ThreadParam *threadParam = (ThreadParam *)param;
    int i = threadParam->i;
    int start = arrayLength / N_THREADS;
    sums[i] = sumCheck(threadParam->array, start * i, start * (i + 1));
    printf("Ready\n");
}

int main(int argc, char *argv[])
{
    printf("This version is not working, because of the i field of the struct");
    pthread_t threads[N_THREADS];
    int i;
    ThreadParam *threadParamPtr = malloc(sizeof(ThreadParam) + arrayLength * sizeof(int));
    clock_t start = clock();

    fillArray(threadParamPtr->array, arrayLength);

    for (i = 0; i < N_THREADS; ++i)
    {
        threadParamPtr->i = i;
        pthread_create(&threads[i], NULL, work, threadParamPtr);
    }
    for (i = 0; i < N_THREADS; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    clock_t end = clock();

    printArray(sums, N_THREADS);
    printf("Total sum : %d", sumCheck(sums, 0, N_THREADS));
    printf("\nReady Main\n");

    printf("Elapsed time: %lf s ", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

int sumCheck(int array[], int start, int end)
{
    int sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += array[i];
    }
    return sum;
}

void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf(" %d ", array[i]);
    }
}

void fillArray(int array[], int length)
{
    array[length - 1] = 0;
    int i = 0;
    for (int i = 0; i < length; i++)
    {
        array[i] = GenerateRandomBetween(0, 100);
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
