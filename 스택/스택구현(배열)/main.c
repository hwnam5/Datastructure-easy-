#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 9999999

int stack[SIZE];
int top = -1; //최상단(입구)를 의미하는 변수

//스택삽입함수
void push(int data) {
	if (top == SIZE - 1) {
		printf("스택 오버플로우가 발생하였습니다.\n");
		return;
	}
	stack[++top] = data;
}

//스택추출함수
int pop() {
	if (top == -1) {
		printf("스택 언더플로우가 발생하였습니다.\n");
		return -INF;
	}
	return stack[top--];
}

//스택 전체 출력함수
void show() {
	printf("--- 스택의 최상단 ---\n");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	printf("--- 스택의 최하단 ---\n");
}
int main(void) {
	push(7);
	push(5);
	push(4);
	pop();
	push(6);
	pop();
	show();

	system("pause");
	return 0;
}