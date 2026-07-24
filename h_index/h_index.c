
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int hIndex(int* citations, int citationsSize)
{
    int i,j;
    int count = 0;
    int max = 0;
    int better = 0;
    int local_better = 0;

	if (citationsSize < 1)
		return (0);
	if (citationsSize == 1)
		return (citations[0] >= 1? 1: 0);
	for(i = 0; i < citationsSize; i++)
	{
		if (citations[i] >= citationsSize)
			count++;
	}
	better = count;
    for(i = 0; i < citationsSize; i++)
    {
        j = 0;
        count = 0;
        while (j < citationsSize)
        {
            if (citations[j] >= citations[i])
                count++;
            j++;
        }
        local_better = count < citations[i] ? count : citations[i];
        if (better < local_better)
            better = local_better;
        // printf("num=%d count=%d loc=%d\n", citations[i], count, local_better);
    }
    return (better);
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
	int nums[] = {6,6,6,6,6,6,1,0,1,0,2};
	int numsSize = 11;

	print_arr(nums, numsSize);
	printf("expected= 6\n");
	printf("h-index = %d\n", hIndex(nums, numsSize));
}

void example2()
{
	int nums[] = {4,0,6,2,2,5};
	int numsSize = 6;

	print_arr(nums, numsSize);
	printf("expected= 3\n");
	printf("h-index = %d\n", hIndex(nums, numsSize));
}

void example3()
{
	int nums[] = {1,3,1};
	int numsSize = 3;

	print_arr(nums, numsSize);
	printf("expected= 1\n");
	printf("h-index = %d\n", hIndex(nums, numsSize));
}

void example4()
{
	int nums[] = {11,15};
	int numsSize = 2;

	print_arr(nums, numsSize);
	printf("expected= 2\n");
	printf("h-index = %d\n", hIndex(nums, numsSize));
}

void example5()
{
	int nums[] = {2,3,2};
	int numsSize = 3;

	print_arr(nums, numsSize);
	printf("expected= 2\n");
	printf("h-index = %d\n", hIndex(nums, numsSize));
}

void example6()
{
	int nums[] = {8,2,8,9,2};
	int numsSize = 5;

	print_arr(nums, numsSize);
	printf("expected= 3\n");
	printf("h-index = %d\n", hIndex(nums, numsSize));
}


int main(void)
{
	example1();
	example2();
	example3();
	example4();
	example5();
	example6();
	return (0);
}