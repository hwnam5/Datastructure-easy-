#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999

typedef struct {
	int data;
	struct Node* next;
}Node;

typedef struct {
	Node* rear;
	Node* Front;
	int count;
}Queue;

void push(Queue* queue, int data) {
	Node* node = (Node*)malloc(sizeof(Node)); //������ ��� ����
	node->data = data;
	node->next = NULL;
	if (queue->Front == NULL) {
		queue->Front = node;
	}
	else {
		queue->rear->next = node; //���� rear����� next�� ������ ��带 ����Ű�� �Ѵ�
	}
	queue->rear = node; //������ ��尡 rear�� �ǰ� �Ѵ�
	queue->count++;
}

int pop(Queue* queue) {
	if (queue->count == 0) {
		printf("ť ����÷ο찡 �߻��Ͽ����ϴ�.\n");
		return -INF;
	}

	Node* node = queue->Front;
	int data = node->data;
	queue->Front = node->next;
	free(node);
	queue->count--;
	return data;
}

void show(Queue* queue) {
	Node* cur = queue->Front;
	printf("--- ť�� �� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ť�� ��---\n");
}

int main(void) {
	Queue q;
	q.Front = q.rear = NULL;
	push(&q, 7);
	push(&q, 5);
	push(&q, 4);
	pop(&q);
	push(&q, 6);
	pop(&q);
	show(&q);
	system("pause");
	return 0;
}