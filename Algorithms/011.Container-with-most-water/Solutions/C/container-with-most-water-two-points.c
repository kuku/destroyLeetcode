int maxArea(int* height, int heightSize){   
    if (heightSize == 1) {
        return 0;
    }
    int i = 0;
    int j = heightSize - 1;
    int water = 0;
    int maxWater = 0;
    while(i<j) {
        int water = 0;
        if (height[i] <= height[j]) {
            water = height[i] * (j-i);
            i++;
            if (water > maxWater) {
                maxWater = water;
            }
            continue;
        } else {
            water = height[j] * (j-i);
            j--;
            if (water > maxWater) {
                maxWater = water;
            }
            continue;
        }

    }
    return maxWater;
}