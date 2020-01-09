#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct digitMapLetters{
    char digit;
    char letters[5];
};

struct digitMapLetters phone[8];

int initPhoneHash() {
    phone[0].digit = '2';
    memset(phone[0].letters, '\0', 5);
    strcpy(phone[0].letters,"abc");
    phone[0].digit = '3';
    memset(phone[1].letters, '\0', 5);
    strcpy(phone[1].letters,"def");
    phone[0].digit = '4';
    memset(phone[2].letters, '\0', 5);
    strcpy(phone[2].letters,"ghi");
    phone[0].digit = '5';
    memset(phone[3].letters, '\0', 5);
    strcpy(phone[3].letters,"jkl");
    phone[0].digit = '6';
    memset(phone[4].letters, '\0', 5);
    strcpy(phone[4].letters,"mno");
    phone[0].digit = '7';
    memset(phone[5].letters, '\0', 5);
    strcpy(phone[5].letters,"pqrs");
    phone[0].digit = '8';
    memset(phone[6].letters, '\0', 5);
    strcpy(phone[6].letters,"tuv");
    phone[0].digit = '9';
    memset(phone[7].letters, '\0', 5);
    strcpy(phone[7].letters,"wxyz");  
    return 0;
}

char getMapLetter(char digit, int mapIndex) {
    if (digit == '\0') {
        return '\0';
    } else {
        return phone[digit-'0'-2].letters[mapIndex];
    }
}

int getMapLetterStringLen(char digit) {
    return strlen(phone[digit-'0'-2].letters);
}
int total = 0;
int preAllocLen = 32;
char **returnString;
int backtrack (char *digit, char *combination, int index) {
    if (*digit == '\0') {
        combination[index] = '\0';
        int lenOfCombination = strlen(combination) + 1;
        char *finalStr = (char *) malloc(sizeof(char) * lenOfCombination);
        strcpy(finalStr, combination);

        if (total >= preAllocLen) {
            preAllocLen = preAllocLen + total;
            printf("preallocLen=%d\n",preAllocLen);
            
            //char **NewReturnString = (char **)malloc(sizeof(char *) * preAllocLen);
            //memcpy(NewReturnString,returnString,total);
            //free(returnString);
            returnString =  realloc(returnString, sizeof(char *) * preAllocLen);
            printf("After realloc the first p is %p\n",returnString[0]);
        }
        returnString[total] = finalStr;
        if (total == 0) {
            printf("the first p is %p\n",returnString[total]);
        }
        printf("the first p is %p\n",returnString[0]);
        total = total + 1;
        //printf("finalStr is %s\n",finalStr);
        printf("total=%d\n",total);
    } else {
        int len = 0;
        len = getMapLetterStringLen(*digit);
        for (int i=0;i < len;i++) {
            combination[index] = getMapLetter(*digit, i);
            backtrack(digit+1, combination, index+1);
        } 
    }
    return 0;
}


char ** letterCombinations(char * digits, int* returnSize){
    initPhoneHash();
    int digitsLen = strlen(digits) + 1;
    

    printf("digits len is %d\n",digitsLen);

    char combination[digitsLen];    
    memset(combination, 0x00, digitsLen);
    returnString = (char **)malloc(sizeof(char *) * preAllocLen);
    backtrack(digits, combination,0);
    *returnSize = total;
    return returnString;
}



int main(int argc, char *argv[]) {
    if (argc < 2) {
        return -1;
    }
    int len = argc - 1;
    char digits[len+1]; 
    for (int i=0;i<len;i++) {
        digits[i] = argv[i+1][0];
    }
    digits[len] = '\0';
    int returnSize = 0;
    char ** returnString;
    returnString = letterCombinations(digits, &returnSize);

    if (returnString[0] == NULL) {
        printf("I am Null");
    } else {
        printf("the first string is %p\n",returnString[0] );
    }
    //printf("returnSize = %d\n", returnSize);
    /*
    for (int l=0;l<returnSize;l++) {
        printf("the[%d] string is %s\n", l, returnString[l]);
    }*/
    return 0;
}