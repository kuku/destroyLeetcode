#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>




int myAtoi(char * str){
    int lenStr = strlen(str);
    if (lenStr == 0) return 0;
    int res = 0;
    int i = 0;
    int start = 0;
    int sign = 0;
    int second_max_num = INT_MAX / 10;
    int second_min_num = INT_MIN / 10;
    for (; i < lenStr; i++) {
        if (start == 0 && str[i] == ' ') {
            continue;
        } else if (start == 0 && str[i] == '-' ) {
            start = 1;
            sign = 1;
        } else if (start == 0 && str[i] == '+' ) {
            start = 1;
            sign = 0;
        } else if (start == 0  && str[i] >= '0' && str[i] <= '9') {
            res = str[i] - '0';
            start = 1;
        } else if (str[i] > '9' || str[i] < '0') {
            break;
        } else {
            if ((res > second_max_num) || ((res == second_max_num) && str[i] - '0' > 7)) {
                res = INT_MAX;
                break;
            }
            if ((res < second_min_num) || ((res == second_min_num) && str[i] - '0' > 8)) {
                res = INT_MIN;
                break;
            }
            
            if (sign == 1) {
                res = res * 10 - (str[i] - '0');
            } else {
                res = res * 10 + (str[i] - '0');
            }
        }
    }
    return res;
}





int main (int argc, char *argv[]) {
    if (argc < 2) {
        return -1;
    }

    printf("the string is %s\n", argv[1]);
    //char *str = argv[1];
    //int c = str[0];
    //printf("%d\n", c-'0');
    int res = myAtoi(argv[1]);    
    printf("res is %d\n", res);
}