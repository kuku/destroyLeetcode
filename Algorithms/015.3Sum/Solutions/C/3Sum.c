#include <stdio.h>
#include <stdlib.h>



int cmp(const void *a, const void *b) {
    
    return (*(int *)a-*(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
     int preSize = 64;
   // int ** array2 = (int **)realloc(array2, sizeof(int *)*(*returnSize + 1));
    int **array2 = (int **)realloc(array2, sizeof(int *)*preSize);
    int j=0;
    int k=0;
    *returnColumnSizes = NULL;
    *returnSize = 0;
    
    qsort(nums, numsSize, sizeof(int),cmp);
    int i = 0;
    int s = 0;
    int *array1 = NULL;
    for (i=0;i<numsSize - 2;i++) {
        if (nums[i] > 0) {
            continue;
        }
        if (i>0 && nums[i] == nums[i-1]) {
            continue;
        }
        
        j = i + 1;
        k = numsSize - 1;
        
        while (j < k) {
            if (nums[i] + nums[j] + nums[k] == 0) {            
                
                array2[*returnSize] = (int *)malloc(sizeof(int)*3);
                 array2[*returnSize][0] = nums[i];
                 array2[*returnSize][1] = nums[j];
                 array2[*returnSize][2] = nums[k];
                *returnSize = *returnSize + 1;
                while (j + 1 < k && nums[j+1] == nums[j] ) {
                    j = j+1;
                }
                while ( k - 1  > j && nums[k-1] == nums[k]  ) {
                    k = k-1;
                }
                j = j+1;
                k = k-1;
                if (*returnSize >= preSize) {
                    preSize = preSize + *returnSize;
                    array2 = (int **)realloc(array2, sizeof(int *)*preSize);
                }
            } else if(nums[i] + nums[j] + nums[k] <0) {
                j = j+1;
            } else if(nums[i] + nums[j] + nums[k] >0) {
                k = k-1;
            }
        }
    }
    *returnColumnSizes = (int *)malloc(sizeof(int )*(*returnSize));
    for (i=0;i<*returnSize;i++) {
         (*returnColumnSizes)[i] = 3;
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

    int returnSize = 0;
    int *retrunColumnSize;
    int **array;
    array = threeSum(inputArray, lenOfInputArray, &returnSize, &retrunColumnSize);

    for (int j=0;j<returnSize;j++) {
        printf("%d,%d,%d\n",array[j][0],array[j][1],array[j][2]);
    }

    return 0;
}