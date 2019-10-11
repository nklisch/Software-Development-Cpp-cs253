#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(const int argc, const char *argv[])
{
    int size = 60000;
    int value;
    const char *coded_values[] = argv;
    int fd = shm_open(coded_values[5776], O_CREAT | O_RDWR, 0666);
    ftruncate(fd, size);
    const char *smPointer = (int *)mmap(0, size, PROT_WRITE, MAP_SHARED, fd, 0);
    const char *buffer[60000];
    for (int i = 0; i < 5776; i++)
    {
        //Convert argument to integer
        sscanf(coded_values[i], "%d", &value);
        value = (value >> 16) & 0xFF; //Isolate color
        sprintf(buffer, "%d", value);
        if (i < 5775)
            strcat(buffer, " ");
    }
    strcat(smPointer, buffer);
    pid_t pid = getpid();
    printf("Blue[%d]: Received coded value %d\n", pid, value);
    value = value & 0xFF; //Isolate color
    printf("Blue[%d]: Decoded into %d\n", pid, value);
    exit(value); //Return result
}