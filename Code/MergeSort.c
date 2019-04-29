#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int Max = 100000;
/**
* �X�ֱƧǪk�]Merge Sort�^�A���j�����C
*/
void Merge(int Array[], int front, int mid, int end) {

	int left = mid - front + 2;
	int right = end - mid + 1;
	int *leftarr;
	leftarr = (int*)malloc(sizeof(int)*left);
	int *rightarr;
	rightarr = (int*)malloc(sizeof(int)*right);
	
	for (int i = front; i <= mid; i++)     // ��array[front]~array[mid]��i leftarr[]
	{
		leftarr[i - front] = Array[i];
	}
	leftarr[(left - 1)] = Max;      // �bLeftSub[]���ݥ[�J�Ȭ� Max ������
	for (int i = mid + 1; i <= end; i++)
	{
		rightarr[i - mid - 1] = Array[i];	// ��array[mid+1]~array[end]��i rightarr[]
	}
	rightarr[(right - 1)] = Max;    // �bRightSub[]���ݥ[�J�Ȭ� Max ������

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

void MergeSort(int arr[], int front, int end) {	// front�Pend���x�}�d��
	if (front < end) {                   // ��ܥثe���x�}�d��O���Ī�
		int mid = (front + end) / 2;         // mid�Y�O�N�x�}��b����index
		MergeSort(arr, front, mid);    // �~��divide�x�}���e�b�qsubarray
		MergeSort(arr, mid + 1, end);    // �~��divide�x�}����b�qsubarray
		//printf(" %d ��\n", end - front + 1);
		Merge(arr, front, mid, end);   // �N���subarray�����, �æX�֥X�Ƨǫ᪺�x�}
	}
}

/**
* �X�ֱƧǪk�]Merge Sort�^�A���N�����C
*/
void mergeSortIterative(int arr[],int x) {
	int length = x;
	int *temp;
	temp = (int*)malloc(sizeof(int)*x);
	for (int i = 1; i < length; i *= 2) {
		int ii = i * 2;
		int maxlength = length - i;  //��arr[mid]���|����O���a��
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

	do                                                 //�Q��scanf()�P�w��J�O�_���Ʀr
	{
		right = scanf("%d", &amount);
		if (right != 1)
		{
			printf("��J���~!!\n");
		}
		else
		{
			printf("%d \n", amount);
			break;
		}
		rewind(stdin);
		amount = 0;
	}while(1);
	
	/*while ((c = getchar()) != NULL && c != EOF) {       //�Q��getchar()�P�w��J�O�_���Ʀr
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
			printf("��J���~!!\n");
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

	/*���j����*/
	MergeSort(arr, 0, amount-1);
	/*���N����*/
	//mergeSortIterative(arr, amount);

	printf("sorted:\n");
	PrintArray(arr, amount);

	free(arr);
	system("pause");
	return 0;
}