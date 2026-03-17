/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int num;
    int freq;
} Element;

int cmp(const void* a, const void* b) {
    return ((Element*)b)->freq - ((Element*)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    int capacity = numsSize;
    Element* freqArr = (Element*)malloc(sizeof(Element) * capacity);
    int freqCount = 0;

    for (int i = 0; i < numsSize; i++) {
        int found = 0;
        for (int j = 0; j < freqCount; j++) {
            if (freqArr[j].num == nums[i]) {
                freqArr[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            freqArr[freqCount].num = nums[i];
            freqArr[freqCount].freq = 1;
            freqCount++;
        }
    }

    qsort(freqArr, freqCount, sizeof(Element), cmp);


    int* result = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        result[i] = freqArr[i].num;
    }

    *returnSize = k;
    free(freqArr);
    return result;
}