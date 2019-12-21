#include <stdlib.h>
#include <stdio.h>
#include <limits.h>



int reverseInteger(int n) {
    int pop;
    int rev = 0;
    int sign = 0;
    /*
    if ( n < 0 ) {
        sign = 1;
        n = abs(n);
    }*/
    while (n != 0) {
        pop = n % 10;
        n = n / 10;
        //printf("pop = %d, n = %d\n",pop, n);
        if ((rev > INT_MAX / 10) || (rev == INT_MAX/10 && pop > 7 )) {
            return 0;
        } 
        if ((rev < INT_MIN / 10) || (rev == INT_MIN/10 && pop < -8)) {
            return 0;
        }
        rev = rev * 10 + pop;
    }
    /*
    if (sign == 1) {
        rev = 0 - rev;
    }*/
    return rev;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return -1;
    }


    //printf("%d\n", INT_MAX); //2147483647
    //printf("%d\n",INT_MIN);  //-2147483648
    int n = atoi(argv[1]);

    int rev = reverseInteger(n);
    printf("des is %d\n", rev);
    return 0;
}