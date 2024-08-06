/*
	Bài 2: Cho dãy ký tự
	Z R L K H F E C A
	a.Tìm x = R, x = C?
	b.Tìm x = D, x = Q?
*/

#include <stdio.h>

// Hàm tìm kiếm nhị phân cho mảng ký tự
int binarySearchChar(char arr[], int size, char x) {
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
	char arr[] = { 'A', 'C', 'E', 'F', 'H', 'K', 'L', 'R', 'Z' };
	int size = sizeof(arr) / sizeof(arr[0]);
	char x;
	int result;
	char choice;

	do {
		printf("Nhap ky tu can tim: ");
		scanf(" %c", &x);

		result = binarySearchChar(arr, size, x);
		if (result != -1) {
			printf("Ky tu %c duoc tim thay tai chi so %d.\n", x, result);
		}
		else {
			printf("Ky tu %c khong co trong day ky tu.\n", x);
		}

		printf("Ban co muon tiep tuc tim kiem? (y/n): ");
		scanf(" %c", &choice);
	} while (choice == 'y' || choice == 'Y');

	return 0;
}
