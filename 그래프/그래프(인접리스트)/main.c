#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int index;
	int distance;
	struct Node* next;
} Node;

void addFront(Node* root, int index, int distance) { // node는 삽일할 노드, root는 정점
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->distance = distance;
	node->next = root->next; // 새로운 node의 next값을 기존의 node의 next값을 저장
	// 0 1 2 배열에 5를 추가한다면 5 0 1 2 로 하나씩 뒤로 밀려나는 것을 설정
	root->next = node;
}

void showALL(Node* root) {
	Node* cur = root->next; //cur 포인터를 root의 next로 설정
	while (cur != NULL) {
		printf("%d(거리: %d) ", cur->index, cur->distance);
		cur = cur->next;
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	Node** arr = (Node**)malloc(sizeof(Node*) * n + 1); //1부터 출발한다고 가정

	for (int i = 1; i <= n; i++) {
		arr[i] = (Node*)malloc(sizeof(Node));
		arr[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y, distance;
		scanf("%d %d %d", &x, &y, &distance);
		addFront(arr[x], y, distance);
	}
	for (int i = 1; i <= n; i++) {
		printf("원소 [%d]: ", i);
		showALL(arr[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}