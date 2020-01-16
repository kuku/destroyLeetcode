#include <stdio.h>
#include <stdbool.h>
#include <strings.h>


int getParenthesesIndex(char *p, char s){

    int length = strlen(p);
    for (int i = 0; i < length;i++) {
        if (s == p[i]) {
            return i;
        }
    }
    return -1;
}
char getExpectCharacter(char *p, int index) {
    int length = strlen(p);
    if (index + 3 < length) {
        return p[index+3];
    }
    return '\0';
}

bool isValid(char *s) {
    char parentheses[7] = {'(','{','[',')','}',']'};
    int length = strlen(s);
    if (length % 2 != 0) {
        return false;
    }
    if (length == 0) {
        return true;
    }
    bool ret = false;
    bool isChecked[length];
    for (int k = 0;k<length;k++) {
        isChecked[length] = false;
    }
    for (int i = 0;i<length;i++) {
        if (isChecked[i] == true) {
            continue;
        }
        int index =  getParenthesesIndex(parentheses,s[i]);
        if (index == -1) {
            ret = false;
            break;
        }
        if (index >= 3){
            ret = false;
            break;
        }
        char expectCharacter = getExpectCharacter(parentheses, index);
        int y = 0;
        //printf("s[%d] = %c\n",i,s[i]);
        while ( i + y+1 < length) {
            if (s[i+y+1] == expectCharacter && isChecked[i+y+1] == false) {
                //printf("checked:s[%d]=%c\n",i+y+1, s[i+y+1]);
                isChecked[i+y+1] = true;
                ret = true;
                break;
            } else {
                y = y + 2;
                ret = false;
                continue;
            } 
        }
        if (ret == false) {
            break;
        }
         
    }
    //printf("\n");
    
    return ret;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return -1;
    }

    printf("the input string is %s\n",argv[1]);
    bool isValidStr = isValid(argv[1]);
    printf("the string is %s\n",isValidStr?"valid":"not vlaid");

}