#include <stdio.h>
#include <stdlib.h>



int min (int a, int b) {
    
    if (a > b) {
        return b;
    } 
    
    return a;
}

int main (int argc, char *argv[]) {
    
    if ( argc != 2) {
        return -1;
    }
    int n = atoi(argv[1]);
    printf("n = %d\n", n);

    int i = 0;
    int dp[n+1];
    dp[1] = 0;
    for (i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i-1];
        if (i % 2 == 0) {
            dp[i] = min(dp[i], 1 + dp[i / 2]);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], 1 + dp[i /3 ]);
        }
    }
    printf("i=%d\n",i);
    printf("The minimut steps to one is %d\n",dp[i-1]);
}