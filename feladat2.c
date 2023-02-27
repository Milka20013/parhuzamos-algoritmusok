#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int generateRandomInInterval(int a, int b);

int main()
{
    int n, a, b;

    scanf("%d %d %d",n,a,b);
    for (int i = 0; i < n; i++)
    {
        printf("%d",generateRandomInInterval(a,b));
    }
    
    return 0;
}

int generateRandomInInterval(int a, int b)
{
    if(a >= b){
        return -1;
    }

    srand(time);
    int num = rand();
    return num;
}