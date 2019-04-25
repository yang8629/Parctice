#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a, b;
	int count = 0, draw = 1, x = 0, y = 0, n = 0;
	while (1)
	{
		if (scanf("%d", &n))
		{
			break;
		}
		rewind(stdin);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		while (x != a || y != b)
		{
			if (x != a && x <= y)
			{
				x++;
			}
			else if (y < b)
			{
				y++;
			}
			else
			{
				x++;
			}
			if (x == y)
			{
				draw++;
			}
		}
	}
	printf("%d\n", draw);
	//system("pause");
	return 0;
}