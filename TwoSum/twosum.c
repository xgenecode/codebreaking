#include <stdlib.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	int *ret;
	int i, j;

	ret = (int *) malloc(2*sizeof(int));
	for (i = 0; i < numsSize - 1; i++ ) {
		for (j = i+1; j < numsSize; j++) {
			if ((nums[i] + nums[j]) == target) {
				ret[0] = i;
				ret[1] = j;
				return ret;
			} 
		}
	}
	return NULL;
}

int main(void)
{
	int nums[3] = {3,2,3};
	int target = 6;
	int *ret;

	ret = twoSum(nums, 3, target);
	if (ret)
		printf("ret [%d, %d]\n", ret[0], ret[1]);
	return 0;
}
