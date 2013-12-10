/*************************************/
/*Converts decimal numbers to binary */
/*Works for integers up to 2**32-1   */
/*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#define LEN 32 

void getBin(int num, char *str)
{
    *(str+LEN-1) = '\0';
    long int mask = pow(2, LEN);
    while(mask >>= 1)
        *str++ = !!(mask & num) + '0';
}

void printBin(char *str)
{
    int i = 0;
    for(i=0; i<LEN; i++){
        if(str[i] != '1')
            str[i] = '0';
    }

    for(i=0; i<LEN; i++){
        if( i > 0 && (i % 8) == 0)
            printf(" ");
        printf("%c", str[i]);
    }

    printf("\n");
} 

void printUsage(char* progName)
{
    printf("%s [decimal]\n", progName);
}

int main(int argc, char **argv)
{
    if(argc < 2 || argc > 2){
        printUsage(argv[0]);
        exit(1);
    }

    const unsigned long int MAX = pow(2, LEN) - 1;
    unsigned long int dec = strtol(argv[1], NULL, 10);
    char love[LEN];
    assert(love != NULL);

    if(dec > MAX){
        printf("%s\n", "Integer too large");
        exit(1);
    }
    getBin(dec, love);
    printBin(love);
}
