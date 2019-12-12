#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int getCurrentPalindromeLength(char *s, int left, int right) {
    int L = left;
    int R = right;
    int lenOfString = strlen(s);

    while ((L>=0) && (R < lenOfString) && (s[L] == s[R])) {
        L--;
        R++;
    }
    return R-L-1;
}

void getSlicedString(char *origin, char *output, int start, int end) {
    int i = 0;
    int j = 0;
    for (i = start; i <= end ; i++) {
        output[j] = origin[i];
        j++;
    }
    output[j] = '\0';
}

char * longestPalindrome(char *s) {
    int lenOfString = strlen(s);
    if (lenOfString == 0 || lenOfString == 1) {
        return s;
    }

    int start = 0, end = 0;
    int i;
    for (i=0;i<lenOfString;i++){
        int len1 = getCurrentPalindromeLength(s, i,i); 
        int len2 = getCurrentPalindromeLength(s, i, i+1);
        int len;
        if (len1 > len2) {
            len = len1;
        } else {
            len = len2;
        }
        //printf("len: %d; start= %d;end=%d\n",len, start, end);
        if (len > (end - start)) {
            start = i - (len-1) / 2;
            end = i + len / 2;
        }
    }
    //printf("start: %d, end:%d\n",start, end);
    //char longestPalindrome[];
    char *longestPalindrome = malloc(sizeof(char) * (end-start+2));
    //memset(longestPalindrome, 0x00, end-start+2);
    getSlicedString(s,longestPalindrome,start,end); 
    //printf("%s\n",longestPalindrome);
    return longestPalindrome;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return -1;
    }

    longestPalindrome(argv[1]);
    return 0;
}