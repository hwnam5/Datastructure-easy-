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
	array = (char**)malloc(sizeof(char*) * n); //문자열이 담겨져 있는 배열
	for (int i = 0; i < n; i++) {
		array[i] = malloc(sizeof(char) * LENGTH);
		scanf_s("%s", array[i], 1000);
	}
	for (int i = 0; i < n; i++) {
		if(!strcmp(array[i], word)){
			printf("%d번째 원소입니다.\n", i + 1);
			founded = 1;
		}
	}
	if (!founded) printf("원소를 찾을 수 없습니다.\n");
	system("pause");
	return 0;
}