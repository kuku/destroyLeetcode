#include <stdio.h>
#include <stdlib.h>



int cmp(const void *a, const void *b) {
    return (*(int *)a-*(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **array2 = NULL;

    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int),cmp);
    int i = 0;
    for (i=0;i<numsSize - 2;i++) {
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            if (nums[i] + nums[j] + nums[k] == 0) {
                //printf("%d, %d, %d\n",nums[i],nums[j],nums[k]);
                int duplicate = 0;
                for (int s=0;s<*returnSize;s++) {
                    if ((array2[s][0] == nums[i] && array2[s][1] == nums[j])){
                        duplicate = 1;
                        break;;
                    }
                }
                if (duplicate == 1) {
                    j = j+1;
                    k = k-1;
                    continue;
                }
                int *array1 = (int *)malloc(sizeof(int)*3);
                //*returnColumnSizes  = malloc(sizeof(int)*1);
                array1[0] = nums[i];
                array1[1] = nums[j];
                array1[2] = nums[k];
                array2 = (int **)realloc(array2, sizeof(int *)*(*returnSize + 1));
                array2[*returnSize] = array1;
                *returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int)*(*returnSize + 1));
                (*returnColumnSizes)[*returnSize] = 3;
                *returnSize = *returnSize + 1;
                //printf("i=%d,j=%d,k=%d\n",i,j,k);
                j = j+1;
                k = k-1;

            } else if(nums[i] + nums[j] + nums[k] <0) {
                j = j+1;
            } else if(nums[i] + nums[j] + nums[k] >0) {
                k = k-1;
            }
        }
    }
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
    int **array;
    array = threeSum(inputArray, lenOfInputArray, &returnSize, &retrunColumnSize);

    for (int j=0;j<returnSize;j++) {
        printf("%d,%d,%d\n",array[j][0],array[j][1],array[j][2]);
    }

    return 0;
}