#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main() {
	int w1, h1, w2, h2;
	int mark = 0;
	scanf("%d %d %d %d", &w1, &h1, &w2, &h2);
	mark = (w1 + 2)*(h1 + 2) - w1 * h1 + h2 * 2;
	printf("%d\n", mark);
	//system("pause");
	return 0;
}
