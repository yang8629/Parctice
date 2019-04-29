#include <stdio.h>
#include <stdlib.h>
#define size 8

void InsertionSort(int arr[]) {
	for (int i = 0; i < size; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

void PrintArray(int buffer[]) {
	for (int i = 0; i < size; i++) {
		printf(" %d ",buffer[i]);
	}
	putchar('\n');
	putchar('\n');
}

int main() {	
	int arr[8] = { 2,7,5,4,3,1,8,6 };

	printf("original:\n");
	PrintArray(arr);	
	InsertionSort(arr);

	printf("sorted:\n");
	PrintArray(arr);

	system("pause");
	return 0;
}