#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define SIZE 1000

int a[SIZE];

int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int n, min, index;
	printf("�迭�� ũ�� : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("�Է°� : ");
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		min = INT_MAX; // limits.h���� ������ int�� �ִ�
		for (int j = i; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				index = j;
			}
		}
		swap(&a[i], &a[index]); //���ڰ� ���� ��ġ�� �ٲٴ� ����
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}