#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10000

int a[MAX_SIZE];
int founded;

// MID위치에 있는 원소와 반복적으로 비교
int search(int start, int end, int target) {
	if (start > end) return -9999;
	int mid = (start + end) / 2;
	if (a[mid] == target) return mid;
	else if (a[mid] > target) return search(start, mid - 1, target);
	else return search(mid + 1, end, target);
	// 재귀함수 이용
}

int main(void) {
	int n, target;
	scanf_s("%d %d", &n, &target);
	for (int i = 0; i < n; i++) scanf_s("%d", &a[i]);
	int result = search(0, n - 1, target);
	if (result != -9999)
		printf("%d번째 원소입니다.\n", result + 1);
	else printf("원소를 찾을 수 없습니다.\n");
	system("pause");
	return 0;
}