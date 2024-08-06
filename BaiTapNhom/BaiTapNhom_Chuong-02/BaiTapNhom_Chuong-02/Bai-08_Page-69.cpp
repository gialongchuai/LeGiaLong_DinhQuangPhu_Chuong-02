/*
	Bài 8: Cho một mảng các phân số gồm n phần tử (n≤50), sau
	đó thực hiện các chức năng:
	1. Viết hàm nhập danh sách các phân số.
	2. Viết hàm xuất danh sách các phân số.
	3. Tìm phân số có giá trị lớn/nhỏ nhất
	4. Tính tổng và tích các phân số.
	5. Xuất ra nghịch đảo giá trị các phân số trong mảng.
	6. Sắp xếp mảng tăng/giảm dần theo các giải thuật đã học.
*/

#include <stdio.h>

#define MAX 50

typedef struct {
	int tu; // Tử số
	int mau; // Mẫu số
} PhanSo;

// Hàm nhập danh sách các phân số
void nhapDanhSach(PhanSo ds[], int *n) {
	printf("Nhap so luong phan so (n <= 50): ");
	scanf("%d", n);

	for (int i = 0; i < *n; i++) {
		printf("Nhap phan so thu %d: \n", i + 1);
		printf("Tu so: ");
		scanf("%d", &ds[i].tu);
		printf("Mau so: ");
		scanf("%d", &ds[i].mau);
	}
}

// Hàm xuất danh sách các phân số
void xuatDanhSach(PhanSo ds[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Phan so thu %d: %d/%d\n", i + 1, ds[i].tu, ds[i].mau);
	}
}

// Hàm tính giá trị phân số
float giaTri(PhanSo ps) {
	return (float)ps.tu / ps.mau;
}

// Hàm tìm phân số có giá trị lớn nhất và nhỏ nhất
void timMaxMin(PhanSo ds[], int n, PhanSo *max, PhanSo *min) {
	if (n == 0) return;

	*max = ds[0];
	*min = ds[0];

	for (int i = 1; i < n; i++) {
		if (giaTri(ds[i]) > giaTri(*max)) {
			*max = ds[i];
		}
		if (giaTri(ds[i]) < giaTri(*min)) {
			*min = ds[i];
		}
	}
}

// Hàm tính tổng và tích các phân số
void tinhTongTich(PhanSo ds[], int n, PhanSo *tong, PhanSo *tich) {
	tong->tu = 0;
	tong->mau = 1;
	tich->tu = 1;
	tich->mau = 1;

	for (int i = 0; i < n; i++) {
		tong->tu = tong->tu * ds[i].mau + ds[i].tu * tong->mau;
		tong->mau = tong->mau * ds[i].mau;

		tich->tu *= ds[i].tu;
		tich->mau *= ds[i].mau;
	}
}

// Hàm xuất nghịch đảo các phân số
void xuatNghichDao(PhanSo ds[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Nghich dao phan so thu %d: %d/%d\n", i + 1, ds[i].mau, ds[i].tu);
	}
}

// Hàm đổi chỗ hai phân số
void doiCho(PhanSo *a, PhanSo *b) {
	PhanSo temp = *a;
	*a = *b;
	*b = temp;
}

// Hàm sắp xếp phân số theo thứ tự tăng dần
void sapXepTangDan(PhanSo ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (giaTri(ds[i]) > giaTri(ds[j])) {
				doiCho(&ds[i], &ds[j]);
			}
		}
	}
}

// Hàm sắp xếp phân số theo thứ tự giảm dần
void sapXepGiamDan(PhanSo ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (giaTri(ds[i]) < giaTri(ds[j])) {
				doiCho(&ds[i], &ds[j]);
			}
		}
	}
}

int main() {
	PhanSo ds[MAX];
	int n;
	PhanSo max, min, tong, tich;
	int chon;

	do {
		printf("\nMenu:\n");
		printf("1. Nhap danh sach phan so\n");
		printf("2. Xuat danh sach phan so\n");
		printf("3. Tim phan so co gia tri lon nhat va nho nhat\n");
		printf("4. Tinh tong va tich cac phan so\n");
		printf("5. Xuat nghich dao cac phan so\n");
		printf("6. Sap xep tang dan\n");
		printf("7. Sap xep giam dan\n");
		printf("0. Thoat\n");
		printf("Chon chuc nang: ");
		scanf("%d", &chon);

		switch (chon) {
		case 1:
			nhapDanhSach(ds, &n);
			break;
		case 2:
			xuatDanhSach(ds, n);
			break;
		case 3:
			timMaxMin(ds, n, &max, &min);
			printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);
			printf("Phan so nho nhat: %d/%d\n", min.tu, min.mau);
			break;
		case 4:
			tinhTongTich(ds, n, &tong, &tich);
			printf("Tong cac phan so: %d/%d\n", tong.tu, tong.mau);
			printf("Tich cac phan so: %d/%d\n", tich.tu, tich.mau);
			break;
		case 5:
			xuatNghichDao(ds, n);
			break;
		case 6:
			sapXepTangDan(ds, n);
			printf("Danh sach sau khi sap xep tang dan:\n");
			xuatDanhSach(ds, n);
			break;
		case 7:
			sapXepGiamDan(ds, n);
			printf("Danh sach sau khi sap xep giam dan:\n");
			xuatDanhSach(ds, n);
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
	} while (chon != 0);

	return 0;
}
