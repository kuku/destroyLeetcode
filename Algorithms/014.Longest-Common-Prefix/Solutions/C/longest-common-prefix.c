#include <string.h>
#include <stdio.h>
#include <stdlib.h>




char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize <= 0) {
        return "";
    }
    if (strsSize == 1) {
        return strs[0];
    }
    int i,j=0;
    int reachEnd = 0;
    while (1) {
        for (i=0;i<strsSize;i++) {
            if (j >= strlen(strs[i])) {
                reachEnd = 1;
                break;
            }
            if(strs[0][j] == strs[i][j]) {
                //printf("strs[0][%d] = %c", j,strs[0][j]);
                continue;
            } else {
                reachEnd = 1;
                break;
            }   
        }
        if (reachEnd == 1) {
            break;
        } else {
            j++;
        }
    }
    printf("j=%d\n",j);
    if (j==0) {
        return "";
    } else {
        char *longestCommonPrefix = malloc(sizeof(char) * (j+1));
        memcpy(longestCommonPrefix,strs[0],j);
        longestCommonPrefix[j] = '\0';
        return longestCommonPrefix;
    }
}

int main(int argc, char *argv[]){
    if (argc<=1) {
        return -1;
    }
    char *strs[argc-1];
    int i;
    for(i=0;i<argc-1;i++){
        //printf("%p\n",argv[i+1]);
        strs[i] = argv[i+1];
        printf("%s\n",strs[i]);
    }
    longestCommonPrefix(strs, argc-1);
}