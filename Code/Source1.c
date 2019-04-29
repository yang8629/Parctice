#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
void main(void)
{
	char ch; int ix = 0;
	printf("輸入一個整數:"); scanf("%d", &ix);
	rewind(stdin); // 清除輸入緩衝區的內容
	printf("輸入一個字元:"); ch = getchar();
	printf("ch = %d, ix = %d\n", ch, ix);
	system("pause");
}
