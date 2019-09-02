#include <stdio.h>
#include <stdlib.h>
#include "Executor.h"

int main(int argc, const char* argv[])
{
	int seed = atoi(argv[1]);
	printf("Invoker - With Seed: %d\n", seed);
	float ratio = get_running_ratio(seed);
	printf("Invoker - Running Ratio: %f\n", ratio);
	return 0;

}
