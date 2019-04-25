#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int t = 0, n, a = 0, b = 0, buy = 0, now = 0, buffer = 0;
	while (1)
	{
		if (scanf("%d", &n))
		{
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if (now == 0)
		{
			now = t;
		}
		if (t == now)
		{
			if (t == 1)
			{
				a++;
			}
			else
			{
				b++;
			}
		}		
		else
		{
			now = t;
			if (t == 1)
			{
				a = 1;
			}
			else
			{
				b = 1;
			}
		}
		buffer = a < b ? a : b;
		buy = buy < buffer ? buffer : buy;
	}
	buy = buy * 2;
	printf("%d\n", buy);

	//system("pause");
	return 0;
}