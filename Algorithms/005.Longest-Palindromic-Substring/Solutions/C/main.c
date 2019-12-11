#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int findIfHasTheSameCharacterInString(char *s, int index, int base) {
    int lenOfString = strlen(s);
    int i;
    //printf("        lenOfString = %d;index =%d;base = %d\n", lenOfString, index, base);
    if (base == 0) {
        i = index + 1;
    } else {
        i = base + 1;
    }
    for (; i < lenOfString; i++) {
        //printf("        ::%c;",s[index]);
        if (s[index] == s[i]) {
            return i;
        }
    }
    return 0;
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

char * longestPalindrome(char * s){

    int lenOfString = 0;
    lenOfString = strlen(s);
     int result = 0;

    char *palindromeString = malloc(sizeof(char) * (lenOfString + 1));
    memset(palindromeString, 0x00, lenOfString + 1);

    result = checkIfStringIsPalindrome(s);
    if (result == 1) {
        return s
    }

    palindromeString[0] = s[0];
    int i;


    for (i=0; i < lenOfString; i ++) {
       
        char newString[lenOfString + 1];

        //printf("i = %d\n",i);
        int nextSameCharacterIndex = 0;
    
        do {
            nextSameCharacterIndex = findIfHasTheSameCharacterInString(s, i, nextSameCharacterIndex);
            if (nextSameCharacterIndex > 0) {
                //printf("        i=%d;nextSameCharacterIndex=%d\n",i, nextSameCharacterIndex);
                get_sliced_string(s, newString, i, nextSameCharacterIndex);
                result = checkIfStringIsPalindrome(newString);
                if (result == 1) {
                    if (strlen(newString) > strlen(palindromeString)) {
                        strncpy(palindromeString, newString, strlen(newString)+1);
                    }
                } else {
                    //printf("No, it is not\n");
                }
                    
            }
        } while (nextSameCharacterIndex != 0);



        /*
        int j = 0;
        for (j=0; j > i;j++){
            int nextSameCharacterIndex = 0;
            char newString[lenOfString + 1];
            char OriginalString[lenOfString + 1];
            int result = 0;
            get_sliced_string(s, newString, i, nextSameCharacterIndex);
            nextSameCharacterIndex = findIfHasTheSameCharacterInString(s, i);
            if (nextSameCharacterIndex > 0) {
                get_sliced_string(s, newString, i, nextSameCharacterIndex);
                
            }
        }*/
    }
    printf("the longest palindrome String is %s\n",palindromeString);
    return palindromeString;
    //return s;
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
