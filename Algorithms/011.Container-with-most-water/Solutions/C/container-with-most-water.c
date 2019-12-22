int maxArea(int* height, int heightSize){
    int maxWater = 0;
    int i = 0;
    if (heightSize == 1) {
        return 0;
    }
    for (;i<heightSize-1;i++) {
        int j = i + 1;
        int water = 0;
        for (;j<heightSize;j++) {
            if (height[i] <= height[j]) {
                water = height[i]* (j-i); 
            } else {
                water = height[j]* (j-i);
            }
            if (water > maxWater) {
                maxWater = water;
            }
            //printf("i=%d,j=%d,water=%d\n",i,j,water);
        }
    }
    return maxWater;
}