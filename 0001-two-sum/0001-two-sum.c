/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;
    int* result = (int*)malloc(2 * sizeof(int));
    for(int x=0;x<numsSize;x++){
        for(int y=x+1;y<numsSize;y++){
            if(nums[x]+nums[y]==target){
              result[0]=x;
               result[1]=y;
               return result;
            }
        }
    }
   return NULL; 
}