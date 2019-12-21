#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int checkIfStringIsPalindrome(char *s) {
    int lenOfString = strlen(s);
    for(int i = 0; i <= lenOfString/2 ; i ++) {
        if (s[i] == s[lenOfString - i - 1]) {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}

int expandAroundCenter(char *s, int left, int right) {
    int L = left, R = right;
    while (L > 0 && R < strlen(s) && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L + 1;
}

void get_sliced_string(char *origin, char *output, int start, int end) {
    int i = 0;
    int j = 0;
    for (i = start; i <= end ; i++) {
        output[j] = origin[i];
        j++;
    }
    output[j] = '\0';
}

char * longestPalindrome(char * s){

    int lenOfString = 0;
    lenOfString = strlen(s);
    int result = 0;

    char *palindromeString = malloc(sizeof(char) * (lenOfString + 1));
    memset(palindromeString, 0x00, lenOfString + 1);

    result = checkIfStringIsPalindrome(s);
    if (result == 1) {
        return s;
    }

    palindromeString[0] = s[0];
    int i;
    int start = 0, end = 0;
    for (i=0;i<lenOfString;i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i+1);
        int len = 0;
        if (len1 > len2) {
            len = len1;
        } else {
            len = len2;
        }
        start = i - (len - 1)/2;
        end = i + len /2;
    }

    char newString[lenOfString];
    get_sliced_string(s,newString, start , end);

    printf("the longest string is %s\n",newString); 
    return newString;
}

int main(int argc, char *arg[]) {
    //char *inputString = "babad\n";
    //longestPalindrome(inputString);
    if (argc < 2) {
        printf("The argument number must great than 1\n");
        return -1;
    }
    longestPalindrome(arg[1]);
    
    return 0;
}