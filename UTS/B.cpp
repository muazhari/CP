#include <stdio.h>

void B()
{
	int T, N;
	char flavor, c, s, v;
	int chocolateCounter = 0, strawberryCounter = 0, vanillaCounter = 0;

	printf("Enter the number of cases: ");
	scanf("%d", &T);
	printf("Enter the number of people: ");
	scanf("%d", &N);

	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= N; j++) {
			printf("Please enter a flavor: ");
			scanf(" %c", &flavor);

			if (flavor == 'c') {
				chocolateCounter++;
			} else if (flavor == 's') {
				strawberryCounter++;
			} else {
				vanillaCounter++;
			}
		}

		printf("Case #%d:\n", i);

		if (chocolateCounter > strawberryCounter && chocolateCounter > vanillaCounter) {
			printf("Chocolate\n");
		} else if (chocolateCounter < strawberryCounter && strawberryCounter < vanillaCounter) {
			printf("Strawberry\n");
		} else if (vanillaCounter > chocolateCounter && vanillaCounter > strawberryCounter) {
			printf("Vanilla\n");
		} else if (chocolateCounter == strawberryCounter && chocolateCounter > vanillaCounter) {
			printf("Chocolate\n");
			printf("Strawberry\n");
		} else if (chocolateCounter == vanillaCounter && chocolateCounter > strawberryCounter) {
			printf("Chocolate\n");
			printf("Vanilla\n");
		} else if (vanillaCounter == strawberryCounter && vanillaCounter > chocolateCounter) {
			printf("Vanilla\n");
			printf("Stawberry\n");
		} else {
			printf("Chocolate\n");
			printf("Vanilla\n");
			printf("Stawberry\n");
		}
	}
}
