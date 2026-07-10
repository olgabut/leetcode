
#include <stdio.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize) {
	int candidate = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (count == 0)
            candidate = nums[i];
        if (nums[i] == candidate)
            count++;
        else
            count--;
    }
    return candidate;
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
	int nums[] = {2,2,3,2,3,2,2,7,2,2,4, 4,4, 4, 2, 2};
	int numsSize = 16;

	print_arr(nums, numsSize);
	printf("value of max count = %d\n", majorityElement(nums, numsSize));
}

int main(void)
{
	example1();
	return (0);
}