/*
	Cho mảng hai chiều các số nguyên a có n hàng và m cột. Hãy
	thực hiện các yêu cầu sau:
	Bài 1: Sắp xếp các phần tử trong ma trận sao cho dòng chẵn
	tăng dòng lẻ giảm.
	Bài 2: Sắp xếp các phần tử trong ma trận sao cho cột chẵn
	tăng cột lẻ giảm.
	Bài 3: Sắp xếp ma trận tăng dần/giảm dần theo zic-zac.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortRow(int arr[MAX][MAX], int n, int m, int row, int ascending) {
	int start = (ascending) ? 0 : m - 1;
	int end = (ascending) ? m - 1 : 0;
	int step = (ascending) ? 1 : -1;

	for (int i = start; i != end; i += step) {
		for (int j = i + step; j != end + step; j += step) {
			if ((ascending && arr[row][i] > arr[row][j]) || (!ascending && arr[row][i] < arr[row][j])) {
				swap(&arr[row][i], &arr[row][j]);
			}
		}
	}
}

void sortColumn(int arr[MAX][MAX], int n, int m, int col, int ascending) {
	int start = (ascending) ? 0 : n - 1;
	int end = (ascending) ? n - 1 : 0;
	int step = (ascending) ? 1 : -1;

	for (int i = start; i != end; i += step) {
		for (int j = i + step; j != end + step; j += step) {
			if ((ascending && arr[i][col] > arr[j][col]) || (!ascending && arr[i][col] < arr[j][col])) {
				swap(&arr[i][col], &arr[j][col]);
			}
		}
	}
}

void sortMatrixZigzag(int arr[MAX][MAX], int n, int m, int ascending) {
	for (int i = 0; i < n; i++) {
		int start = (i % 2 == 0) ? 0 : m - 1;
		int end = (i % 2 == 0) ? m - 1 : 0;
		int step = (i % 2 == 0) ? 1 : -1;

		for (int j = start; j != end; j += step) {
			for (int k = j + step; k != end + step; k += step) {
				if ((ascending && arr[i][j] > arr[i][k]) || (!ascending && arr[i][j] < arr[i][k])) {
					swap(&arr[i][j], &arr[i][k]);
				}
			}
		}
	}
}

void printMatrix(int arr[MAX][MAX], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int arr[MAX][MAX];
	int n, m, choice;

	printf("Nhap so hang (n): ");
	scanf("%d", &n);
	printf("Nhap so cot (m): ");
	scanf("%d", &m);

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}

	printf("Chon bai toan (1, 2, 3): ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		for (int i = 0; i < n; i++) {
			sortRow(arr, n, m, i, i % 2 == 0);
		}
		printf("Ma tran sau khi sap xep:\n");
		printMatrix(arr, n, m);
		break;

	case 2:
		for (int j = 0; j < m; j++) {
			sortColumn(arr, n, m, j, j % 2 == 0);
		}
		printf("Ma tran sau khi sap xep:\n");
		printMatrix(arr, n, m);
		break;

	case 3:
		sortMatrixZigzag(arr, n, m, 1);
		printf("Ma tran sau khi sap xep theo zic-zac tang dan:\n");
		printMatrix(arr, n, m);
		break;

	default:
		printf("Lua chon khong hop le.\n");
		break;
	}
	system("pause");
	return 0;
}
