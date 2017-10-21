#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define alpha 0.125
#define beta 0.25

double abs(double value)
{
	if (value)
		return value;
	else
		return - value;
}

int main()
{
	int SRTT[110];
	double ERTT[110];

	srand((unsigned)time(NULL));

	for (int i = 0; i < 100; i++)
		SRTT[i] = (rand() % 300) + 1;
	
	ERTT[0] = (double)SRTT[0];

	for (int i = 1; i < 100; i++)
		ERTT[i] = (1 - alpha) * ERTT[i - 1] + (alpha) * (double)SRTT[i];

	printf("\tSRTT\tERTT\n");

	for (int i = 0; i < 100; i++)
		printf("%d\t%d\t%lf\n", i + 1, SRTT[i], ERTT[i]);

	double DevRTT[110];

	DevRTT[0] = beta * abs(SRTT[0] - ERTT[0]);

	for (int i = 1; i < 100; i++)
		DevRTT[i] = (1 - beta) * DevRTT[i - 1] + beta * abs(SRTT[i] - ERTT[i]);

	int Timeout_interval[110];

	for (int i = 0; i < 100; i++)
		Timeout_interval[i] = ERTT[i] + 4 * DevRTT[i];
}
