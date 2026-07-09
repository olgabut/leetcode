
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	int unique = 0;
	int equal = 0;
	int count = 1;

	if (numsSize <= 1)
		return (numsSize);

	for(int i = 1; i < numsSize; i++)
	{
		if (nums[i] != nums[unique])
		{
		    count = 1;
			unique++;
			if (i != unique)
				nums[unique] = nums[i];
		}
		else
		{
			if (count == 1)
			{
				unique++;
				if (i != unique)
					nums[unique] = nums[i];
			}
			count++;
		}
	}
	return (unique + 1);
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
	int nums[] = {1,1,1,2,2,3};
	int numsSize = 6;

	print_arr(nums, numsSize);
	printf("unique = %d\n", removeDuplicates(nums, numsSize));
	print_arr(nums, numsSize);
}

void example2()
{
	int nums[] = {0,0,1,1,1,1,2,3,3};
	int numsSize = 9;

	print_arr(nums, numsSize);
	printf("unique = %d\n", removeDuplicates(nums, numsSize));
	print_arr(nums, numsSize);
}

int main(void)
{
	example1();
	example2();
	return (0);
}



