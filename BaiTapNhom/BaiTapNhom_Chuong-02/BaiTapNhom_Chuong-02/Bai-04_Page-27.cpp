/*
	Viết bổ sung các hàm vào chương trình xử lý mảng 1 chiều
	các hàm thực hiện những yêu cầu sau:
	1. Viết hàm sắp xếp tăng theo PP interchange sort cho dữ liệu số
	nguyên/số thực/ký tự/ chuỗi ký tự.
	2. Viết hàm sắp xếp giảm theo PP interchange sort cho dữ liệu số
	nguyên/số thực/ký tự/ chuỗi ký tự.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void interchangeSortAscendingInt(int arr[], int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void interchangeSortDescendingInt(int arr[], int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void displayIntArray(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void interchangeSortAscendingFloat(float arr[], int n) {
	int i, j;
	float temp;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}



void displayFloatArray(float arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%.2f ", arr[i]);
	}
	printf("\n");
}

int main() {
	int choice, n, i;
	int intArr[MAX];
	float floatArr[MAX];
	char charArr[MAX];
	char strArr[MAX][MAX];

	do {
		printf("===== MENU =====\n");
		printf("1. Sap xep tang theo PP interchange sort (So nguyen)\n");
		printf("2. Sap xep giam theo PP interchange sort (So nguyen)\n");
		printf("3. Sap xep tang theo PP interchange sort (So thuc)\n");
		printf("4. Sap xep giam theo PP interchange sort (So thuc)\n");
		printf("5. Sap xep tang theo PP interchange sort (Ky tu)\n");
		printf("6. Sap xep giam theo PP interchange sort (Ky tu)\n");
		printf("7. Sap xep tang theo PP interchange sort (Chuoi ky tu)\n");
		printf("8. Sap xep giam theo PP interchange sort (Chuoi ky tu)\n");
		printf("9. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Nhap so phan tu: ");
			scanf("%d", &n);
			printf("Nhap cac phan tu (so nguyen): ");
			for (i = 0; i < n; i++) {
				scanf("%d", &intArr[i]);
			}
			interchangeSortAscendingInt(intArr, n);
			printf("Mang sau khi sap xep tang: ");
			displayIntArray(intArr, n);
			break;
		case 2:
			printf("Nhap so phan tu: ");
			scanf("%d", &n);
			printf("Nhap cac phan tu (so nguyen): ");
			for (i = 0; i < n; i++) {
				scanf("%d", &intArr[i]);
			}
			interchangeSortDescendingInt(intArr, n);
			printf("Mang sau khi sap xep giam: ");
			displayIntArray(intArr, n);
			break;
		case 3:
			printf("Nhap so phan tu: ");
			scanf("%d", &n);
			printf("Nhap cac phan tu (so thuc): ");
			for (i = 0; i < n; i++) {
				scanf("%f", &floatArr[i]);
			}
			interchangeSortAscendingFloat(floatArr, n);
			printf("Mang sau khi sap xep tang: ");
			displayFloatArray(floatArr, n);
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
	} while (choice != 9);

	return 0;
}
