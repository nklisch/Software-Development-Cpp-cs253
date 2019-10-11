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
    int fd = shm_open(argv[5776], O_CREAT | O_RDWR, 0666);
    ftruncate(fd, size);
    char *smPointer = (char *)mmap(0, size, PROT_WRITE, MAP_SHARED, fd, 0);
    char buffer[60000];

    for (int i = 0; i < 5776; i++)
    {
        char val[20];
        //Convert argument to integer
        value = atoi(argv[i]);
        value = (value >> 16) & 0xFF; //Isolate color
        sprintf(val, "%d ", value);
        strcat(buffer, val);
    }
    
    strcat(smPointer, buffer);
    pid_t pid = getpid();
    printf("Red[%d]: Received coded value %d\n", pid, value);
    printf("Red[%d]: Decoded into %d\n", pid, value);
    shm_unlink(argv[5776]);
    return 0; //Return result
}