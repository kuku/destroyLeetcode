#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * convert(char * s, int numRows){

    int i;

    int lenStr = strlen(s);
    

    if(numRows <= 1) {
        return s;
    }
    int numFullColumn = lenStr / (numRows + numRows - 2);

    //printf("originStr = %s, len=%d\n",s, lenStr);
    char *newStr = malloc(sizeof(char)*(lenStr+1));
    int newSeq = 0;
    for (i=0;i < numRows;i++) {
        int j=0;
        for(;j<=numFullColumn;j++) {
            if (j*(numRows+numRows - 2) + i < lenStr) {
                newStr[newSeq] = s[j*(numRows+numRows - 2) + i];
                newSeq ++;
            }
            
            if (i == 0 || i == numRows - 1) {
                continue;
            } else {
                if (((j+1) * (2*numRows - 2) - i) < lenStr) {
                    newStr[newSeq] = s[(j+1) * (2*numRows - 2) - i];
                    newSeq ++;
                }
            }
        }
        newStr[newSeq] = '\0';     
        //printf("newStr = %s\n",newStr);

    }
    //printf("newSeq=%d\n",newSeq);
    newStr[newSeq] = '\0';
    //printf("newStr = %s\n",newStr);

    return newStr;

}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        return 0;
    }

    int numberRows = atoi(argv[2]);
    //printf("the result is %d, %d,%d,%d\n", 5%5, 4%5, 5/5,4/5);
    convert(argv[1], numberRows);
}