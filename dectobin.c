/*************************************/
/*Converts decimal numbers to binary */
/*Works for integers up to 2**16-1   */
/*************************************/

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

    int dec = strtol(argv[1], NULL, 10);
    char love[LEN];
    assert(love != NULL);

		if(dec > 65535){
        printf("%s\n", "Integer too large");
        exit(1);
    }
    else if(dec < 0){
        printf("%s\n", "Integer too small");
        exit(1);
    }
    getBin(dec, love);
    printBin(love);
}
