#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int Max = 100000;
/**
* 合併排序法（Merge Sort），遞迴版本。
*/
void Merge(int Array[], int front, int mid, int end) {

	int left = mid - front + 2;
	int right = end - mid + 1;
	int *leftarr;
	leftarr = (int*)malloc(sizeof(int)*left);
	int *rightarr;
	rightarr = (int*)malloc(sizeof(int)*right);
	
	for (int i = front; i <= mid; i++)     // 把array[front]~array[mid]放進 leftarr[]
	{
		leftarr[i - front] = Array[i];
	}
	leftarr[(left - 1)] = Max;      // 在LeftSub[]尾端加入值為 Max 的元素
	for (int i = mid + 1; i <= end; i++)
	{
		rightarr[i - mid - 1] = Array[i];	// 把array[mid+1]~array[end]放進 rightarr[]
	}
	rightarr[(right - 1)] = Max;    // 在RightSub[]尾端加入值為 Max 的元素

	int idxLeft = 0, idxRight = 0;

	for (int i = front; i <= end; i++) {

		if (leftarr[idxLeft] <= rightarr[idxRight]) {
			Array[i] = leftarr[idxLeft];
			idxLeft++;
		}
		else {
			Array[i] = rightarr[idxRight];
			idxRight++;
		}
		//printf(" %d ", Array[i]);
	}
	//printf('\n\n');
	free(leftarr);
	free(rightarr);
}

void MergeSort(int arr[], int front, int end) {	// front與end為矩陣範圍
	if (front < end) {                   // 表示目前的矩陣範圍是有效的
		int mid = (front + end) / 2;         // mid即是將矩陣對半分的index
		MergeSort(arr, front, mid);    // 繼續divide矩陣的前半段subarray
		MergeSort(arr, mid + 1, end);    // 繼續divide矩陣的後半段subarray
		//printf(" %d 個\n", end - front + 1);
		Merge(arr, front, mid, end);   // 將兩個subarray做比較, 並合併出排序後的矩陣
	}
}

/**
* 合併排序法（Merge Sort），迭代版本。
*/
void mergeSortIterative(int arr[],int x) {
	int length = x;
	int *temp;
	temp = (int*)malloc(sizeof(int)*x);
	for (int i = 1; i < length; i *= 2) {
		int ii = i * 2;
		int maxlength = length - i;  //讓arr[mid]不會指到別的地方
		for (int j = 0; j < maxlength; j += ii) {
			int end = j + ii;
			if (end > length) {
				end = length;
			}
			int front = j;
			int mid = front + i;
			int now = j;
			int rightfront = mid;
			while (front < mid && rightfront < end) {
				if (arr[front] - arr[rightfront] >= 0) {
					temp[now++] = arr[rightfront++];
				}
				else {
					temp[now++] = arr[front++];
				}
			}

			while (front < mid) {
				temp[now++] = arr[front++];
			}
			while (rightfront < end) {
				temp[now++] = arr[rightfront++];
			}
			for (int i = j; i < end; i++)
			{
				arr[i] = temp[i];
			}
		}
	}
	free(temp);
}

void PrintArray(int buffer[], int x) {
	for (int i = 0; i < x; i++) {
		printf(" %4d ",buffer[i]);
	}
	putchar('\n');
	putchar('\n');
}

void SetArray(int arr[],int x) {
	for (int i = 0; i < x; i++)
	{
		arr[i] = (int)rand() % 10000;
	}
}

int main() {	
	srand((unsigned)time(NULL));
	int *arr;
	int amount = 0;
	printf("%d \n", sizeof(int));
	int right;
	int c;
	int x = 0;
	int input[100];

	do                                                 //利用scanf()判定輸入是否為數字
	{
		right = scanf("%d", &amount);
		if (right != 1)
		{
			printf("輸入錯誤!!\n");
		}
		else
		{
			printf("%d \n", amount);
			break;
		}
		rewind(stdin);
		amount = 0;
	}while(1);
	
	/*while ((c = getchar()) != NULL && c != EOF) {       //利用getchar()判定輸入是否為數字
		if (c >= 48 && c <= 57)
		{
			printf("%d\n", c);
			input[x] = c - 48;
			x++;
		}
		else if (c == '\n')
		{
			break;
		}
		else
		{
			printf("輸入錯誤!!\n");
			while ((c = getchar()) != '\n' && c != EOF) {}
			x = 0;
			memset(input, 0, sizeof(input));
		}
	};
	for (int i = 0; i < x; i++)
	{
		amount += input[i] * pow(10, x-1);
		x--;
	}*/

	arr = (int*)malloc(sizeof(int)*amount);
	SetArray(arr, amount);

	printf("original:\n");
	PrintArray(arr, amount);

	/*遞迴版本*/
	MergeSort(arr, 0, amount-1);
	/*迭代版本*/
	//mergeSortIterative(arr, amount);

	printf("sorted:\n");
	PrintArray(arr, amount);

	free(arr);
	system("pause");
	return 0;
}