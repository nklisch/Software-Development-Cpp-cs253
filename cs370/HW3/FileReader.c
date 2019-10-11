#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(const int argc, const char *argv[])
{
	const char *filename = argv[1];
	int writeEnd = atoi(argv[2]);

	char valuesBuff[60000];
	FILE *input = fopen(filename, "r");
	if (input == NULL)
	{
		fprintf(stderr, "File Failed to open");
	}

	char line[500];
	for (int i = 0; i < 76; i++)
	{
		fgets(line, 500, input);
		strcat(valuesBuff, " ");
		strcat(valuesBuff, line);
	}
	fclose(input);
	write(writeEnd, valuesBuff, 60000);
	close(writeEnd);
	return 0;
}
