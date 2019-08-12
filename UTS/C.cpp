void zone(char *S) {
	long int zero, one;

	long int len = sizeof(S) / sizeof(S[0]);

	//reducing
	for (long int i = 0; i < len; i+=1) {
		switch (S[i]) {
		case '0':
			zero += 1;
			break;
		case '1':
			one += 1;
			break;
		}
	}

	if (zero > one) {
		printf("0 %ld", zero);
	} else {
		printf("1 %ld", one);
	}
}

void cases(int *T) {
	for (int i = 1; i <= *T; i++) {
		printf("Case #%d:\n", i+1);

		printf("Enter the string size: ");
		long int N;
		scanf("%ld", &N);

		printf("Enter the string: ");
		char S[N];
		scanf("%s", S);

		if (N >= 1 || N <= pow(10, 5)) {
			zone(S);
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
