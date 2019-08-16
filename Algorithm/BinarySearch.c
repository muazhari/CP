#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define arrayLength(array) (size_t)((sizeof array) / (sizeof array[0]))

struct list
{
    long int *array;
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
    int count = 0;

    while (count < n)
    {
        x->array[count] = *(fromList->array + i);
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

int binarySearch2(list *x, int l, int r, int num)
{

    long int mid = (l + r) / 2;
    // printf("mid: %d, l: %d, r: %d\n", x->array[mid], l, r);
    list *sliced = slice(x, l, r - l);
    printl(sliced);

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

void test_slice(int id, list *t, int expect)
{
    assert(t->length == expect);
    freeList(t);
    printf("==================================\n");
    printf("test_slice_%d OK\n", id);
    printf("==================================\n");
}

void test_binsearch(int id, int t, int expect)
{
    assert(t == expect);
    printf("==================================\n");
    printf("test_binsearch_%d OK\n", id);
    printf("==================================\n");
}

void test_unit(list *x)
{
    // test_slice(1, slice(x, 3, 16), 12);
    // test_slice(2, slice(x, 0, 0), 0);
    // test_slice(3, slice(x, -1, 99999), 0);
    // test_slice(4, slice(x, 0, 99999), 15);
    // test_slice(5, slice(x, 0, -1), 15);

    test_binsearch(1, binarySearch(x, 11), 1);
    test_binsearch(2, binarySearch(x, 99), 1);
    test_binsearch(3, binarySearch(x, 1237), 1);
    test_binsearch(4, binarySearch(x, -1), 0);
    test_binsearch(5, binarySearch(x, 99999), 0);

    test_binsearch(1, binarySearch2(x, 0, x->length, 11), 1);
    test_binsearch(2, binarySearch2(x, 0, x->length, 99), 1);
    test_binsearch(3, binarySearch2(x, 0, x->length, 1237), 1);
    test_binsearch(4, binarySearch2(x, 0, x->length, -1), 0);
    test_binsearch(5, binarySearch2(x, 0, x->length, 99999), 0);
}

int main()
{
    int raw_array[] = {11, 24, 30, 43, 99, 1237};
    char raw_array2[] = "halo";

    // declare array as list
    list *nums = newList(arrayLength(raw_array));
    nums->array = raw_array;
    printl(nums);

    test_unit(nums);

    int find = binarySearch(nums, 24);
    printf("%d", find);
}
