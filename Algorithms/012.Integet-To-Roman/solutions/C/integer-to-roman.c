#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const static struct {
    int      val;
    char *str;
} conversion [] = {
    {1, "I"},
    {5, "V"},
    {10, "X"},
    {50, "L"},
    {100, "C"},
    {500, "D"},
    {1000,"M"}
};

char * intToRoman(int num){

    int j;
    char *str = "";
    int leftNum = num;
    int remainder = 0;
    int i = 0;
    while(leftNum > 0) {
        remainder = leftNum % 10;
        leftNum = leftNum / 10;

        printf("leftNum = %d,remainder = %d\n",leftNum,remainder);
        //remainder = remainder * i * 10;
        //convertRemainderToRoman(remainder);
        char *str1="V";
        if (remainder <= 3) {
            int j=0;
            for (;j<remainder;j++) {
                strncat(str1, "I",1);
                printf("the str is %s\n",str1);
            }
        }
        //printf("the str is %s\n",str1);
        /*
        for (j=0; j<sizeof(conversion)/sizeof(conversion[0]);j++) {
            if (num == conversion[j].val) {
                printf("%s\n",conversion[j].str );
                return (conversion[j].str);
            }
        }*/
        i ++;
    }
   
    return str;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return -1;
    }
    int number = atoi(argv[1]);
    printf("%d\n",number);
    char *str = "abc";
    char str1 = 'b';
    strncat(str, &str1, 1);
    printf("the new string is %s\n",str);
    //intToRoman(number);   
}