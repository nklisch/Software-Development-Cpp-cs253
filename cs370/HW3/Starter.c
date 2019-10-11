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

pid_t decodeValue(char *[], char[], char *smPointer);
void readValues(char *, int[]);
const int IMAGE_HEIGHT = 76;
const int IMAGE_WIDTH = 76;
const int SIZE = 5776;
const int BUFFER_SIZE = 60000;
int main(const int argc, const char *argv[])
{

    char filename[] = "coded_image_1.txt";

    if (argc >= 2)
        strcat(filename, argv[1]);

    int myPipe[2];
    if (pipe(myPipe) < 0)
    {
        //fprintf(stderr, "Pipe Failed");
        return 1;
    }
    char fileDescriptor[200];
    sprintf(fileDescriptor, "%d", myPipe[1]);

    int my_pid = fork();
    char fileData[BUFFER_SIZE];

    if (my_pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 2;
    }
    else if (my_pid == 0)
    {
        execlp("FileReader", "FileReader.c", filename, fileDescriptor, NULL);
    }
    else
    {
        wait(NULL);
        close(myPipe[1]);
        read(myPipe[0], fileData, sizeof(fileData));
        close(myPipe[0]);
    }
    char *coded_values[5778];

    char s[2] = " ";
    coded_values[5777] = strtok(NULL, s);
    for (int i = 0; i < 5776; i++)
    {
        coded_values[i] = strtok(fileData, s);
    }
    pid_t pids[3];
    char *shmPs[3];
    char *colors[3] = {"Red",
                       "Green",
                       "Blue"};

    for (int i = 0; i < SIZE; i++)
    {
        pids[i] = decodeValue(coded_values, colors[i], shmPs[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        int status;
        waitpid(pids[i], &status, WCONTINUED);
    }
    int red[SIZE];
    int green[SIZE];
    int blue[SIZE];

    readValues(shmPs[0], red);
    readValues(shmPs[1], green);
    readValues(shmPs[2], blue);
    shm_unlink("Shared_mem_red");
    shm_unlink("Shared_mem_green");
    shm_unlink("Shared_mem_blue");
    //Determine output file name
    char outputFileName[30] = "";
    char extension[12] = "_output.pmm";
    strcpy(outputFileName, filename);
    char *pos = strchr(outputFileName, '.');
    *pos = '\0';
    strcat(outputFileName, extension);

    //Output the values into the .pmm file
    FILE *fout = fopen(outputFileName, "wb");
    fprintf(fout, "P6\n%i %i 255\n", IMAGE_HEIGHT, IMAGE_WIDTH);
    for (int i = 0; i < SIZE; i++)
    {
        fputc(red[i], fout);
        fputc(green[i], fout);
        fputc(blue[i], fout);
    }
    fclose(fout);
    printf("Starter: %s file written and closed.\n", outputFileName);
}

pid_t decodeValue(char *coded_values[], char color[], char *smPointer)
{
    char sharedMemory[] = "Shared_mem_";
    strcat(sharedMemory, color);
    char file[] = "./";
    strcat(file, color);
    coded_values[5776] = sharedMemory;
    int fd = shm_open(sharedMemory, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, BUFFER_SIZE);
    smPointer = (char *)mmap(0, BUFFER_SIZE, PROT_READ, MAP_SHARED, fd, 0);

    pid_t pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        exit(1);
    }
    else if (pid == 0)
    {
        execvp(file, coded_values);
    }

    //printf("Starter: Forked proccess with ID %d\n", pid);
    //printf("Starter: Waiting for proccess [%d]\n", pid);

    //printf("Starter: Child proccess %d returned %d\n", pid, status);
    return pid;
}

void readValues(char *shm_values, int output[])
{
    for (int i = 0; i < 5776; i++)
    {
        sscanf(shm_values, "%d", &output[i]);
    }
    return;
}