#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * convert(char * s, int numRows){
    printf("The input string is: %s\n, number rows = %d\n",s, numRows);

    int i;

    int lenStr = strlen(s);
    printf("len of string is %d\n", lenStr);
    char newS[numRows-1][10];
    
    for(i=0;i<numRows;i++) {
        int j = 0;
        for(; j < 10; j++) {
           newS[i][j] = 0;
        }
    }
    int numFullColumn = lenStr % numRows;
    printf("numFullColumn = %d\n", numFullColumn);
    for (i=0;i<numRows;i++) {
        int j = 0;
        for(;j < numFullColumn+1;j++) {
            printf("i=%d, j= %d\n",i,j);
            if ((j*(2*numRows-2) + i) > lenStr) {
                break;
            }
            newS[i][j*(numRows-1)] = s[j*(2*numRows-2)+i];
            if((j+1)*numRows + numRows - i - 2 >= lenStr){
                break;
            }
            newS[i][j*(numRows-1)+(numRows-i-1)] = 
                                s[(j+1)*numRows + numRows - i - 2];
        }
    }
    for(i=0;i<numRows;i++) {
        int j = 0;
        for(; j < 10; j++) {
            if(newS[i][j] != 0) {
                printf("%c",newS[i][j]);
            }
        }
    }
    printf("\n");

    return s;

}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        return 0;
    }

    int numberRows = atoi(argv[2]);
    //printf("the result is %d, %d,%d,%d\n", 5%5, 4%5, 5/5,4/5);
    convert(argv[1], numberRows);
}