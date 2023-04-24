#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int GenerateRandomBetween(int a, int b);
double GenerateRandomDBetween(double a, double b);

typedef struct
{
    char* content;
    int length;
}String;

void SearchString(String text, String str, int *indices);

int main()
{
    srand(time(NULL));

    int numberOfLetters = 50000;
    String* textPtr = malloc(sizeof(String));
    textPtr->content = malloc(sizeof(char)*numberOfLetters);
    textPtr->length = numberOfLetters;

    FILE *fp = fopen("lorem.txt","r");
    if(fp == 0)
    {
        printf("Couldn't open the file");
        return 0;
    }
    char tmp;
    for (int i = 0; i < numberOfLetters; i++)
    {
        tmp = fgetc(fp);
        textPtr->content[i] = tmp;
        printf("%c",textPtr->content[i]);
        
    }
    fclose(fp);
    free(textPtr);
    char strToFind[] = "Lorem";
    
    
    


    return 0;
}

void SearchString(String text, String str, int *indices)
{
    int tester = 0;
    int indexOfIndex = 0;
    for (int i = 0; i < text.length - str.length; i++)
    {
        for (int j = 0; j < str.length; j++)
        {
            if (str.content[j] != text.content[i + j])
            {
                break;
            }
            else
            {
                tester ++;
            }
            
        }
        if (tester == str.length)
        {
            indices[indexOfIndex] = i;
            indexOfIndex ++;
        }
    }
    

}