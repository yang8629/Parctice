#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int length = 0;
	int *arr;
	int right = 1;
	int d = 0, countplus = 0, countminus = 0;
	scanf("%d", &length);
	arr = (int*)malloc(sizeof(int)*length);
	for (int i = 0; i < length; i++)
	{
		right = scanf("%d", &arr[i]);
		if (!right)
		{
			printf("¿é¤J¿ù»~");
			memset(arr, 0, length);
			break;
		}
	}
	rewind(stdin);
	d = (int)ceil((float)length / 2);
	for (int i = 0; i < length; i++)
	{
		if (arr[i] > 0)
		{
			countplus++;
		}
		else if (arr[i] < 0)
		{
			countminus++;
		}
	}
	if (countplus >= d)
	{
		printf("%d\n", d);
	}
	else if (countminus >= d)
	{
		printf("%d\n", -d);
	}
	else
	{
		printf("0\n");
	}
	free(arr);
	//system("pause");
	return 0;
}

