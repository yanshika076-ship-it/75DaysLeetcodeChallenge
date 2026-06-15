int maxProduct(int* nums, int numsSize) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int tempMax = maxProd;
        int tempMin = minProd;

        maxProd = nums[i];
        if (tempMax * nums[i] > maxProd) maxProd = tempMax * nums[i];
        if (tempMin * nums[i] > maxProd) maxProd = tempMin * nums[i];

        minProd = nums[i];
        if (tempMax * nums[i] < minProd) minProd = tempMax * nums[i];
        if (tempMin * nums[i] < minProd) minProd = tempMin * nums[i];

        if (maxProd > result) result = maxProd;
    }

    return result;
}