
//Determines number of interations to run
//Pre-Condition: Integer, should be randomly produced
//Post-Condition: A Integer between [50-150) based on the input
int get_iteration_count(int rand);
//Determines the size of an array
//Pre-Condition: Integer, should be randomly produced
//Post-Condition: A Integer between [100-200) based on the input
int get_arr_size(int rand);
//Determines a value to put in the array
//Pre-Condition: Integer, should be randomly produced
//Post-Condition: A Integer between [97-123) based on the input
char get_arr_val(int rand);
//Calculates the ratio of vowels to constants in the given array
//Pre-Condition: A pointer to an array of chars, the array size, and a pointer to store if the current array had the most vowels
//Post-Conditon: returns the ratio of vowels/constanants as a float, and sets maxCounterPointer if it was the current max
float char_ratio(char *arr, int size, int *maxCountPointer);
//Calculates the average ratio of vowels/constanants across all arrays
//Pre-Condition: A seed to use for the random generation of values
//Post-Condition: The average ratio of vowels/constants across all created arrays
float get_running_ratio(int seed);