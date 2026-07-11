
#include <stdio.h>

void rotate(int* nums, int numsSize, int k) {
    int i;
    int tmp;
    int oto;
    int ofrom;
    int rep;

	if (numsSize == 1)
		return ;
	if (k >= numsSize)
		k = k % numsSize;
	if (k == 0)
		return;
	i = 0;
    rep = 0;
    while (i < numsSize)
    {
	    tmp = nums[k + rep];
        oto = k + rep;
        ofrom = rep;
	    while (1)
	    {
	        // printf("from %d to %d\n", ofrom, oto);
			nums[oto] = nums[ofrom];
			oto = ofrom;
			if (ofrom - k < 0)
				ofrom = numsSize + ofrom - k;
			else
				ofrom = ofrom - k;
			i++;
			if (ofrom == k + rep)
				break;
	    }
        nums[oto] = tmp;
        i++;
        // printf("i = %d\n", i);
        rep++;
	}
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
	int nums[] = {1,2,3,4,5,6,7};
	int numsSize = 7;
	int k = 3;

	print_arr(nums, numsSize);
	rotate(nums, numsSize, k);//{5,6,7,1,2,3,4}
	print_arr(nums, numsSize);
}

void example2()
{
	int nums[] = {-1,-100,3,99};
	int numsSize = 4;
	int k = 2;

	print_arr(nums, numsSize);
	rotate(nums, numsSize, k);//{3,99,-1,-100}
	print_arr(nums, numsSize);
}

void example3()
{
	int nums[] = {0,1,2,3,4,5,6,7};
	int numsSize = 8;
	int k = 2;

	print_arr(nums, numsSize);
	rotate(nums, numsSize, k);
	print_arr(nums, numsSize);
}


int main(void)
{
	example1();
	example2();
	example3();
	return (0);
}



