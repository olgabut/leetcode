
#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    int i;
    int min;
    int max;
    int minall;
    int maxpart;

	if (pricesSize <= 1)
		return (0);
	min = prices[0];
	max = prices[0];
	minall = prices[0];
	maxpart = prices[0];
    i = 1;
    while (i < pricesSize)
    {
        if (prices[i] > maxpart)
            maxpart = prices[i];

        if (max - min < maxpart - minall)
        {
            max = maxpart;
            min = minall;
        }
		if (prices[i] < minall)
		{
			minall = prices[i];
			maxpart = prices[i];
		}
        i++;
    }
    return (max - min);
}


void print_arr(int *arr, int size)
{
	int i;
	printf("[");
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("]\n");
}

void myexample()
{
	int nums[] = {7,8,2,3,8,4,1,5,3,6,4,1};
	int numsSize = 12;

	print_arr(nums, numsSize);
	printf("value of max count = %d\n", maxProfit(nums, numsSize));
}

int main(void)
{
	myexample();
	return (0);
}