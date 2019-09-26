#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(const int argc, const char *argv[])
{
    pid_t pid = getpid();
    int value = atoi(argv[1]); //Convert argument to integer
    printf("Blue[%d]: Received coded value %d\n", pid, value);
    value = value & 0xFF; //Isolate color
    printf("Blue[%d]: Decoded into %d\n", pid, value);
    exit(value); //Return result
}