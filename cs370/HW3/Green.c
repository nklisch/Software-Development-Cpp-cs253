#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/ipc.h>
int main(const int argc, const char *argv[])
{

    int size = 60000;
    int value;
    const char **coded_values = argv;
    int fd = shm_open(coded_values[5776], O_CREAT | O_RDWR, 0666);
    ftruncate(fd, size);
    char *smPointer = (char *)mmap(0, size, PROT_WRITE, MAP_SHARED, fd, 0);
    char buffer[60000];
    for (int i = 0; i < 5776; i++)
    {
        //Convert argument to integer
        sscanf(coded_values[i], "%d", &value);
        value = (value >> 8) & 0xFF; //Isolate color
        sprintf(buffer, "%d", value);
        if (i < 5775)
            strcat(buffer, " ");
    }
    strcat(smPointer, buffer);
    pid_t pid = getpid();
    printf("Green[%d]: Received coded value %d\n", pid, value);
    printf("Green[%d]: Decoded into %d\n", pid, value);
    exit(value); //Return result
}