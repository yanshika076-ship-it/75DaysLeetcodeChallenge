/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* a = (int*)malloc(numsSize * sizeof(int));
    int count=0;
    for(int i=0;i<numsSize;i++){
       int index=abs(nums[i])-1;
       if (nums[index]<0){
        a[count++]=abs(nums[i]);
       }else{
        nums[index]=-nums[index];
               }
    }
    *returnSize=count;
    return a;
}