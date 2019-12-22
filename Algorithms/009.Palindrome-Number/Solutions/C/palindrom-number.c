#include <limits.h>
#include <stdbool.h>



bool isPalindrome(int x){
    if (x<0) {
        return false;
    }
    
    if (x<10) {
        return true;
    }
    int ret = 0;
    int originalX = x;
    while (x > 0) {
        if (ret > INT_MAX/10 || (ret == INT_MAX/10 && ((x % 10) > 7)) ) {
            return false;
        }
        
        ret = 10*ret + x % 10;
        x = x / 10;
        
    }
    if (originalX == ret) {
        return true;
    }
    
    return false;
}