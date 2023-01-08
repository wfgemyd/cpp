#include <stdio.h>


typedef struct node {
	int value;
	struct node* next; //pointer to the next node
}Node; //name

void print_list(Node* head) {
	Node* current;
	current = head; // points to the head
	int i = 0;
	while (current != NULL) {
		printf("Node %d: %d\n", i, current->value); //-> will be used in a pointer to a struct
		i++;
		current = current->next; //tarversing the list
	}
}

int main() {
	Node a, b, c;
	a.value = 5;
	b.value = 6;
	c.value = 7;

	a.next = &b;//will give me the memory location of b
	b.next = &c;
	c.next = NULL; //tail

	print_list(&a);
	return 0;
}
