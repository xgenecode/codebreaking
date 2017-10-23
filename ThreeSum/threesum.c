#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int comp_func(const void *x, const void *y)
{
	int a = *(int *)x;
	int b = *(int *)y;

	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

int **threeSum(int *nums, int numsSize, int *returnSize)
{
	int **ret, **new_ret;
	int *tmp;
	int i, x;
	int a, b, c;
	int start, end;
	int count = 0;
	int duplicate;

	if (numsSize < 3)
		return NULL;
	//sort the input form min to max, O(nlogn)
	tmp = malloc(numsSize*sizeof(nums[0]));
	memcpy(tmp, nums, numsSize*sizeof(nums[0]));
	qsort(tmp, numsSize, sizeof(nums[0]), comp_func);

	ret = malloc(sizeof(int*));
	ret[0] = malloc(3 *sizeof(int));
	for (i = 0; i < numsSize - 2; i++) {
		a = tmp[i];
		//won't find a combination if a >0
		if (a > 0)
			break;
		if (i > 0 && (tmp[i] == tmp[i-1]))
			continue;
		start = i + 1;
		end = numsSize - 1;
		while (start < end) {
			b = tmp[start];
			c = tmp[end];
			if (a + b+ c == 0) {
				count ++;
				*returnSize = count;
				new_ret = (int **) realloc(ret, count* sizeof(int *));
				if (new_ret) {
					ret = new_ret;
					ret[count - 1] = (int *)malloc(3 * sizeof(int));
					if (ret[count - 1]) {
						ret[count - 1][0] = a;
						ret[count - 1][1] = b;
						ret[count - 1][2] = c;
					}
				}
				while(tmp[start] == tmp[start + 1])
					start++;
				while(tmp[end] == tmp[end - 1])
					end --;
				end --;
				start++;
			} else if (a + b +c > 0) {
				end --;
			} else {
				start ++;
			}

		}
	} 
	return ret;

}

int main(void)
{
	int nums[6] = {-1, 0, 1, 2, -1, -4};
	int **ret;
	int size, i;

	ret = threeSum(nums, 6, &size);
	if (ret && size) {
		for (i =0; i<size; i++) {
			printf("ret[%d] [%d, %d, %d]\n", i, ret[i][0],ret[i][1], ret[i][2]);
		}
	}
	return 0;
}
