#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "Test.h"

#define arrayLength(array) (size_t)((sizeof array) / (sizeof array[0]))

typedef struct list
{
    long int *array;
    size_t length;
} list;

list *newList(int const len)
{
    list *x = (list *)malloc(sizeof(list));
    x->array = malloc(sizeof(*x->array) * len);
    x->length = len;

    return x;
}

void freeList(list *x)
{
    free(x->array);
    free(x);
}

void copyList(list *listFrom, list *listTo)
{
    listTo->length = listFrom->length;
    memcpy(&listTo->array, &listFrom->array, listFrom->length);
}

void printl(list *x)
{
    printf("[");
    for (int i = 0; i < x->length; i++)
    {
        printf(" %d", *(x->array + i));
    }
    printf(" ]\n");
}

list *slice(list const *const fromList, int i, int n)
{
    // validation
    i = i > fromList->length ? fromList->length : i;
    n = i + n > fromList->length ? fromList->length - i : n;

    list *x = newList(n);
    int count = 0;

    while (count < n)
    {
        x->array[count] = *(fromList->array + i);
        count += 1;
        i += 1;
    }

    return x;
}

int binarySearch(list const *const x, int num)
{
    list *sliced;
    int mid = (int)x->length / 2;

    if (num == (int)x->array[mid])
    {
        return 1;
    }
    else if (x->length == 1)
    {
        return 0;
    }
    else if (num > x->array[mid])
    {
        sliced = slice(x, mid, x->length - mid);
        printl(sliced);
        binarySearch(sliced, num);
    }
    else if (num < x->array[mid])
    {
        sliced = slice(x, 0, mid);
        printl(sliced);
        binarySearch(sliced, num);
    }
}

int binarySearch2(list const *const x, int l, int r, int num)
{
    long int mid = (l + r) / 2;
    list *sliced = slice(x, l, r - l);
    printl(sliced);
    freeList(sliced);

    if (num == x->array[mid])
    {
        return 1;
    }
    else if (l == r || r - l == 1 && num != x->array[mid])
    {
        return 0;
    }
    else if (num > x->array[mid])
    {
        return binarySearch2(x, mid, r, num);
    }
    else if (num < x->array[mid])
    {
        return binarySearch2(x, l, mid, num);
    }
}

int main()
{
    int raw_array[] = {11, 24, 30, 43, 51, 61, 73, 86, 99, 134, 353, 579, 781, 959, 1237};

    // declare array as list
    list *nums = newList(arrayLength(raw_array));
    nums->array = raw_array;
    printl(nums);

    // test_unit(nums);

    int N = 233;

    int find = binarySearch(nums, N);
    printf("IsFound? %d\n", find);

    int find2 = binarySearch2(nums, 0, nums->length, N);
    printf("IsFound? %d\n", find2);
}
