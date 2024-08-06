/*
	Thiết kế một chương trình lưu trữ thông tin sinh viên được mô tả chi tiết như sau:
	Danh sách sinh viên gồm n sinh viên, với n được nhập từ bàn phím. Thông tin một sinh
	viên bao gồm: Số thứ tự, Mã số sinh viên, Họ tên sinh viên, Điểm tiểu luận, Điểm thi kết
	thúc môn. Thực hiện các yêu cầu sau:
	1. Hãy xây dựng hàm nhập/xuất danh sách sinh viên.
	2. Hãy tính điểm tổng kết = 30%Điểm tiểu luận + 70% Điểm thi kết thúc môn.
	3. In ra sinh viên có điểm tổng kết cao nhất và thấp nhất.
	4. Cho biết có bao nhiêu sinh viên đạt và không đạt.
	5. Hãy qui đổi điểm từ hệ 10 sang hệ 4 theo cơ chế tín chỉ.
	6. Hãy sắp xếp danh sách sinh viên tăng/giảm dần theo điểm tổng kết.
	7. Hãy tính điểm trung bình của tất cả các sinh viên.
	8. Hãy thực hiện việc nhập xuất dữ liệu bằng file txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define GRADE_A 9.0
#define GRADE_B 7.0
#define GRADE_C 5.5
#define GRADE_D 4.0

typedef struct {
	int stt;
	char maSV[15];
	char hoTen[50];
	float diemTieuLuan;
	float diemThi;
	float diemTongKet;
	float diemHe4;
} SinhVien;

// Hàm nhập danh sách sinh viên
void nhapDanhSach(SinhVien ds[], int *n) {
	printf("Nhap so sinh vien: ");
	scanf("%d", n);
	for (int i = 0; i < *n; i++) {
		printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
		ds[i].stt = i + 1;
		printf("Ma so sinh vien: ");
		scanf("%s", ds[i].maSV);
		printf("Ho ten sinh vien: ");
		scanf(" %[^\n]", ds[i].hoTen); // Đọc dòng văn bản với khoảng trắng
		printf("Diem tieu luan: ");
		scanf("%f", &ds[i].diemTieuLuan);
		printf("Diem thi ket thuc mon: ");
		scanf("%f", &ds[i].diemThi);
		ds[i].diemTongKet = 0.3 * ds[i].diemTieuLuan + 0.7 * ds[i].diemThi;
		// Chuyển đổi điểm từ hệ 10 sang hệ 4
		if (ds[i].diemTongKet >= GRADE_A) ds[i].diemHe4 = 4.0;
		else if (ds[i].diemTongKet >= GRADE_B) ds[i].diemHe4 = 3.0;
		else if (ds[i].diemTongKet >= GRADE_C) ds[i].diemHe4 = 2.0;
		else if (ds[i].diemTongKet >= GRADE_D) ds[i].diemHe4 = 1.0;
		else ds[i].diemHe4 = 0.0;
	}
}

// Hàm xuất danh sách sinh viên
void xuatDanhSach(SinhVien ds[], int n) {
	printf("\nDanh sach sinh vien:\n");
	for (int i = 0; i < n; i++) {
		printf("STT: %d\n", ds[i].stt);
		printf("Ma so sinh vien: %s\n", ds[i].maSV);
		printf("Ho ten sinh vien: %s\n", ds[i].hoTen);
		printf("Diem tieu luan: %.2f\n", ds[i].diemTieuLuan);
		printf("Diem thi ket thuc mon: %.2f\n", ds[i].diemThi);
		printf("Diem tong ket: %.2f\n", ds[i].diemTongKet);
		printf("Diem he 4: %.2f\n\n", ds[i].diemHe4);
	}
}

// Hàm in sinh viên có điểm tổng kết cao nhất và thấp nhất
void inDiemCaoThap(SinhVien ds[], int n) {
	float maxDiem = ds[0].diemTongKet;
	float minDiem = ds[0].diemTongKet;
	int indexMax = 0;
	int indexMin = 0;

	for (int i = 1; i < n; i++) {
		if (ds[i].diemTongKet > maxDiem) {
			maxDiem = ds[i].diemTongKet;
			indexMax = i;
		}
		if (ds[i].diemTongKet < minDiem) {
			minDiem = ds[i].diemTongKet;
			indexMin = i;
		}
	}

	printf("\nSinh vien diem tong ket cao nhat:\n");
	printf("STT: %d\n", ds[indexMax].stt);
	printf("Ma so sinh vien: %s\n", ds[indexMax].maSV);
	printf("Ho ten sinh vien: %s\n", ds[indexMax].hoTen);
	printf("Diem tong ket: %.2f\n", ds[indexMax].diemTongKet);

	printf("\nSinh vien diem tong ket thap nhat:\n");
	printf("STT: %d\n", ds[indexMin].stt);
	printf("Ma so sinh vien: %s\n", ds[indexMin].maSV);
	printf("Ho ten sinh vien: %s\n", ds[indexMin].hoTen);
	printf("Diem tong ket: %.2f\n", ds[indexMin].diemTongKet);
}

// Hàm đếm số sinh viên đạt và không đạt
void demSoSinhVien(SinhVien ds[], int n) {
	int soDat = 0;
	int soKhongDat = 0;

	for (int i = 0; i < n; i++) {
		if (ds[i].diemTongKet >= 5.0) {
			soDat++;
		}
		else {
			soKhongDat++;
		}
	}

	printf("\nSo sinh vien dat: %d\n", soDat);
	printf("So sinh vien khong dat: %d\n", soKhongDat);
}

// Hàm sắp xếp danh sách sinh viên theo điểm tổng kết
void sapXepDanhSach(SinhVien ds[], int n, int tangDan) {
	SinhVien temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((tangDan && ds[i].diemTongKet > ds[j].diemTongKet) ||
				(!tangDan && ds[i].diemTongKet < ds[j].diemTongKet)) {
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}

// Hàm tính điểm trung bình của tất cả các sinh viên
float tinhDiemTrungBinh(SinhVien ds[], int n) {
	float tongDiem = 0.0;
	for (int i = 0; i < n; i++) {
		tongDiem += ds[i].diemTongKet;
	}
	return tongDiem / n;
}

// Hàm lưu danh sách sinh viên vào file
void luuFile(SinhVien ds[], int n, const char *tenFile) {
	FILE *file = fopen(tenFile, "w");
	if (file == NULL) {
		printf("Khong the mo file!\n");
		return;
	}
	fprintf(file, "%d\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(file, "%d %s %s %.2f %.2f %.2f %.2f\n",
			ds[i].stt, ds[i].maSV, ds[i].hoTen,
			ds[i].diemTieuLuan, ds[i].diemThi,
			ds[i].diemTongKet, ds[i].diemHe4);
	}
	fclose(file);
}

// Hàm đọc danh sách sinh viên từ file
void docFile(SinhVien ds[], int *n, const char *tenFile) {
	FILE *file = fopen(tenFile, "r");
	if (file == NULL) {
		printf("Khong the mo file!\n");
		return;
	}
	fscanf(file, "%d", n);
	for (int i = 0; i < *n; i++) {
		fscanf(file, "%d %s", &ds[i].stt, ds[i].maSV);
		fscanf(file, " %[^\n]", ds[i].hoTen);
		fscanf(file, "%f %f %f %f",
			&ds[i].diemTieuLuan, &ds[i].diemThi,
			&ds[i].diemTongKet, &ds[i].diemHe4);
	}
	fclose(file);
}

int main() {
	SinhVien ds[MAX];
	int n;
	int chon;
	char tenFile[100];

	while (1) {
		printf("\n1. Nhap danh sach sinh vien\n");
		printf("2. Xuat danh sach sinh vien\n");
		printf("3. In sinh vien diem cao nhat va thap nhat\n");
		printf("4. Dem so sinh vien dat va khong dat\n");
		printf("5. Sap xep danh sach theo diem tong ket\n");
		printf("6. Tinh diem trung binh\n");
		printf("7. Luu danh sach sinh vien vao file\n");
		printf("8. Doc danh sach sinh vien tu file\n");
		printf("9. Thoat\n");
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
			inDiemCaoThap(ds, n);
			break;
		case 4:
			demSoSinhVien(ds, n);
			break;
		case 5:
			printf("1. Sap xep tang dan\n");
			printf("2. Sap xep giam dan\n");
			printf("Chon: ");
			scanf("%d", &chon);
			sapXepDanhSach(ds, n, chon == 1);
			break;
		case 6:
			printf("Diem trung binh cua tat ca sinh vien: %.2f\n", tinhDiemTrungBinh(ds, n));
			break;
		case 7:
			printf("Nhap ten file luu danh sach: ");
			scanf("%s", tenFile);
			luuFile(ds, n, tenFile);
			break;
		case 8:
			printf("Nhap ten file doc danh sach: ");
			scanf("%s", tenFile);
			docFile(ds, &n, tenFile);
			break;
		case 9:
			return 0;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	}

	return 0;
}
