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
	Node* node = (Node*)malloc(sizeof(Node)); //삽입할 노드 마련
	node->data = data;
	node->next = NULL;
	if (queue->Front == NULL) {
		queue->Front = node;
	}
	else {
		queue->rear->next = node; //원래 rear노드의 next가 삽입할 노드를 가리키게 한다
	}
	queue->rear = node; //삽입한 노드가 rear이 되게 한다
	queue->count++;
}

int pop(Queue* queue) {
	if (queue->count == 0) {
		printf("큐 언더플로우가 발생하였습니다.\n");
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
	printf("--- 큐의 앞 ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 큐의 뒤---\n");
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