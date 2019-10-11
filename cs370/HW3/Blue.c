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
    pid_t pid = getpid();
    //Open shared memory
    int fd = shm_open(coded_values[5776], O_CREAT | O_RDWR, 0666);
    ftruncate(fd, size);
    char *smPointer = (char *)mmap(0, size, PROT_WRITE, MAP_SHARED, fd, 0);
    char buffer[60000];
    //Parse arguments convert number and put into buffer
    for (int i = 0; i < 5776; i++)
    {
        char val[20];
        value = atoi(argv[i]);
        value = (value) & 0xFF; //Isolate color
        sprintf(val, "%d ", value);
        strcat(buffer, val);
        printf("Blue[%d]: Received coded value %d\n", pid, value);
        printf("Blue[%d]: Decoded into %d\n", pid, value);
    }
    //Place buffer into shared memory
    strcat(smPointer, buffer);
    shm_unlink(argv[5776]);
    return 0;
}
