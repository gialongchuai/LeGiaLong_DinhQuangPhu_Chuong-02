/*
	Cho mảng hai chiều các số nguyên a có m hàng và n cột. Hãy thực
	hiện các yêu cầu sau:
	Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ.
	Bài 2: Liệt kê các số hoàn thiện trong ma trận.
	Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó.
	Bài 4: Tính tổng giá trị trên dòng k của ma trận.
	Bài 5: Tính tổng các giá trị nằm trên biên của ma trận.
	Bài 6: Đếm tần suất xuất hiện của 1 giá trị x trong ma trận.
	Bài 7: Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số
	nguyên tố.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_M 100
#define MAX_N 100

// Kiem tra so nguyen to
bool laNguyenTo(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt((double)n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// Kiem tra so hoan thien
bool laSoHoanThien(int n) {
	int tong = 0;
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			tong += i;
		}
	}
	return tong == n;
}

// Tinh tong cac phan tu co chu so dau la chu so le
int tongChuSoLe(int m, int n, int a[MAX_M][MAX_N]) {
	int tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int so = a[i][j];
			int chuSoDau = abs(so);
			while (chuSoDau >= 10) {
				chuSoDau /= 10;
			}
			if (chuSoDau % 2 != 0) {
				tong += so;
			}
		}
	}
	return tong;
}

// Liet ke cac so hoan thien
void lietKeSoHoanThien(int m, int n, int a[MAX_M][MAX_N]) {
	printf("Cac so hoan thien trong ma tran:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (laSoHoanThien(a[i][j])) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Tinh tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau
int tongLonHonTriTuyetDoi(int m, int n, int a[MAX_M][MAX_N]) {
	int tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[i][j] > abs(a[i][j + 1])) {
				tong += a[i][j];
			}
		}
	}
	return tong;
}

// Tinh tong gia tri tren dong k
int tongDongK(int m, int n, int a[MAX_M][MAX_N], int k) {
	int tong = 0;
	for (int j = 0; j < n; j++) {
		tong += a[k][j];
	}
	return tong;
}

// Tinh tong cac gia tri nam tren bien cua ma tran
int tongBien(int m, int n, int a[MAX_M][MAX_N]) {
	int tong = 0;
	for (int j = 0; j < n; j++) {
		tong += a[0][j] + a[m - 1][j];
	}
	for (int i = 1; i < m - 1; i++) {
		tong += a[i][0] + a[i][n - 1];
	}
	return tong;
}

// Dem tan suat xuat hien cua x trong ma tran
int demTanSuat(int m, int n, int a[MAX_M][MAX_N], int x) {
	int dem = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == x) {
				dem++;
			}
		}
	}
	return dem;
}

// Dem so luong cac phan tu
void demPhanTu(int m, int n, int a[MAX_M][MAX_N]) {
	int chan = 0, le = 0, am = 0, duong = 0, nguyenTo = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int x = a[i][j];
			if (x % 2 == 0) {
				chan++;
			}
			else {
				le++;
			}
			if (x < 0) {
				am++;
			}
			else if (x > 0) {
				duong++;
			}
			if (laNguyenTo(x)) {
				nguyenTo++;
			}
		}
	}
	printf("So luong so chan: %d\n", chan);
	printf("So luong so le: %d\n", le);
	printf("So luong so am: %d\n", am);
	printf("So luong so duong: %d\n", duong);
	printf("So luong so nguyen to: %d\n", nguyenTo);
}

int main() {
	int m, n;
	int a[MAX_M][MAX_N];

	// Nhap so hang va so cot
	printf("Nhap so hang (m) va so cot (n): ");
	scanf("%d %d", &m, &n);

	// Nhap ma tran
	printf("Nhap ma tran %d x %d:\n", m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	// Thuc hien cac bai tap
	printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tongChuSoLe(m, n, a));

	lietKeSoHoanThien(m, n, a);

	printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau: %d\n", tongLonHonTriTuyetDoi(m, n, a));

	int k;
	printf("Nhap dong k de tinh tong: ");
	scanf("%d", &k);
	printf("Tong gia tri tren dong %d: %d\n", k, tongDongK(m, n, a, k));

	printf("Tong cac gia tri nam tren bien cua ma tran: %d\n", tongBien(m, n, a));

	int x;
	printf("Nhap gia tri x de dem tan suat: ");
	scanf("%d", &x);
	printf("Tan suat xuat hien cua %d: %d\n", x, demTanSuat(m, n, a, x));

	demPhanTu(m, n, a);

	return 0;
}
