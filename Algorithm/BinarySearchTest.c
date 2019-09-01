#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BinarySearch.c"
#include "Test.h"

void test_slice(int id, list *t, int expect) {
  assert(t->length == expect);
  printl(t);
  freeList(t);
  printf("==================================\n");
  printf("test_slice_%d OK\n", id);
  printf("==================================\n");
}

void test_slice(int id, list *t, int expect) {
  assert(t->length == expect);
  printl(t);
  freeList(t);
  printf("==================================\n");
  printf("test_slice_%d OK\n", id);
  printf("==================================\n");
}

void test_binsearch(int id, int t, int expect) {
  assert(t == expect);
  printf("==================================\n");
  printf("test_binsearch_%d OK\n", id);
  printf("==================================\n");
}

void test_unit(list *x) {
  test_slice(1, slice(x, 3, 16), 12);
  test_slice(2, slice(x, 0, 0), 0);
  test_slice(3, slice(x, -1, 99999), 0);
  test_slice(4, slice(x, 0, 99999), 15);
  test_slice(5, slice(x, 0, -1), 15);

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