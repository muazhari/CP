#include <stdio.h>
#include <assert.h>
#define arraySize(array) (size_t)(sizeof(array) / sizeof(array[0]))
#define strSize(string) (size_t)(strlen(string))

typedef struct string
{
    char *string;
    size_t size;
} str;

typedef struct list
{
    int *array;
    size_t size;

} list;

str *newString(size_t const n)
{
    str *x = (str *)malloc(sizeof(str));
    x->string = malloc(strSize(x->string) * n);
    x->size = n;
    return x;
}

list *newList(size_t const n)
{
    list *x = (list *)malloc(sizeof(str));
    x->array = malloc(arraySize(x->array) * n);
    x->size = n;
    return x;
}

void freeStr(str *x)
{
    // free(x->string);
    free(x);
}

void freeList(list *x)
{
    free(x->array);
    free(x);
}

long int pow(int const x, int const n)
{
    long int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= x;
    }

    return result;
}

long int solve(str const *const x)
{
    long int sum = 0;
    long int pow_i = 0;

    for (long int i = x->size - 1; i >= 0; i -= 1)
    {
        if (x->string[i] == ')')
        {
            sum -= (x->string[i - 1] - '0') * pow(2, pow_i);
            i -= 3;
        }
        else
        {
            sum += (x->string[i] - '0') * pow(2, pow_i);
        }
        pow_i += 1;
    }
    return sum;
}

void test_solve(int const n, char const *const t, int const expect)
{
    str *x = newString(strSize(t));
    x->string = t;

    long int result = solve(x);
    printf("result: %ld\n", result);

    assert(result == expect);
    freeStr(x);
    printf("test_solve_%d OK\n", n);
}

void test_unit()
{
    test_solve(1, "1000", 8);
    test_solve(2, "000000", 0);
    test_solve(3, "1111", 15);
    test_solve(4, "(-1)", -1);
    test_solve(5, "(-1)(-1)(-1)(-1)", -15);
    test_solve(6, "1(-1)(-1)(-1)", 1);
}

void cases(int const T)
{
    for (int i = 1; i <= T; i++)
    {
        printf("Case #%d:\n", i);

        printf("Enter the string binary: \n");
        char *N = malloc(sizeof(char));
        scanf("%s", N);

        str *x = newString(strSize(N));
        x->string = N;

        long int result = solve(x);
        printf("result: %ld\n", result);
    }
}

int main()
{
    test_unit();
    printf("Enter the number of cases: \n");
    int T;
    // scanf("%d", &T);

    if (T >= 1 || T <= 10)
    {
        cases(1);
    }
}