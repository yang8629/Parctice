#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
void main(void)
{
	char ch; int ix = 0;
	printf("��J�@�Ӿ��:"); scanf("%d", &ix);
	rewind(stdin); // �M����J�w�İϪ����e
	printf("��J�@�Ӧr��:"); ch = getchar();
	printf("ch = %d, ix = %d\n", ch, ix);
	system("pause");
}
