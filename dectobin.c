/*************************************/
/*Converts decimal numbers to binary */
/*Works for integers up to 2**64-1   */
/*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#define LEN 64 

void getBin(long long num)
{
	long long MASK = 0x8000000000000000;
	int idx;
	long long bit;
	for(idx = 0; idx < LEN; idx++){
		long long bit = num & MASK;	
		printf("%lld", bit/MASK);
		num <<= 1;
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

    const long long MAX = LLONG_MAX;
    const long long dec = strtoll(argv[1], NULL, 10);

    if(dec > MAX){
        printf("%s\n", "Integer is out of range");
        exit(1);
    }

    getBin(dec);
}
