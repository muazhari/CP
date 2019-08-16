#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void year(long int *Ni) {
	long int a = *Ni / 4;
	long int b = *Ni / 100;
	long int c = *Ni / 400;
	long int result = a - b + c;
	printf("%ld", result);
	printf("\na: %ld\nb: %ld\nc: %ld\n", a, b, c);
}

void cases(int *T) {
	for (int i = 1; i <= *T; i++) {
		printf("Case #%d:\n", i+1);

		printf("Enter the number of years: ");
		long int N;
		scanf("%ld", &N);

		if (N >= 1 || N <= pow(10, 6)) {
			year(&N);
		}
	}
}

int main()
{
	printf("Enter the number of cases: ");
	int T;
	scanf("%d", &T);

	if (T >= 1 || T <= 10) {
		cases(&T);
	}
}
