#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int index;
	int distance;
	struct Node* next;
} Node;

void addFront(Node* root, int index, int distance) { // node�� ������ ���, root�� ����
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->distance = distance;
	node->next = root->next; // ���ο� node�� next���� ������ node�� next���� ����
	// 0 1 2 �迭�� 5�� �߰��Ѵٸ� 5 0 1 2 �� �ϳ��� �ڷ� �з����� ���� ����
	root->next = node;
}

void showALL(Node* root) {
	Node* cur = root->next; //cur �����͸� root�� next�� ����
	while (cur != NULL) {
		printf("%d(�Ÿ�: %d) ", cur->index, cur->distance);
		cur = cur->next;
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	Node** arr = (Node**)malloc(sizeof(Node*) * n + 1); //1���� ����Ѵٰ� ����

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
		printf("���� [%d]: ", i);
		showALL(arr[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}