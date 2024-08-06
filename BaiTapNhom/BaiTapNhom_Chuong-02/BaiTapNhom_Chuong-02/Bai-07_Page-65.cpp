/*
	Khai báo cấu trúc phân số cần thiết lưu trữ thông tin phân
	số, sau đó thực hiện các chức năng:
	1. Viết hàm nhập vào phân số.
	2. Viết hàm xuất phân số.
	3. Kiểm tra phân số mẫu phải khác 0.
	4. Viết hàm tối giản phân số.
	5. Nhập vào 2 phân số. Tính tổng, hiệu, tích và thương của hai
	phân số.
*/

#include <stdio.h>

typedef struct {
	int tuSo;  // Tử số
	int mauSo; // Mẫu số
} PhanSo;

// Ham nhap phan so
void nhapPhanSo(PhanSo *ps) {
	printf("Nhap tu so: ");
	scanf("%d", &ps->tuSo);
	do {
		printf("Nhap mau so (khac 0): ");
		scanf("%d", &ps->mauSo);
		if (ps->mauSo == 0) {
			printf("Mau so phai khac 0. Vui long nhap lai.\n");
		}
	} while (ps->mauSo == 0);
}

// Ham xuat phan so
void xuatPhanSo(PhanSo ps) {
	printf("%d/%d\n", ps.tuSo, ps.mauSo);
}

// Ham toi gian phan so
void toiGian(PhanSo *ps) {
	int a = ps->tuSo;
	int b = ps->mauSo;
	int gcd, temp;

	// Tim uoc chung lon nhat
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	gcd = a;

	ps->tuSo /= gcd;
	ps->mauSo /= gcd;
}

// Ham tinh tong hai phan so
PhanSo tong(PhanSo ps1, PhanSo ps2) {
	PhanSo result;
	result.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
	result.mauSo = ps1.mauSo * ps2.mauSo;
	toiGian(&result);
	return result;
}

// Ham tinh hieu hai phan so
PhanSo hieu(PhanSo ps1, PhanSo ps2) {
	PhanSo result;
	result.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
	result.mauSo = ps1.mauSo * ps2.mauSo;
	toiGian(&result);
	return result;
}

int main() {
	PhanSo ps1, ps2;
	int luaChon;

	do {
		printf("\n----- MENU -----\n");
		printf("1. Nhap phan so 1\n");
		printf("2. Nhap phan so 2\n");
		printf("3. Xuat phan so 1\n");
		printf("4. Xuat phan so 2\n");
		printf("5. Tinh tong hai phan so\n");
		printf("6. Tinh hieu hai phan so\n");
		printf("7. Tinh tich hai phan so\n");
		printf("8. Tinh thuong hai phan so\n");
		printf("0. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &luaChon);

		switch (luaChon) {
		case 1:
			nhapPhanSo(&ps1);
			break;
		case 2:
			nhapPhanSo(&ps2);
			break;
		case 3:
			printf("Phan so 1: ");
			xuatPhanSo(ps1);
			break;
		case 4:
			printf("Phan so 2: ");
			xuatPhanSo(ps2);
			break;
		case 5:
			printf("Tong hai phan so: ");
			xuatPhanSo(tong(ps1, ps2));
			break;
		case 6:
			printf("Hieu hai phan so: ");
			xuatPhanSo(hieu(ps1, ps2));
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
	} while (luaChon != 0);

	return 0;
}
