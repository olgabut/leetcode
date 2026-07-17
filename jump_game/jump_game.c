
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int i;
    int max;

	max = 0;
    if (numsSize <= 1)
        return (true);
    for (i = 0; i < numsSize; i++)
    {
        if (i > max)
            return (false);
        max = max > i + nums[i] ? max : i + nums[i];
    }
    return (true);
}


void print_arr(int *arr, int size)
{
	int i;
	printf("[");
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("]\n");
}

void example1()
{
	int nums[] = {2,3,1,1,5};
	int numsSize = 5;

	print_arr(nums, numsSize);
	printf("jump %d\n", canJump(nums, numsSize));
}

void example2()
{
	int nums[] = {3,2,1,0,4};
	int numsSize = 5;

	print_arr(nums, numsSize);
	printf("jump %d\n", canJump(nums, numsSize));
}

int main(void)
{
	example1();
	example2();
	return (0);
}