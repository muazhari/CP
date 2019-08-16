#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int *getRandom()
{

	static int r[10];
	int i;

	/* set the seed */
	srand((unsigned)time(NULL));

	for (i = 0; i < 10; ++i)
	{
		r[i] = rand();
		printf("r[%d] = %d\n", i, r[i]);
	}

	return r;
}

struct list
{
	int *array;
	int *length;
} typedef list;

int *slice(int *array, int i, int n)
{
	list *result;
	result->array = malloc(sizeof *result * n);
	int len = sizeof(*array) / sizeof(int);

	int count = 0;

	printf("r[%d] = %d\n", (len), array);

	for (int index = i; i < len && count != n; index++)
	{
		result->array[count] = array[index];
		result->length++;
		count++;

		printf("r[%d] = %d\n", (len), array[index]);
	}
	return result;
}

// int isInArray(int *array, int num)
// {
// 	int len = sizeof(array) / sizeof(array[0]);
// 	int mid = floor(len / 2);

// 	if (num > array[mid])
// 	{
// 	}
// }

int main()
{
	int array[] = {11, 24, 30, 43, 51, 61, 73, 86};
	list *sliced = slice(array, 1, 5);
	// int result = isInArray(&array, 20);

	// int *p = getRandom();

	// for (int i = 0; i < 10; i++)
	// {
	// 	printf("*(p + %d) : %d\n", i, *(p + i));
	// }
	// int len = sizeof(sliced) / sizeof(sliced[0]);
	for (int i = 0; i < 5; i++)
	{
		printf("*(p + %d) : %d\n", i, *(sliced->array + i));
	}
	// printf("%d", result);
}
