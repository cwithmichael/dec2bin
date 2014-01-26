/*************************************/
/*Converts decimal numbers to binary */
/*Works for integers up to 2**64-1   */
/*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <errno.h>
#define LEN 64 

void getBin(unsigned long long int num)
{
	unsigned long long int MASK = 0x8000000000000000;
	int idx;
	unsigned long long int bit;
	for(idx = 0; idx < LEN; idx++){
		unsigned long long int bit = num & MASK;	
		printf("%llu", bit/MASK);
		num <<= 1;

		/*Break up the output into nibbles*/
		if( ( (idx+1) % 4) == 0) printf("%s", " ");
	}
	printf("\n");
}

void printUsage(char* progName)
{
    printf("%s [decimal]\n", progName);
}

int main(int argc, char **argv)
{
    if(argc != 2){
        printUsage(argv[0]);
        exit(1);
    }

    const unsigned long long int MAX = ULLONG_MAX;
    const unsigned long long int dec = strtoull(argv[1], NULL, 10);

    if(errno == ERANGE){
        printf("%s\n", "Integer is out of range");
		printf("The largest integer allowed on this system is : %llu\n", MAX);
        exit(1);
    }

	printf("Input: %llu\n", dec);
	printf("%s\n", "Output: ");
	getBin(dec);
}
