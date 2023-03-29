#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

const int N_THREADS = 600;

void *work(void *_)
{
    sleep(2);
    printf("Ready\n");
}

int main(int argc, char *argv[])
{
    pthread_t threads[N_THREADS];
    int i;
    clock_t start = clock();
    for (i = 0; i < N_THREADS; ++i)
    {
        pthread_create(&threads[i], NULL, work, NULL);
    }

    for (i = 0; i < N_THREADS; ++i)
    {
        pthread_join(threads[i], NULL);
    }
    clock_t end = clock();
    printf("Ready Main\n");
    printf("Elapsed time: %lf s ", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
