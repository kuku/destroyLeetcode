#include <stdlib.h>
#include <stdio.h>



int reverseInteger(int n) {

    if (n < 10 && n > -10) {
        return n;
    }
    //printf(n);
    int sigh = 0;
    if (n < 0) {
        sigh = 1;
    }
    n = abs(n);
    int des[10];
    int i = 0;
    while (n > 0) {
        des[i]  = n % 10;
        i = i + 1;
        n = n / 10;
    }
    //printf("%d%d\n",des[0],des[1]);
    if (n >= (2^31 - 1) || n <= -(2^31)) {
        return 0;
    }
   
    int j = 0;
    int digitNum = i - 1;
    int desNumber = 0;
    //printf("i=%d\n",i);
    for (j=0; j < i;j++) {
        int k = 0;
        int numberZ = 1;
        for (k = 0;k < digitNum;k++) {
            numberZ = numberZ * 10;
        }
        desNumber = des[j] * numberZ + desNumber;
        digitNum = digitNum - 1;
    }

    //printf("des:%d\n",desNumber);
    if (sigh == 1) {
        desNumber = 0 - desNumber;
    }
    return desNumber;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return -1;
    }
   
    int n = atoi(argv[1]);

    int des = reverseInteger(n);
    printf("des is %d\n", des);
    return 0;
}