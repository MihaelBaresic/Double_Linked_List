#define _CRT_SECURE_NO_WARNINGS
//LIFO dodavanje na poc. skidanje s poc.
//FIFO last in head next out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Stog * Position;
struct _Stog;
typedef struct _Stog {
	int El;
	Position next;
}Stog;

Position createEl(int);
void insertStart(Position, Position);
void printList(Position);
void deleteStart(Position);

int main() {
	Stog head;
	head.next = NULL;
	Position K = NULL;
	
	K = createEl(1);
	insertStart(&head, K);
	K = createEl(2);
	insertStart(&head, K);
	K = createEl(3);
	insertStart(&head, K);
	
	printf("\n\tList content:");
	printList(&head);
	
	deleteStart(&head);
	deleteStart(&head);
	deleteStart(&head);
	
	printf("\n\tList content:");
	printList(&head);
	
	system("pause");
	return 0;
}

Position createEl(int El) {
	Position Q;
	Q = (Position)malloc(sizeof(Stog));
	if (!Q)
		printf("Memory not allocated!");
	Q->El = El;
	Q->next = NULL;
	return Q;
}

void insertStart(Position head, Position K) {
	K->next = head->next;
	head->next = K;
}

void deleteStart(Position head) {
	Position temp;
	temp = head->next;
	head->next = temp->next;
	free(temp);
}


void printList(Position head) {
	if (NULL == head->next)
		printf("Linked list is emtpy!");
	
	head = head->next;
	while (head != NULL) {
		printf("\t\n%d", head->El);
		head = head->next;
	}

	puts("\n");
}