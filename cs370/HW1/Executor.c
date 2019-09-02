#include <stdlib.h>
#include <stdio.h>
int get_iteration_count(int);
int get_arr_size(int);
char get_arr_val(int);
float char_ratio(char *, int , int *);
float get_running_ratio (int);


float get_running_ratio (int seed) {
    int maxCount = 0;
    int tempMax = 0;
    int maxIteration = 0;
    srand(seed);
    int numRuns = get_iteration_count(rand());
    float cumulativeRatio = 0;
    for(int i = 0; i < numRuns; i++)
    {
        int size = get_arr_size(rand());
        char *arr = (char*)malloc(sizeof(char[size]));
        for(int i = 0; i < size; i++)
        {
            arr[i] = get_arr_val(rand());
        }
        tempMax = maxCount;
        cumulativeRatio += char_ratio(arr, size, &maxCount);
        
        if(maxCount != tempMax)
        {
            maxIteration = i;
        }
        free(arr);
    }

    printf("Executor - Max Interation: %d \n", maxIteration);
    printf("Executor - Max Vowel Count: %d\n", maxCount);
    return cumulativeRatio / numRuns;
}

int get_iteration_count(int rand)
{
    return (rand % 100 + 50) * 1;
}

int get_arr_size(int rand)
{
    return (rand % 100 + 100) * 1;
}

char get_arr_val(int rand)
{
    return (char)(rand % 26 + 97) * 1;
}

float char_ratio(char *arr, int size, int *maxCountPointer)
{
    int vowels = 0;
    int constant = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'u')
        {
            vowels++;
        }
        else
        {
            constant++;
        }
                    
    }
    if(constant > *maxCountPointer)
        *maxCountPointer = constant;
    return ((float)vowels)/constant;
}