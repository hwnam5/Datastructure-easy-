#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VALUE 10001

int n, m;
int a[MAX_VALUE];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &m); a[m]++; }
	for (int i = 0; i < MAX_VALUE; i++) {
		while (a[i] != 0) { printf("%d ", i); a[i]--; } //출력할때마다 a[i]를 줄여서 a[i]가 0이 될때까지 출력하는 반복문
	}
	system("pause");
}