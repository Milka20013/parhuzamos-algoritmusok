#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

const int N_THREADS = 2;

int GenerateRandomBetween(int a, int b);
double GenerateRandomDBetween(double a, double b);

void *RandomSort(void *param);
void RandomSortS(int *array, int length);
int Sorted(int *array, int length);
void RandomIndexArray(int *array, int length);
int Unique(int *array, int length);

typedef struct
{
    int length;
    int array[];
} ThreadParam;

int main()
{
    srand(time(NULL));
    /*pthread_t threads[N_THREADS];
    int length = 10;
    ThreadParam *threadParamPtr = malloc(sizeof(ThreadParam) + length * sizeof(int));
    for (int i = 0; i < length; i++)
    {
       threadParamPtr->array[i] = GenerateRandomBetween(0,length);
    }
    threadParamPtr->length = length;
    for (int i = 0; i < N_THREADS; ++i)
    {
        pthread_create(&threads[i], NULL, RandomSort, threadParamPtr);
    }
    while (!Sorted(threadParamPtr->array, length))
    {
        for (int i = 0; i < length; i++)
        {
            printf(" %d ",threadParamPtr->array[i]);
        }
    }*/
    int length = 5;
    int arr[length];
    for (int i = 0; i < length; i++)
    {
        arr[i] = GenerateRandomBetween(0,100);
    }
    
    RandomSortS(arr, length);
    for (int i = 0; i < length; i++)
    {
        printf(" %d ", arr[i]);
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

double GenerateRandomDBetween(double min, double max)
{
    if (min >= max)
    {
        return min - 1;
    }
    double range = RAND_MAX / (max - min);
    return rand() / range + min;
}

void RandomSortS(int *array, int length)
{
    int arr[length];
    int indexArr[length];
    for (int i = 0; i < length; i++)
    {
        arr[i] = array[i];
        indexArr[i] = i;
    }
    
    while (Sorted(arr, length) == 0)
    {
        RandomIndexArray(indexArr, length);
        for (int i = 0; i < length; i++)
        {
            arr[indexArr[i]] = array[indexArr[i]];
        }
    }
    for (int i = 0; i < length; i++)
    {
        array[i] = arr[i];
    }
}

void *RandomSort(void *param)
{
    ThreadParam *threadParam = (ThreadParam *)param;
    int length = threadParam->length;
    int arr[length];
    int indexArr[length];
    while (Sorted(arr, length) == 0)
    {
        RandomIndexArray(indexArr, length);
        for (int i = 0; i < length; i++)
        {
            arr[indexArr[i]] = threadParam->array[indexArr[i]];
        }
    }
    for (int i = 0; i < length; i++)
    {
        threadParam->array[i] = arr[i];
    }
}

int Sorted(int *array, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void RandomIndexArray(int *array, int length)
{
    while (Unique(array, length) == 0)
    {
        for (int i = 0; i < length; i++)
        {
            array[i] = GenerateRandomBetween(0, length - 1);
        }
    }
}

int Unique(int *array, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (array[i] == array[j])
            {
                return 0;
            }
        }
    }

    return 1;
}
