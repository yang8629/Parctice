#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int tiers[100500][2] = { 0 };
	long long int  Adis = 0, Bdis = 0, a = 1, b = 1, ntier, buffer;
	while (1)
	{
		if (scanf("%lld", &ntier))
		{
			break;
		}
		rewind(stdin);
	}

	for (long long int i = 1; i <= ntier * 2; i++)
	{
		scanf("%lld", &buffer);
		if (tiers[buffer][0] == 0)
		{
			tiers[buffer][0] = i;
		}
		else
		{
			tiers[buffer][1] = i;
		}
	}

	for (int i = 1; i <= ntier; i++)
	{
		Adis += abs(tiers[i][0] - a);
		a = tiers[i][0];
		Bdis += abs(tiers[i][1] - b);
		b = tiers[i][1];
	}

	printf("%lld\n", Adis + Bdis);	
	//system("pause");
	return 0;
}