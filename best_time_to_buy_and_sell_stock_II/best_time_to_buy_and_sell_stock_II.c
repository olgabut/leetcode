
#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    int i;
    int minpart;
    int maxpart;
    int prev;
    int profit_part = 0;
    int profit_all = 0;

	if (pricesSize <= 1)
		return (0);
	minpart = prices[0];
	maxpart = prices[0];
	prev = prices[0];
    i = 1;
    while (i < pricesSize)
    {
        if (prices[i] >= maxpart)
        {
            maxpart = prices[i];
		}
		if (maxpart - minpart > 0 && maxpart - minpart > profit_part)
                profit_part = maxpart - minpart;
        if (prices[i] < prev)
        {
            profit_all +=profit_part;
            profit_part = 0;
            minpart = prices[i];
            maxpart = prices[i];
        }
        // printf("prices[%d]= %d min= %d max= %d profit_part= %d profit_all= %d\n",
        //     i, prices[i], minpart, maxpart, profit_part, profit_all);
        prev = prices[i];
        i++;
    }
    profit_all +=profit_part;
    return (profit_all);
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
	int nums[] = {7,5,3,8,5,1,2,3,4,2,6,7,3};
	int numsSize = 13;

	print_arr(nums, numsSize);
	printf("value of max profit = %d\n", maxProfit(nums, numsSize));
}

void example1()
{
	int nums[] = {7,1,5,3,6,4};
	int numsSize = 6;

	print_arr(nums, numsSize);
	printf("value of max profit = %d\n", maxProfit(nums, numsSize));
}

void example2()
{
	int nums[] = {1,2,3,4,5};
	int numsSize = 5;

	print_arr(nums, numsSize);
	printf("value of max profit = %d\n", maxProfit(nums, numsSize));
}

void example3()
{
	int nums[] = {7,6,4,3,1};
	int numsSize = 5;

	print_arr(nums, numsSize);
	printf("value of max profit = %d\n", maxProfit(nums, numsSize));
}

int main(void)
{
	myexample();
	example1();
	example2();
	example3();
	return (0);
}