#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 1000

char** array;
int founded;

int main(void) {
	int n;
	char* word;
	word = malloc(sizeof(char) * LENGTH);
	scanf_s("%d %s", &n, word, 1000);
	array = (char**)malloc(sizeof(char*) * n); //���ڿ��� ����� �ִ� �迭
	for (int i = 0; i < n; i++) {
		array[i] = malloc(sizeof(char) * LENGTH);
		scanf_s("%s", array[i], 1000);
	}
	for (int i = 0; i < n; i++) {
		if(!strcmp(array[i], word)){
			printf("%d��° �����Դϴ�.\n", i + 1);
			founded = 1;
		}
	}
	if (!founded) printf("���Ҹ� ã�� �� �����ϴ�.\n");
	system("pause");
	return 0;
}