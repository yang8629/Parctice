
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>





int main() {

	int arr[] = { 5,3,8,6,2,7,1,4 };
	//std::vector<int> array(arr, arr + sizeof(arr) / sizeof(int));
	int aftermerge[8];

	printf("original:\n");
	//PrintArray(arr);
	for (int i = 0; i < 8; i++) {
		printf(arr[i]);
		printf(" ");
	}
	//MergeSort(array, 0, 7);
	printf("sorted:\n");
//	PrintArray(&aftermerge);

	return 0;
}