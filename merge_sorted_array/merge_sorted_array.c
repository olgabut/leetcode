/*
C language
Run
>> cc merge_sorder_array.c
>> ./a.out
*/

#include <stdio.h>


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i1;
	int i2;
	int ifin;

	if (n == 0)
		return ;
	i1 = m - 1;
	i2 = n - 1;
	for (ifin = n + m - 1; ifin >= 0; ifin--)
	{
		if (i1 < 0)
			nums1[ifin] = nums2[i2--];
		else if (i2 < 0)
			nums1[ifin] = nums1[i1--];
		else
		{
			if (nums1[i1] > nums2[i2])
				nums1[ifin] = nums1[i1--];
			else
				nums1[ifin] = nums2[i2--];
		}
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
	int m = 3;
	int n = 3;
	int num1[6] = {1,2,3,0,0,0};
	int num2[3] = {2,5,6};

	printf("num1 = ");
	print_arr(num1, m + n);
	printf("num2 = ");
	print_arr(num2, n);
	merge(num1, m+n, m, num2, n, n);
	printf("num1 after merge = ");
	print_arr(num1, m + n);
}

void example2()
{
	int m = 1;
	int n = 0;
	int num1[1] = {1};
	int num2[0] = {};

	printf("num1 = ");
	print_arr(num1, m + n);
	printf("num2 = ");
	print_arr(num2, n);
	merge(num1, m+n, m, num2, n, n);
	printf("num1 after merge = ");
	print_arr(num1, m + n);
}

void example3()
{
	int m = 0;
	int n = 1;
	int num1[1] = {0};
	int num2[1] = {1};

	printf("num1 = ");
	print_arr(num1, m + n);
	printf("num2 = ");
	print_arr(num2, n);
	merge(num1, m+n, m, num2, n, n);
	printf("num1 after merge = ");
	print_arr(num1, m + n);
}

int main()
{
	example1();
	example2();
	example3();
	return (0);
}