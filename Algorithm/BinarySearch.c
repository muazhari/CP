#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define arrayLength(array) (size_t)((sizeof array) / (sizeof array[0]))

struct list
{
    int *array;
    size_t length;
} typedef list;

list *newList(int len)
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

list *slice(list *fromList, int i, int n)
{
    // validation
    i = i > fromList->length ? fromList->length : i;
    n = i + n > fromList->length ? fromList->length - i : n;

    list *x = newList(n);
    // printf("fromList len: %d result len: %d\n", fromList->length, n);
    int count = 0;
    while (count < n)
    {
        x->array[count] = *(fromList->array + i);
        // printf("%d\n", x->array[count]);
        count += 1;
        i += 1;
    }

    return x;
}

int binarySearch(list *x, int num)
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
        binarySearch(sliced, num);
    }
    else if (num < x->array[mid])
    {
        sliced = slice(x, 0, mid);
        binarySearch(sliced, num);
    }
}

void test_slice(int id, list *t, int expect)
{
    assert(t->length == expect);
    freeList(t);
    printf("test_slice_%d OK\n", id);
}

void test_binsearch(int id, int t, int expect)
{
    assert(t == expect);
    printf("test_binsearch_%d OK\n", id);
}

void test_unit(list *nums)
{
    test_slice(1, slice(nums, 3, 16), 12);
    test_slice(2, slice(nums, 0, 0), 0);
    test_slice(3, slice(nums, -1, 99999), 0);
    test_slice(4, slice(nums, 0, 99999), 15);
    test_slice(5, slice(nums, 0, -1), 15);

    test_binsearch(1, binarySearch(nums, 11), 1);
    test_binsearch(2, binarySearch(nums, 99), 1);
    test_binsearch(3, binarySearch(nums, 1237), 1);
    test_binsearch(4, binarySearch(nums, -1), 0);
    test_binsearch(5, binarySearch(nums, 99999), 0);
}

int main()
{
    int raw_array[] = {11, 24, 30, 43, 51, 61, 73, 86, 99, 134, 353, 579, 781, 959, 1237};

    // declare array as list
    list *nums = newList(arrayLength(raw_array));
    nums->array = raw_array;
    printl(nums);

    test_unit(nums);

    int find = binarySearch(nums, 579);
    printf("%d", find);
}
