#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Element* Position;
typedef struct _Element;
typedef struct _Element {
	int El;
	Position next;
	Position prev;
}Element;

Position createEl(int);
void printList(Position);
void insertStart(Position, Position);
void insertEnd(Position, Position);
Position findEl(Position, int);
Position findPrevEl(Position, int);
void insertAfter(Position, int, int);
void insertBefore(Position, int, int);
void deleteEl(Position, int);
void deleteAll(Position);
void Sort(Position,int x);

int main() {
	Element head;
	head.next = NULL, head.prev = NULL;
	Position K = NULL;

	Sort(&head, 3);
	Sort(&head, 7);
	Sort(&head, 5);
	Sort(&head, 4);

	printf("\nSorted list:");
	printList(&head);

	insertBefore(&head, 7, 9);
	puts("\n");
	
	insertAfter(&head, 22, 1);

	insertAfter(&head, 5, 8);
	puts("\n");

	deleteEl(&head, 9);

	printf("\n\nIn FIND:\n");
	K=findEl(&head, 5);
	if(K!=NULL)
		printf("\t\nValue of found Element = %d\n",K->El);
	printf("\nIn FIND_PREV:\n");
	K=findPrevEl(&head, 2);
	if (K != NULL)
		printf("\t\nValue of found Element = %d\n", K->El);
	K = findPrevEl(&head, 5);
	if (K != NULL)
		printf("\t\nValue of found Element = %d\n", K->El);
	
	printf("\nList content:\n");
	printList(&head);

	deleteAll(&head);
	printList(&head);

	return 0;
}

Position createEl(int x) {
	Position K;
	K = (Position)malloc(sizeof(Element));
	if (!K)
		printf("Struct failed to allocate!");

	K->El = x;
	return K;
}

void insertStart(Position head,Position K) {

	if (head == NULL)
		return NULL;
	K->next = head->next; // OVO MORA ICI PRVO INACE PROGRAM PUCA (prije head->next) !!
	K->prev = head;
	head->next = K;

}
void insertAfter(Position head, int x, int y) {
	Position K = NULL;
	head = findEl(head, x);
	K = createEl(y);
	insertStart(head, K);
}

void insertBefore(Position head, int x, int y) {
	Position K = NULL;
	head = findPrevEl(head, x);
	K = createEl(y);
	insertStart(head, K);
}

void deleteEl(Position head, int x) {
	
	Position temp;
	temp = findEl(head, x);
	
	if (temp != NULL) {
		head = temp->next;
		head->prev = temp->prev;
		temp->prev->next = temp->next;
		free(temp);
	}

}

void deleteAll(Position head) {
	Position temp, tempo;
	tempo = head->next;

	while (head->next != NULL) {
		temp = tempo;
		head->next = temp->next;
		if (temp->next == NULL)
			break;
		else {
			temp->next->prev = head;
			tempo = head->next;
			free(temp);
		}
	}
}

void Sort(Position head, int x) {

	Position K;
	K = createEl(x);

	while (head->next != NULL && head->next->El < x) {
		head->next->prev = head;
		head = head->next;
	}

	insertStart(head, K);
}

void insertEnd(Position head,Position K) {
	
	while (head->next != NULL) {
		head->next->prev = head;
		head = head->next;
	}

	K->next = NULL;
	head->next = K;
	K->prev = head;
}

Position findEl(Position head, int x) {
	Position last = NULL;
	//Position temp = head;

	if (head->next == NULL) {
		printf("Linked list is empty!");
		return NULL;
	}
	
	while (head->next != NULL)
	{
		last = head;
		head = head->next;
		head->prev = last;

		if (head->El == x) {
			printf("\nElement %d is found!", x);
			return head;
		}
	}
	//Provjera jeli radi PREV
	/*
	if (head->prev->El == temp->El)
		printf("\nHead is prev of found element!");
	else
		printf("\t\n%d is prev of found element!", head->prev->El);
	*/
	if (head->next == NULL) {
		printf("Element %d is not found in Linked list!\n", x);
		return NULL;
	}
}

Position findPrevEl(Position head, int x)
{
	Position K = NULL;
	Position temp = head;
	head = findEl(head, x);
	if (head == NULL)
		return NULL;
	head = head->prev;
	return head;

}


void printList(Position head) {

	//Position last = NULL;
	if (head->next == NULL)
		printf("Linked list is empty!");
	puts("\n");
	head = head->next;
	
	while (head != NULL) {
		printf("\t\n%d", head->El);
		//last = head;
		head = head->next;
	}
	//Preko prev-a
	//puts("\n\nReverse:\n");

	//while (last->prev != NULL) {
	//	printf("\t\n%d", last->El);
	//	last = last->prev;
	//}
	
	puts("\n");
}


