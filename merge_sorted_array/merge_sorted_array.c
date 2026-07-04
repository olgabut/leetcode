/*
C language
Run
>> cc merge_sorder_array.c
>> ./a.out
>> leaks --atExit -- ./a.out // for MacOS
*/

#include <stdlib.h>
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
	int *num1;
	int m;
	int *num2;
	int n;

	m = 3;
	n = 3;
	num1 = calloc(m + n, sizeof(int));
	num1[0] = 1;
	num1[1] = 2;
	num1[2] = 3;
	num1[3] = 0;
	num1[4] = 0;
	num1[5] = 0;
	printf("num1 = ");
	print_arr(num1, m + n);
	num2 = calloc (n, sizeof(int));
	num2[0] = 2;
	num2[1] = 5;
	num2[2] = 6;
	printf("num2 = ");
	print_arr(num2, n);
	merge(num1, m+n, m, num2, n, n);
	printf("num1 after merge = ");
	print_arr(num1, m + n);
	free(num1);
	free(num2);
}

void example2()
{
	int *num1;
	int m;
	int *num2;
	int n;

	m = 1;
	n = 0;
	num1 = calloc(m + n, sizeof(int));
	num1[0] = 1;
	printf("num1 = ");
	print_arr(num1, m + n);
	num2 = calloc (n, sizeof(int));
	printf("num2 = ");
	print_arr(num2, n);
	merge(num1, m+n, m, num2, n, n);
	printf("num1 after merge = ");
	print_arr(num1, m + n);
	free(num1);
	free(num2);
}

void example3()
{
	int *num1;
	int m;
	int *num2;
	int n;

	m = 0;
	n = 1;
	num1 = calloc(m + n, sizeof(int));
	num1[0] = 0;
	printf("num1 = ");
	print_arr(num1, m + n);
	num2 = calloc (n, sizeof(int));
	num2[0] = 1;
	printf("num2 = ");
	print_arr(num2, n);
	merge(num1, m+n, m, num2, n, n);
	printf("num1 after merge = ");
	print_arr(num1, m + n);
	free(num1);
	free(num2);
}

int main()
{
	example1();
	example2();
	example3();
	return (0);
}