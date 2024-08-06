/*
	Cho ma trận vuông n. Viết các hàm sau:
	Bài 1: Tính tổng các phần tử nằm trên đường chéo chính.
	Bài 2: Tính tổng các phần tử nằm trên đường chéo phụ.
	Bài 3: Tính tổng các phần tử nằm phía trên đường chéo chính.
	Bài 4: Tính tổng các phần tử nằm phía trên đường chéo phụ.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Hàm tính tổng các phần tử nằm trên đường chéo chính
int tinhTongDuongCheoChinh(int maTran[MAX_SIZE][MAX_SIZE], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += maTran[i][i];
	}
	return tong;
}

// Hàm tính tổng các phần tử nằm trên đường chéo phụ
int tinhTongDuongCheoPhu(int maTran[MAX_SIZE][MAX_SIZE], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += maTran[i][n - 1 - i];
	}
	return tong;
}

// Hàm tính tổng các phần tử nằm phía trên đường chéo chính
int tinhTongTrenDuongCheoChinh(int maTran[MAX_SIZE][MAX_SIZE], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			tong += maTran[i][j];
		}
	}
	return tong;
}

// Hàm tính tổng các phần tử nằm phía trên đường chéo phụ
int tinhTongTrenDuongCheoPhu(int maTran[MAX_SIZE][MAX_SIZE], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			tong += maTran[i][j];
		}
	}
	return tong;
}

// Hàm chính
int main() {
	int n;
	int maTran[MAX_SIZE][MAX_SIZE];

	printf("Nhap kich thuoc ma tran vuong (n): ");
	scanf("%d", &n);

	printf("Nhap ma tran:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("maTran[%d][%d] = ", i, j);
			scanf("%d", &maTran[i][j]);
		}
	}

	printf("Tong duong cheo chinh: %d\n", tinhTongDuongCheoChinh(maTran, n));
	printf("Tong duong cheo phu: %d\n", tinhTongDuongCheoPhu(maTran, n));
	printf("Tong phia tren duong cheo chinh: %d\n", tinhTongTrenDuongCheoChinh(maTran, n));
	printf("Tong phia tren duong cheo phu: %d\n", tinhTongTrenDuongCheoPhu(maTran, n));

	system("pause");
	return 0;
}
