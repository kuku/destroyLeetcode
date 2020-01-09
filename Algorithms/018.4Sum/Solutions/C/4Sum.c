
#include <stdlib.h>
#include <stdio.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp (const void *a, const void *b) {
    
    return (*(int *)a - *(int *)b); 
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){


    if (returnSize == NULL) {
        returnSize = (int *)malloc(sizeof(int));
    }
    if (numsSize <= 3) {
        *returnSize = 0;
        return NULL;
    }
    
    int preAllocLen = 32;
    int **array = (int **)malloc(sizeof(int *) * preAllocLen);
    returnColumnSizes = (int **)malloc(sizeof(int*) * preAllocLen);
    int totalSize = 0;

    

    qsort(nums, numsSize, sizeof(int), cmp);
    
    for (int i =0;i<numsSize-3;i++) {
        int start = i+1;
        int end = numsSize - 1;
        int beforeEnd = numsSize - 2;
        if (nums[i]>target) {
            continue;
        }
        if (i>0) {
            if (nums[i] == nums[i-1]) {
                continue;
            }
        }
        while ( start < beforeEnd) {
            if (nums[i] + nums[start] + nums[beforeEnd] + nums[end] == target) {
               

                int *tempArray = (int *)malloc(sizeof(int)*4);
                tempArray[0] = nums[i];
                tempArray[1] = nums[start];
                tempArray[2] = nums[beforeEnd];
                tempArray[3] = nums[end];

                if (totalSize >= preAllocLen) {
                    preAllocLen += totalSize;
                    array = realloc(array, sizeof(int *)*preAllocLen);
                    returnColumnSizes = realloc(returnColumnSizes, sizeof(int *)*preAllocLen);
                }
               
                array[totalSize] = tempArray;
 
                int *tempColumnSize = (int *)malloc(sizeof(int)*1);
                tempColumnSize[0] = 4;

                returnColumnSizes[totalSize] = tempColumnSize;

                totalSize++;
                start++;
                end--;
                beforeEnd--;
            }
            if (nums[i] + nums[start] + nums[beforeEnd] + nums[end] > target) {
                end--;
                beforeEnd--;
            }
            if (nums[i] + nums[start] + nums[beforeEnd] + nums[end] < target) {
                start++;
            }
        }

    }
    *returnSize = totalSize;
    return array;
}

int main(int argc, char *argv[]) {
    if (argc <=1 ){
        return -1;
    }    

    int i = 1;

    int lenOfInputArray = argc - 1; 
    int inputArray[lenOfInputArray];
    for (;i<argc;i++) {
        inputArray[i-1] = atoi(argv[i]);
    }

    int returnSize = 0;
    int **returnColumnSize;
    int **array;
    int target = 0;
    fourSum(inputArray, lenOfInputArray, target, &returnSize, returnColumnSize);
}