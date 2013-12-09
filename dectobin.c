/*Converts decimal numbers to binary*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define LEN 16

void getBin(int num, char *str)
{
    *(str+LEN-1) = '\0';
    int mask = 0x8000 << 1;
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

    double dec = strtod(argv[1], NULL);
    char* love = malloc(LEN);
    assert(love != NULL);
    getBin(dec, love);
    printBin(love);
    free(love);
}
