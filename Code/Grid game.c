#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main() {
	char s[100] = { 0 };
	int i = 0, tileV = 0, tileH = 0;
	while ((s[i] = getchar()) != NULL && s[i] != EOF)
	{
		if (s[i] == 48)
		{
			printf("%d %d\n", 1, tileV % 4 + 1);
			tileV++;
			i++;
		}
		else if (s[i] == 49)
		{
			tileH++;
			printf("%d %d\n", 4, (tileH * 2 - 1) % 4);
			i++;
		}
		else
		{
			break;
		}
	}
	//scanf("%s", &s);
	//printf("%4s\n", s);
	//system("pause");
	return 0;
}