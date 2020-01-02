#include <stdlib.h>
#include <stdio.h>

int cmp(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b);
}


int threeSumClosest(int* nums, int numsSize, int target){
    qsort((void *)nums, numsSize, sizeof(int),cmp);
    int closestValue = 10000;
    int minDiff = 10000;
    int closestIndex = 0;
    if (numsSize == 3) {
        return (nums[0] + nums[1] + nums[2]);
    }
    for(int i =0;i<numsSize-2;i++) {
        int j = i+1;
        int k = numsSize - 1;
        while(j<k) {
            int sum = nums[i] + nums[j] + nums[k];
            printf("sum=%d\n",sum);
            int diff = sum - target;
            printf("diff=%d\n",diff);
            if (diff == 0) {
                return sum;
            }
            if (abs(diff) < abs(minDiff)) {
                minDiff = diff;
                closestValue = sum;
                
            } 
            if (diff > 0) {
                k = k - 1;
            }
            if (diff < 0) {
                j = j + 1;
            }
        }
    }
    printf("closeValue=%d\n",closestValue);
    return closestValue;
}



int main(int argc, char *argv[]) {
    if (argc <= 2) {
        return -1;
    } 

    int i = 1;

    int lenOfInputArray = argc - 1; 
    int inputArray[lenOfInputArray];
    for (;i<argc;i++) {
        inputArray[i-1] = atoi(argv[i]);
    }
    threeSumClosest(inputArray, lenOfInputArray,-100);
}