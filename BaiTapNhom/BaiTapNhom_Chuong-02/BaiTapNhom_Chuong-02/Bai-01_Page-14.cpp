/*
	Bài 1: Cho dãy số sau:
	7 9 13 17 27 30 31 35 38 40
	a.Tìm x = 17, x = 35, x = 40?	
	b.Tìm x = 23, x = 10, x = 36?
*/

#include <stdio.h>

int binarySearch(int arr[], int size, int x) {
	int left = 0, right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		// Kiểm tra nếu x nằm ngay tại giữa
		if (arr[mid] == x) {
			return mid;
		}
		// Nếu x lớn hơn, bỏ qua nửa trái
		if (arr[mid] < x) {
			left = mid + 1;
		}
		// Nếu x nhỏ hơn, bỏ qua nửa phải
		else {
			right = mid - 1;
		}
	}
	// Trả về -1 nếu không tìm thấy
	return -1;
}

int main() {
	int arr[] = { 7, 9, 13, 17, 27, 30, 31, 35, 38, 40 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int x;
	int result;
	char choice;

	do {
		printf("Nhap gia tri can tim: ");
		scanf("%d", &x);

		result = binarySearch(arr, size, x);
		if (result != -1) {
			printf("Gia tri %d duoc tim thay tai chi so %d.\n", x, result);
		}
		else {
			printf("Gia tri %d khong co trong day so.\n", x);
		}

		printf("Ban co muon tiep tuc tim kiem? (y/n): ");
		scanf(" %c", &choice);
	} while (choice == 'y' || choice == 'Y');

	return 0;
}
