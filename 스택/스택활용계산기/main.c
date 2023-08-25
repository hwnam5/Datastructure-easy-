#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999

typedef struct {
	char data[100];
	struct Node* next;
}Node;

typedef struct {
	Node* Top;
}Stack;

void push(Stack* stack, char* data) {
	Node* node = (Node*)malloc(sizeof(Node));
	strcpy(node->data, data);
	node->next = stack->Top;
	stack->Top = node;
}

char* getTop(Stack* stack) {
	Node* top = stack->Top;
	return top->data;
}
char* pop(Stack* stack) {
	if(stack->Top == NULL) {//������ ����ִٸ�
		printf("���� ����÷ο찡 �߻��Ͽ����ϴ�.\n");
		return -INF;
	}
	Node* node = stack->Top;
	char* data = (char*)malloc(sizeof(char) * 100);
	strcpy(data, node->data);
	stack->Top = node->next;
	free(node);
	return data;
}

int getPriority(char* i) {
	if (!strcmp(i, "(")) return 0; // ���ڿ��� ��ġ�� �� 0�� ��ȯ�ϹǷ� !�� �����Ͽ� ������ ������ �ٲ�
	if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
	if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
	return 3;
}

char* transition(Stack* stack, char** s, int size) {
	char result[1000] = "";
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
			// stack�� �ִ� �������� �켱 ������ ���ٸ� -> stack�� �ִ� �����ڸ� ������ ��ȯ�� ������ ����� �迭�� ����
			while (stack->Top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {
				strcat(result, pop(stack));
				strcat(result, " ");
			}
			push(stack, s[i]);
		}
		else if (!strcmp(s[i], "("))
			push(stack, s[i]);
		else if (!strcmp(s[i], ")")) { // ���ڿ��� )�� ������ ��
			while (strcmp(getTop(stack), "(")) { //"(" �� �ȳ����� ������
				strcat(result, pop(stack));
				strcat(result, " ");
			}
			pop(stack); // "("�� �� �ű�
		}
		else {
			strcat(result, s[i]);
			strcat(result, " ");
		}
	}
	while (stack->Top != NULL) {
		strcat(result, pop(stack));
		strcat(result, " ");
	}
	return result;
}

void calculate(Stack* stack, char** s, int size) {
	int x, y, z;
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) { // �����ڸ� ������ �ǿ����� 2���� �̾Ƽ� ���
			x = atoi(pop(stack)); // atoi() => ���ڿ��� ���� Ÿ������
			y = atoi(pop(stack));
			if (!strcmp(s[i], "+")) z = y + x;
			if (!strcmp(s[i], "-")) z = y - x;
			if (!strcmp(s[i], "*")) z = y * x;
			if (!strcmp(s[i], "/")) z = y / x;
			char buffer[100];
			sprintf(buffer, "%d", z);
			push(stack, buffer);
		}
			else{
				push(stack, s[i]);
			}
	}
	printf("%s\n", pop(stack)); // ���� ���� ������ stack�� ��
}

int main(void) {
	Stack stack;
	stack.Top = NULL;
	char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
	int size = 1;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == ' ')
			size++;
	}
	char* ptr = strtok(a, " ");
	char** input = (char**)malloc(sizeof(char*) * size);
	for (int i = 0; i < size; i++) {
		input[i] = (char*)malloc(sizeof(char) * 100);
	}
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr);
		ptr = strtok(NULL, " ");
	}
	char b[1000] = "";
	strcpy(b, transition(&stack, input, size));
	printf("���� ǥ���: %s\n", b);

	size = 1;
	for (int i = 0; i < strlen(b) - 1; i++) { // �������� �׻� ������ ���Ƿ� 1�� ����
		if (b[i] == ' ')
			size++;
	}
	char* ptr2 = strtok(b, " ");
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr2);
		ptr2 = strtok(NULL, " ");
	}
	calculate(&stack, input, size);
	
	system("pause");
	return 0;
}