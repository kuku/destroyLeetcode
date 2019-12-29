#include <stdio.h>
#include <stdlib.h>



int cmp(const void *a, const void *b) {
    return (*(int *)a-*(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    qsort(nums, numsSize, sizeof(int),cmp);
    int i = 0;
    for (i=0;i<numsSize - 2;i++) {
        int j = i + 1;
        int k = numsSize - i;
        while (j < k) {
            if (nums[i] + nums[j] + nums[k] == 0) {
                printf("%d, %d, %d\n",nums[i],nums[j],nums[k]);
                j = j+1;
            } else if(nums[i] + nums[j] + nums[k] <0) {
                j = j+1;
            } else if(nums[i] + nums[j] + nums[k] >0) {
                k = k-1;
            }
        }
    }
    int **array2 = (int **)malloc(sizeof(int *)*1);
    
    *returnSize = 2;
    return array2;
}

int main(int argc, char *argv[]){
    if (argc <=1 ){
        return -1;
    }    

    int i = 1;

    int lenOfInputArray = argc - 1; 
    int inputArray[lenOfInputArray];
    for (;i<argc;i++) {
        inputArray[i-1] = atoi(argv[i]);
    }

    printf("%d\n",lenOfInputArray);
    qsort(inputArray, lenOfInputArray, sizeof(int), cmp);
    for(i=0;i<lenOfInputArray;i++) {
        printf("%d\n",inputArray[i]);
    }

    int returnSize = 0;
    int *retrunColumnSize;

    threeSum(inputArray, lenOfInputArray, &returnSize, &retrunColumnSize);

    return 0;
}