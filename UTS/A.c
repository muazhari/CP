#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void timer(long int *Ni)
{
	char msg[] = "%d SECONDS TILL NEW YEAR!!\n";
	printf(msg, *Ni);
	*Ni -= 1;
	for (int j = 0; *Ni != j; *Ni -= 1)
	{
		if (*Ni == 60 || *Ni == 30 || *Ni == 10 || *Ni == 5)
		{
			printf(msg, *Ni);
		}
		else
		{
			printf("%ld\n", *Ni);
		}
	}
}

void cases(int *T)
{
	for (int i = 1; i <= *T; i++)
	{
		printf("Case #%d:\n", i);

		printf("Enter the number of secs: ");
		long int N;
		scanf("%ld", &N);

		if (N >= 1 || N <= pow(10, 5))
		{
			timer(&N);
		}
	}
}

int main()
{
	printf("Enter the number of cases: ");
	int T;
	scanf("%d", &T);

	if (T >= 1 || T <= 10)
	{
		cases(&T);
	}
}
