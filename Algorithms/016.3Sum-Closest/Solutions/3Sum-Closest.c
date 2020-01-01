#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b);
}


int threeSumClosest(int* nums, int numsSize, int target){
    qsort((void *)nums, numsSize, sizeof(int),cmp);
    int closestValue = 10000;
    int closestIndex = 0;
    for(int i =0;i<numsSize-2;i++) {
        int j = i+1;
        int k = numsSize - 1;
        while(j<k) {
            int sum = nums[i] + nums[j] + nums[k];
            int diff = target - sum;
            if (abs(diff) < closestValue) {
                closestValue = sum;
            } else if (diff == 0) {
                return sum;
            }
            if (diff > 0) {
                k = k - 1;
            }
            if (diff < 0) {
                j = j + 1;
            }
        }
    }
    return closestValue;
}