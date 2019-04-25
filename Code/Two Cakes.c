#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *tiers;
	int ntier, Adis = 0, Bdis = 0, a = 0, b = 0;

	while (1)
	{
		if (scanf("%d", &ntier))
		{
			rewind(stdin);
			break;
		}
		rewind(stdin);
	}
	//ntier *= 2;
	tiers = (int*)malloc(sizeof(int)*ntier * 2);

	for (int i = 0; i < ntier * 2; i++)
	{
		scanf("%d", &tiers[i]);
	}

	for (int i = 1; i <= ntier; i++)
	{
		int x = 0, y = 0, time = 0, move = 0;
		for (int j = 0; j < ntier * 2; j++)
		{
			if (tiers[j] == i)
			{
				if (time == 0)
				{
					x = j - a;
					//printf("%d\n", x);
				}
				else if (time == 1)
				{
					y = j - a;
					//printf("j: %d\n", j);
					//printf("time: %d\n", time);
					//printf("%d\n", y);
				}
				time++;				
			}
			if (time == 2)
			{
				move = abs(x) > abs(y) ? y : x;
				Adis += abs(move);
				a += move;
				tiers[a] = 0;
				break;
			}
		}
	}

	for (int i = 1; i <= ntier; i++)
	{
		for (int j = 0; j < ntier * 2; j++)
		{
			int x = 0;
			if (tiers[j] == i)
			{
				x = j - b;
				Bdis += abs(x);
				b += x;
				tiers[b] = 0;
				break;
			}
		}
	}
	printf("%d %d\n", Adis, Bdis);
	printf("%d\n", Adis + Bdis);	
	free(tiers);
	system("pause");
	return 0;
}