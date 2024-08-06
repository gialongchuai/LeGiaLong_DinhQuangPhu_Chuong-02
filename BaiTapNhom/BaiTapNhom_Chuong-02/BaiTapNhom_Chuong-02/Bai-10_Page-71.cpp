/*
Cho một danh sách sinh viên gồm n sinh viên, với n được nhập bất kỳ. Thông tin một sinh
viên: Mã số sinh viên, Họ tên sinh viên, Điểm các môn: Nhập môn lập trình, Môn toán A1, Môn
toán A2, Môn Vật lý kỹ thuật, Môn anh văn, Điểm trung bình tích lũy. Thông tin môn học bao gồm:
Mã môn, Tên môn, Số tín chỉ, Điểm. Thực hiện các yêu cầu sau:
a) Hãy thiết kế và xây dựng các cấu trúc (struct) phù hợp cho bài toán.
b) Xây dựng một chương trình hoàn chỉnh cho một lớp học đảm bảo các thao tác sau:
1. Hàm nhập/xuất danh sách sinh viên
2. Tìm một sinh viên thông qua mã số sinh viên.
3. Tìm sinh viên có điểm trung bình cao nhất.
4. Thêm, xóa một sinh viên ra khỏi danh sách.
5. Sắp xếp danh sách sinh viên tăng/giảm theo điểm trung bình.
6. Xếp loại học tập của sinh viên theo kết quả học tập.
7. Thống kê số môn đậu rớt của sinh viên.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MON 5
#define MAX_NAME 100

// Cấu trúc để lưu thông tin môn học
typedef struct {
	char maMon[10];
	char tenMon[MAX_NAME];
	int soTinChi;
	float diem;
} MonHoc;

// Cấu trúc để lưu thông tin sinh viên
typedef struct {
	char maSV[10];
	char hoTen[MAX_NAME];
	MonHoc monHoc[MAX_MON];
	float diemTrungBinh;
} SinhVien;

// Cấu trúc để lưu danh sách sinh viên
typedef struct {
	SinhVien* danhSach;
	int soLuong;
} DanhSachSinhVien;

// Hàm nhập thông tin môn học
void nhapMonHoc(MonHoc* mon) {
	printf("Nhap ma mon: ");
	scanf("%s", mon->maMon);
	printf("Nhap ten mon: ");
	scanf(" %[^\n]", mon->tenMon);
	printf("Nhap so tin chi: ");
	scanf("%d", &mon->soTinChi);
	printf("Nhap diem: ");
	scanf("%f", &mon->diem);
}

// Hàm nhập thông tin sinh viên
void nhapSinhVien(SinhVien* sv) {
	printf("Nhap ma sinh vien: ");
	scanf("%s", sv->maSV);
	printf("Nhap ho ten sinh vien: ");
	scanf(" %[^\n]", sv->hoTen);
	for (int i = 0; i < MAX_MON; i++) {
		printf("Nhap thong tin mon hoc thu %d:\n", i + 1);
		nhapMonHoc(&sv->monHoc[i]);
	}
	// Tính điểm trung bình
	float tongDiem = 0;
	for (int i = 0; i < MAX_MON; i++) {
		tongDiem += sv->monHoc[i].diem * sv->monHoc[i].soTinChi;
	}
	int tongTinChi = 0;
	for (int i = 0; i < MAX_MON; i++) {
		tongTinChi += sv->monHoc[i].soTinChi;
	}
	sv->diemTrungBinh = tongDiem / tongTinChi;
}

// Hàm xuất thông tin môn học
void xuatMonHoc(const MonHoc* mon) {
	printf("Ma mon: %s\n", mon->maMon);
	printf("Ten mon: %s\n", mon->tenMon);
	printf("So tin chi: %d\n", mon->soTinChi);
	printf("Diem: %.2f\n", mon->diem);
}

// Hàm xuất thông tin sinh viên
void xuatSinhVien(const SinhVien* sv) {
	printf("Ma sinh vien: %s\n", sv->maSV);
	printf("Ho ten: %s\n", sv->hoTen);
	printf("Diem trung binh: %.2f\n", sv->diemTrungBinh);
	for (int i = 0; i < MAX_MON; i++) {
		printf("Thong tin mon hoc thu %d:\n", i + 1);
		xuatMonHoc(&sv->monHoc[i]);
	}
}

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(DanhSachSinhVien* ds) {
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &ds->soLuong);
	ds->danhSach = (SinhVien*)malloc(ds->soLuong * sizeof(SinhVien));
	for (int i = 0; i < ds->soLuong; i++) {
		printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
		nhapSinhVien(&ds->danhSach[i]);
	}
}

// Hàm xuất danh sách sinh viên
void xuatDanhSachSinhVien(const DanhSachSinhVien* ds) {
	for (int i = 0; i < ds->soLuong; i++) {
		printf("Thong tin sinh vien thu %d:\n", i + 1);
		xuatSinhVien(&ds->danhSach[i]);
	}
}

// Tìm sinh viên theo ma so sinh vien
SinhVien* timSinhVienTheoMa(DanhSachSinhVien* ds, const char* maSV) {
	for (int i = 0; i < ds->soLuong; i++) {
		if (strcmp(ds->danhSach[i].maSV, maSV) == 0) {
			return &ds->danhSach[i];
		}
	}
	return NULL;
}

// Tìm sinh viên có diem trung binh cao nhat
SinhVien* timSinhVienDiemCaoNhat(DanhSachSinhVien* ds) {
	if (ds->soLuong == 0) return NULL;
	SinhVien* svMax = &ds->danhSach[0];
	for (int i = 1; i < ds->soLuong; i++) {
		if (ds->danhSach[i].diemTrungBinh > svMax->diemTrungBinh) {
			svMax = &ds->danhSach[i];
		}
	}
	return svMax;
}

// Thêm sinh vien vao danh sach
void themSinhVien(DanhSachSinhVien* ds, SinhVien svMoi) {
	ds->danhSach = (SinhVien*)realloc(ds->danhSach, (ds->soLuong + 1) * sizeof(SinhVien));
	ds->danhSach[ds->soLuong] = svMoi;
	ds->soLuong++;
}

// Xoa sinh vien theo ma so sinh vien
void xoaSinhVien(DanhSachSinhVien* ds, const char* maSV) {
	for (int i = 0; i < ds->soLuong; i++) {
		if (strcmp(ds->danhSach[i].maSV, maSV) == 0) {
			for (int j = i; j < ds->soLuong - 1; j++) {
				ds->danhSach[j] = ds->danhSach[j + 1];
			}
			ds->danhSach = (SinhVien*)realloc(ds->danhSach, (ds->soLuong - 1) * sizeof(SinhVien));
			ds->soLuong--;
			return;
		}
	}
}

// So sanh diem trung binh
int soSanhDiemTrungBinh(const void* a, const void* b) {
	float diemA = ((SinhVien*)a)->diemTrungBinh;
	float diemB = ((SinhVien*)b)->diemTrungBinh;
	return (diemA > diemB) - (diemA < diemB);
}

// Sap xep danh sach sinh vien theo diem trung binh
void sapXepDanhSachSinhVien(DanhSachSinhVien* ds, int tangDan) {
	qsort(ds->danhSach, ds->soLuong, sizeof(SinhVien), soSanhDiemTrungBinh);
	if (!tangDan) {
		for (int i = 0; i < ds->soLuong / 2; i++) {
			SinhVien temp = ds->danhSach[i];
			ds->danhSach[i] = ds->danhSach[ds->soLuong - i - 1];
			ds->danhSach[ds->soLuong - i - 1] = temp;
		}
	}
}

// Xep loai hoc tap
void xepLoaiHocTap(const SinhVien* sv) {
	if (sv->diemTrungBinh >= 8) {
		printf("Xep loai: Gioi\n");
	}
	else if (sv->diemTrungBinh >= 6.5) {
		printf("Xep loai: Kha\n");
	}
	else if (sv->diemTrungBinh >= 5) {
		printf("Xep loai: Trung binh\n");
	}
	else {
		printf("Xep loai: Yeu\n");
	}
}

// Dem so mon thi dat
int demMonThiDat(const SinhVien* sv) {
	int dem = 0;
	for (int i = 0; i < MAX_MON; i++) {
		if (sv->monHoc[i].diem >= 5) {
			dem++;
		}
	}
	return dem;
}

// Dem so mon thi truot
int demMonThiTruot(const SinhVien* sv) {
	int dem = 0;
	for (int i = 0; i < MAX_MON; i++) {
		if (sv->monHoc[i].diem < 5) {
			dem++;
		}
	}
	return dem;
}

int main() {
	DanhSachSinhVien ds;
	int luaChon;
	char maSV[10];
	SinhVien svMoi;
	SinhVien* svTim;

	do {
		printf("\n1. Nhap danh sach sinh vien\n");
		printf("2. Xuat danh sach sinh vien\n");
		printf("3. Tim sinh vien theo ma so\n");
		printf("4. Tim sinh vien diem cao nhat\n");
		printf("5. Them sinh vien\n");
		printf("6. Xoa sinh vien\n");
		printf("7. Sap xep sinh vien theo diem trung binh\n");
		printf("8. Xep loai hoc tap\n");
		printf("9. Thong ke so mon thi dat/truot\n");
		printf("0. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &luaChon);

		switch (luaChon) {
		case 1:
			nhapDanhSachSinhVien(&ds);
			break;
		case 2:
			xuatDanhSachSinhVien(&ds);
			break;
		case 3:
			printf("Nhap ma sinh vien: ");
			scanf("%s", maSV);
			svTim = timSinhVienTheoMa(&ds, maSV);
			if (svTim) {
				xuatSinhVien(svTim);
			}
			else {
				printf("Khong tim thay sinh vien\n");
			}
			break;
		case 4:
			svTim = timSinhVienDiemCaoNhat(&ds);
			if (svTim) {
				printf("Sinh vien diem cao nhat:\n");
				xuatSinhVien(svTim);
			}
			else {
				printf("Danh sach sinh vien rong\n");
			}
			break;
		case 5:
			printf("Nhap thong tin sinh vien moi:\n");
			nhapSinhVien(&svMoi);
			themSinhVien(&ds, svMoi);
			break;
		case 6:
			printf("Nhap ma sinh vien can xoa: ");
			scanf("%s", maSV);
			xoaSinhVien(&ds, maSV);
			break;
		case 7:
			printf("Sap xep sinh vien theo diem trung binh:\n");
			printf("1. Tang dan\n");
			printf("2. Giam dan\n");
			printf("Lua chon: ");
			int luaChonSapXep;
			scanf("%d", &luaChonSapXep);
			sapXepDanhSachSinhVien(&ds, luaChonSapXep == 1);
			xuatDanhSachSinhVien(&ds);
			break;
		case 8:
			printf("Nhap ma sinh vien de xep loai: ");
			scanf("%s", maSV);
			svTim = timSinhVienTheoMa(&ds, maSV);
			if (svTim) {
				xepLoaiHocTap(svTim);
			}
			else {
				printf("Khong tim thay sinh vien\n");
			}
			break;
		case 9:
			printf("Nhap ma sinh vien de thong ke: ");
			scanf("%s", maSV);
			svTim = timSinhVienTheoMa(&ds, maSV);
			if (svTim) {
				printf("So mon thi dat: %d\n", demMonThiDat(svTim));
				printf("So mon thi truot: %d\n", demMonThiTruot(svTim));
			}
			else {
				printf("Khong tim thay sinh vien\n");
			}
			break;
		case 0:
			printf("Thoat chuong trinh\n");
			break;
		default:
			printf("Lua chon khong hop le\n");
			break;
		}
	} while (luaChon != 0);

	free(ds.danhSach);
	return 0;
}
