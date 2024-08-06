/*
	Cho mảng 1 chiều a chứa n số nguyên. Viết chương trình thực
	hiện các yêu cầu sau:
	1. Viết hàm nhập/xuất mảng a.
	2. Tìm max/min của a.
	3. Đếm số phần tử chẵn/lẻ trong a.
	4. Tìm kiếm phần tử x trong a theo 2 dạng (trả về vị trí/xuất câu
	thông báo) với giải thuật tìm kiếm tuyến tính/ tìm kiếm nhị
	phân.
	5. Đếm trên a có bao nhiêu phần tử x (x nhập từ bàn phím).
	6. Đếm trên a có bao nhiêu phần tử lớn hơn x.
	7. Tính tổng các phần tử của a.
	8. Xuất các số nguyên tố trong a.
	9. Xuất các số hoàn thiện trong a.
	10.Xuất các phần tử ở vị trí chẵn/ vị trí lẻ trong a.
	11.Xuất giá trị max/min kèm theo vị trí của giá trị đó trong mảng a.
	12.Cho 2 dãy số tăng dần: dãy b có m phần tử và dãy c có n phần
	tử. Ghép b và c thành dãy a được xếp tăng dần.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void nhapMang(int a[], int *n) {
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", n);
	for (int i = 0; i < *n; i++) {
		printf("Nhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}

void xuatMang(int a[], int n) {
	printf("Mang: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int timMax(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

int timMin(int a[], int n) {
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}


void demChanLe(int a[], int n, int *chan, int *le) {
	*chan = 0;
	*le = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			(*chan)++;
		}
		else {
			(*le)++;
		}
	}
}

int timKiemTuyenTinh(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

int binarySearch(int arr[], int left, int right, int x) {
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == x) {
			return mid;
		}

		if (arr[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}


int main() {
	int a[MAX], b[MAX], c[MAX];
	int n, m;
	int choice;
	int x;
	int result;
	int chan, le;

	while (1) {
		printf("\nMenu:\n");
		printf("1. Nhap/xuat mang a\n");
		printf("2. Tim max/min cua a\n");
		printf("3. Dem so phan tu chan/le trong a\n");
		printf("4. Tim kiem phan tu x trong a\n");
		printf("5. Dem so phan tu x trong a\n");
		printf("6. Dem so phan tu lon hon x\n");
		printf("7. Tinh tong cac phan tu cua a\n");
		printf("8. Xuat cac so nguyen to trong a\n");
		printf("9. Xuat cac so hoan thien trong a\n");
		printf("10. Xuat cac phan tu o vi tri chan/le trong a\n");
		printf("11. Xuat gia tri max/min kem theo vi tri cua no trong a\n");
		printf("12. Ghep 2 day so tang dan b va c thanh day a tang dan\n");
		printf("0. Thoat\n");
		printf("Chon: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			nhapMang(a, &n);
			xuatMang(a, n);
			break;
		case 2:
			printf("Max cua a: %d\n", timMax(a, n));
			printf("Min cua a: %d\n", timMin(a, n));
			break;
		case 3:
			demChanLe(a, n, &chan, &le);
			printf("So phan tu chan: %d\n", chan);
			printf("So phan tu le: %d\n", le);
			break;
		case 4:
			printf("Nhap gia tri x can tim: ");
			scanf("%d", &x);
			printf("1. Tim kiem tuyen tinh\n");
			printf("2. Tim kiem nhi phan\n");
			int searchType;
			scanf("%d", &searchType);
			if (searchType == 1) {
				result = timKiemTuyenTinh(a, n, x);
			}
			else if (searchType == 2) {
				result = binarySearch(a, 0, n - 1, x);
			}
			else {
				printf("Lua chon khong hop le\n");
				break;
			}
			if (result != -1) {
				printf("Gia tri %d duoc tim thay tai vi tri %d\n", x, result);
			}
			else {
				printf("Khong tim thay gia tri %d trong mang\n", x);
			}
			break;
		case 0:
			exit(0);
		default:
			printf("Lua chon khong hop le\n");
		}
	}

	return 0;
}
