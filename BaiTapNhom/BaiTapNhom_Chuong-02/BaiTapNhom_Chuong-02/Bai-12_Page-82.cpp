/*
	Cho mảng hai chiều các số nguyên a có m hàng và n cột. Hãy thực hiện
	các yêu cầu sau:
	Bài 1: Liệt kê các cột có tổng nhỏ nhất trong ma trận.
	Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất trong ma trận.
	Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn.
	Bài 4: Tìm giá trị xuất hiện nhiều nhất trong ma trận.
	Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận.
	Bài 6: Tìm phần tử lớn (nhỏ) nhất trong dòng thứ k.
	Bài 7: Tìm phần tử lớn (nhỏ) nhất trong cột thứ k.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
	if (num <= 1) return false;
	if (num <= 3) return true;
	if (num % 2 == 0 || num % 3 == 0) return false;
	for (int i = 5; i * i <= num; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) return false;
	}
	return true;
}

// Hàm tìm giá trị xuất hiện nhiều nhất
int findMostFrequent(int arr[], int size) {
	int maxCount = 0, mostFreq = arr[0];
	for (int i = 0; i < size; i++) {
		int count = 0;
		for (int j = 0; j < size; j++) {
			if (arr[j] == arr[i]) count++;
		}
		if (count > maxCount) {
			maxCount = count;
			mostFreq = arr[i];
		}
	}
	return mostFreq;
}

void printColumnWithMinSum(int **matrix, int m, int n) {
	int minSum = INT_MAX;
	for (int j = 0; j < n; j++) {
		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum += matrix[i][j];
		}
		if (sum < minSum) {
			minSum = sum;
		}
	}
	printf("Cac cot co tong nho nhat: ");
	for (int j = 0; j < n; j++) {
		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum += matrix[i][j];
		}
		if (sum == minSum) {
			printf("%d ", j);
		}
	}
	printf("\n");
}

void printRowsWithMostPerfectNumbers(int **matrix, int m, int n) {
	int maxPerfectCount = 0;
	int *perfectCount = (int *)calloc(m, sizeof(int));

	for (int i = 0; i < m; i++) {
		perfectCount[i] = 0;
		for (int j = 0; j < n; j++) {
			int num = matrix[i][j];
			bool isPerfect = true;
			if (num < 1) isPerfect = false;
			for (int k = 1; k <= num / 2; k++) {
				if (num % k == 0) {
					if (k == num) {
						isPerfect = false;
						break;
					}
				}
			}
			if (isPerfect) {
				perfectCount[i]++;
			}
		}
		if (perfectCount[i] > maxPerfectCount) {
			maxPerfectCount = perfectCount[i];
		}
	}

	printf("Cac dong co nhieu so hoan thien nhat: ");
	for (int i = 0; i < m; i++) {
		if (perfectCount[i] == maxPerfectCount) {
			printf("%d ", i);
		}
	}
	printf("\n");
	free(perfectCount);
}

void printRowsWithAllEven(int **matrix, int m, int n) {
	printf("Cac dong chua toan gia tri chan: ");
	for (int i = 0; i < m; i++) {
		bool allEven = true;
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] % 2 != 0) {
				allEven = false;
				break;
			}
		}
		if (allEven) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

void findMostFrequentValue(int **matrix, int m, int n) {
	int flatSize = m * n;
	int *flat = (int *)malloc(flatSize * sizeof(int));
	int index = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			flat[index++] = matrix[i][j];
		}
	}

	int mostFreq = findMostFrequent(flat, flatSize);
	printf("Gia tri xuat hien nhieu nhat: %d\n", mostFreq);
	free(flat);
}

void findSmallestPrime(int **matrix, int m, int n) {
	int smallestPrime = INT_MAX;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int num = matrix[i][j];
			if (isPrime(num) && num < smallestPrime) {
				smallestPrime = num;
			}
		}
	}
	if (smallestPrime == INT_MAX) {
		printf("Khong co so nguyen to trong ma tran.\n");
	}
	else {
		printf("So nguyen to nho nhat: %d\n", smallestPrime);
	}
}

void findMinMaxInRow(int **matrix, int m, int n, int k) {
	if (k < 0 || k >= m) {
		printf("Chi so dong khong hop le.\n");
		return;
	}
	int min = matrix[k][0];
	int max = matrix[k][0];
	for (int j = 1; j < n; j++) {
		if (matrix[k][j] < min) min = matrix[k][j];
		if (matrix[k][j] > max) max = matrix[k][j];
	}
	printf("Trong dong %d, phan tu nho nhat la %d va phan tu lon nhat la %d.\n", k, min, max);
}

void findMinMaxInColumn(int **matrix, int m, int n, int k) {
	if (k < 0 || k >= n) {
		printf("Chi so cot khong hop le.\n");
		return;
	}
	int min = matrix[0][k];
	int max = matrix[0][k];
	for (int i = 1; i < m; i++) {
		if (matrix[i][k] < min) min = matrix[i][k];
		if (matrix[i][k] > max) max = matrix[i][k];
	}
	printf("Trong cot %d, phan tu nho nhat la %d va phan tu lon nhat la %d.\n", k, min, max);
}

int main() {
	int m, n;
	printf("Nhap so dong (m): ");
	scanf("%d", &m);
	printf("Nhap so cot (n): ");
	scanf("%d", &n);

	// Cấp phát bộ nhớ cho ma trận
	int **matrix = (int **)malloc(m * sizeof(int *));
	for (int i = 0; i < m; i++) {
		matrix[i] = (int *)malloc(n * sizeof(int));
	}

	printf("Nhap ma tran:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	printColumnWithMinSum(matrix, m, n);
	printRowsWithMostPerfectNumbers(matrix, m, n);
	printRowsWithAllEven(matrix, m, n);

	findMostFrequentValue(matrix, m, n);
	findSmallestPrime(matrix, m, n);

	int k;
	printf("Nhap chi so dong (k) de tim min/max: ");
	scanf("%d", &k);
	findMinMaxInRow(matrix, m, n, k);

	printf("Nhap chi so cot (k) de tim min/max: ");
	scanf("%d", &k);
	findMinMaxInColumn(matrix, m, n, k);

	// Giải phóng bộ nhớ
	for (int i = 0; i < m; i++) {
		free(matrix[i]);
	}
	free(matrix);

	system("pause");
	return 0;
}
