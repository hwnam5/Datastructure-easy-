#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999

//�ʿ��Ѹ�ŭ ������ �Ҵ��ϱ� ������ ������ ȿ������ ������
typedef struct { //���� ����Ʈ ����ü
	int data;
	struct Node* next;
}Node;

typedef struct { //���� ����ü
	Node* top;
}Stack;

//stack ���� �Լ�
void push(Stack *stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top; //����� next�� ������ ž�� �´�
	stack->top = node; // ������ ž�� ���� �ٲ�ġ�� 
}

char* getTop(Stack* stack) {
	Node* top = stack->top;
	return top->data;
}

int pop(Stack* stack) {
	if (stack->top == NULL) {//������ ����ִٸ�
		printf("���� ����÷ο찡 �߻��Ͽ����ϴ�.\n");
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
	printf("--- ������ �ֻ�� --- \n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ������ ���ϴ� --- \n");
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