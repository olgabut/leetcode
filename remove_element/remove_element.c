
#include <stdio.h>


int removeElement(int* nums, int numsSize, int val)
{
	int noRemove = 0;
	int i = 0;

	while(i < numsSize)
	{
		if (nums[i] != val)
		{
			nums[noRemove] = nums[i];
			noRemove++;
		}
		i++;
	}
	i = noRemove;
	while(i < numsSize)
		nums[i++] = 0;
	return (noRemove);
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
	int nums[] = {3, 2, 2, 3};
	int val = 3;
	int numsSize = 4;

	print_arr(nums, numsSize);
	printf("no remuve = %d\n", removeElement(nums, numsSize, val));
	print_arr(nums, numsSize);
}

void example2()
{
	int nums[] = {0,1,2,2,3,0,4,2};
	int val = 2;
	int numsSize = 8;

	print_arr(nums, numsSize);
	printf("no remuve = %d\n", removeElement(nums, numsSize, val));
	print_arr(nums, numsSize);
}

int main(void)
{
	example1();
	example2();
	return (0);
}