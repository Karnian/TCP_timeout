#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int SRTT[110];
	double ERTT[110];

	srand((unsigned)time(NULL));

	for (int i = 0; i < 100; i++)
		SRTT[i] = (rand() % 300) + 1;
	
	ERTT[0] = (double)SRTT[0];

	for (int i = 1; i < 100; i++)
		ERTT[i] = (0.875) * ERTT[i - 1] + (0.125) * (double)SRTT[i];

	printf("\tSRTT\tERTT\n");

	for (int i = 0; i < 100; i++)
		printf("%d\t%d\t%lf\n", i + 1, SRTT[i], ERTT[i]);

	double DevRTT[110];


}
