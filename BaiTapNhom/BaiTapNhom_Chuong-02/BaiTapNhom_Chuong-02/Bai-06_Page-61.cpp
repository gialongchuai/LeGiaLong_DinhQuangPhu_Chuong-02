/*
	Cho mảng một chiều các số nguyên a. Hãy thực hiện các
	yêu cầu sau:
	1. Kiểm tra mảng có chứa toàn bộ số nguyên tố hay không?
	2. Kiểm tra mảng có đối xứng hay không?
	3. Kiểm tra mảng có tăng dần/giảm dần/không tăng không
	giảm?
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Ham kiem tra so nguyen to
bool laSoNguyenTo(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// Ham kiem tra mang co chua toan bo so nguyen to hay khong
bool kiemTraMangSoNguyenTo(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (!laSoNguyenTo(a[i])) return false;
	}
	return true;
}

// Ham kiem tra mang doi xung
bool kiemTraMangDoiXung(int a[], int n) {
	for (int i = 0; i < n / 2; i++) {
		if (a[i] != a[n - i - 1]) return false;
	}
	return true;
}

// Ham kiem tra mang tang dan
bool kiemTraTangDan(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

// Ham kiem tra mang giam dan
bool kiemTraGiamDan(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] < a[i + 1]) return false;
	}
	return true;
}

// Ham kiem tra mang khong tang khong giam
bool kiemTraKhongTangKhongGiam(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

int main() {
	int choice;
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);

	// Cap phat bo nho cho mang
	int *a = (int*)malloc(n * sizeof(int));
	if (a == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return 1;
	}

	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}

	do {
		printf("\n--- Menu ---\n");
		printf("1. Kiem tra mang co chua toan bo so nguyen to hay khong?\n");
		printf("2. Kiem tra mang co doi xung hay khong?\n");
		printf("3. Kiem tra mang co tang dan/giam dan/khong tang khong giam?\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			if (kiemTraMangSoNguyenTo(a, n)) {
				printf("Mang chua toan bo so nguyen to.\n");
			}
			else {
				printf("Mang khong chua toan bo so nguyen to.\n");
			}
			break;
		case 2:
			if (kiemTraMangDoiXung(a, n)) {
				printf("Mang doi xung.\n");
			}
			else {
				printf("Mang khong doi xung.\n");
			}
			break;
		case 3:
			if (kiemTraTangDan(a, n)) {
				printf("Mang tang dan.\n");
			}
			else if (kiemTraGiamDan(a, n)) {
				printf("Mang giam dan.\n");
			}
			else if (kiemTraKhongTangKhongGiam(a, n)) {
				printf("Mang khong tang khong giam.\n");
			}
			else {
				printf("Mang khong tang khong giam va khong giam khong tang.\n");
			}
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long nhap lai.\n");
		}
	} while (choice != 0);

	// Giai phong bo nho
	free(a);

	return 0;
}
