/*
	Bài tập:
	1. Đếm số phần tử có giá trị là số nguyên tố trong mảng a
	2. Xuất các phần tử mà từng chữ số của nó là số lẻ.
	3. Tìm vị trí số lớn nhất (cuối cùng) của mảng, nghĩa là nếu
	trong mảng có nhiều phần tử là số lớn nhất thì xuất vị trí số
	cuối cùng.
	4. Kiểm tra mảng có toàn là số chẵn không?
	5. Kiểm tra mảng có phải là dãy số chẵn lẻ xen kẻ không?
*/

#include <stdio.h>
#include <stdbool.h>

// Kiem tra so nguyen to
bool laSoNguyenTo(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// Dem so phan tu co gia tri la so nguyen to
int demSoNguyenTo(int a[], int n) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (laSoNguyenTo(a[i])) dem++;
	}
	return dem;
}


int main() {
	int a[100];
	int n, choice;

	printf("Nhap so luong phan tu cua mang: ");
	scanf("%d", &n);

	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	do {
		printf("\nMenu:\n");
		printf("1. Dem so phan tu co gia tri la so nguyen to trong mang a\n");
		printf("2. Xuat cac phan tu ma tung chu so cua no la so le\n");
		printf("3. Tim vi tri so lon nhat (cuoi cung) cua mang\n");
		printf("4. Kiem tra mang co toan la so chan khong\n");
		printf("5. Kiem tra mang co phai la day so chan le xen ke khong\n");
		printf("0. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("So phan tu la so nguyen to: %d\n", demSoNguyenTo(a, n));
			break;
		
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (choice != 0);

	return 0;
}
