#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int generateRandomInInterval(int a, int b);

int main()
{
    int n,m, a, b, number;
    printf("Elemszam :");
    scanf("%d",&n);

    printf("Elemszam szorzo :");
    scanf("%d",&m);
    short numbers[n];
    clock_t begin = clock();
    srand(time(NULL));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            numbers[j] = generateRandomInInterval(1,100);
        }
    }
    
    FILE *fp;
    fp = fopen("asd.txt","w");
    clock_t middle = clock();
    for (int j = 0; j < m;j++)
    {
        for(int i = 0; i < n; i++)
        {
            fprintf(fp,"%d \n",numbers[i]);
        }
    }
    
   
    fclose(fp);
    clock_t end = clock();
    printf("Time to generate numbers: %lf \n",(double)(middle-begin)/CLOCKS_PER_SEC);
    printf("Time to write numbers: %lf \n",(double)(end-middle)/CLOCKS_PER_SEC);
    
    return 0;
}

int generateRandomInInterval(int a, int b)
{
    if(a >= b){
        return -1;
    }

    
    int num = rand() % (b-a + 1) + a;
    return num;
}