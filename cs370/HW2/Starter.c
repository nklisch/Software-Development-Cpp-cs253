#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int decodeValue(int, const char *, const char *);
int main(const int argc, const char *argv[])
{
    const int SIZE = 5776;
    const char * filename = "coded_image_1.txt";
    
    if(argc >= 2)
        filename = argv[1];

    //Get the values from the input file
    int values[SIZE];
    FILE * input = fopen(filename,"r");
    for(int i = 0; i < SIZE; i++){
        fscanf(input, "%d", &values[i]);
    }
    fclose(input);

    //Decode each color for each value, if the value is not negative then save it;
    int red[SIZE];
    int green[SIZE];
    int blue[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        red[i] = decodeValue(values[i], "./Red", "Red.c");
        green[i] = decodeValue(values[i], "./Green", "Green.c");
        blue[i] = decodeValue(values[i], "./Blue", "Blue.c");
    }


}

//Takes in the value to decode and the name of the file to execute, called color
//Returns the decoded value or a negative -1 if it is the child process
int decodeValue(int value, const char * color, const char * file)
{
    pid_t pid = fork();
    int status;
    char str[30];
    sprintf(str, "%d", value);
    if(pid == 0){
        execlp(color,file, str, (char *)NULL);
    }else{
        printf("Starter: Forked proccess with ID %d\n", pid);
        printf("Starter: Waiting for proccess [%d]\n", pid);
        wait(&status);
        status = WEXITSTATUS(status);
        printf("Starter: Child proccess %d returned %d\n", pid,status);
    }
return status;
}