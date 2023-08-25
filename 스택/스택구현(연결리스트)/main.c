#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999

//필요한만큼 공간을 할당하기 때문에 공간의 효율성이 높아짐
typedef struct { //연결 리스트 구조체
	int data;
	struct Node* next;
}Node;

typedef struct { //스택 구조체
	Node* top;
}Stack;

//stack 삽입 함수
void push(Stack *stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top; //노드의 next로 현재의 탑이 온다
	stack->top = node; // 스택의 탑을 노드로 바꿔치기 
}

char* getTop(Stack* stack) {
	Node* top = stack->top;
	return top->data;
}

int pop(Stack* stack) {
	if (stack->top == NULL) {//스택이 비어있다면
		printf("스택 언더플로우가 발생하였습니다.\n");
		return -INF;
	}
	Node* node = stack->top;
	int data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}

void show(Stack* stack) {
	Node* cur = stack->top;
	printf("--- 스택의 최상단 --- \n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 스택의 최하단 --- \n");
}

int main(void) {
	Stack s;
	s.top == NULL;
	push(&s, 7);
	push(&s, 5);
	push(&s, 4);
	pop(&s);
	push(&s, 6);
	pop(&s);
	show(&s);
	system("pause");
	return 0;
}