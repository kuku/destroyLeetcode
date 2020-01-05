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


char ** letterCombinations(char * digits, int* returnSize){
    initPhoneHash();
    
    

    int digitsLen = strlen(digits) + 1;

    printf("digits len is %d\n",digitsLen);

    char combination[digitsLen];    
    memset(combination, 0x00, digitsLen);
    for(int i=0;i < digitsLen - 1;i++) {
        int number = digits[i] - '0';
        //printf("number = %d\n", number);
        int mapIndex = 0;
        char mapLetter;
        
        mapLetter = getMapLetter(digits[i], mapIndex);
        if(mapLetter != '\0') {
            combination[i] = mapLetter;
        }
    }
    printf("stringis %s\n",combination);


    

    char **returnString = (char **)malloc(sizeof(char *)*1);
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
    letterCombinations(digits, &returnSize);
    return 0;
}