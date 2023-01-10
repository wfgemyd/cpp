#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
	printf("___________________\n");
}
bool is_empty(Node* head) {
	if (head == NULL) return true;
	return false;
}

Node* insert_at_head(Node* head, int new_value) {
	Node* new_node = calloc(1, sizeof(Node)); //allocation of memory
	new_node->value = new_value;
	if (is_empty(&head)) return new_node;
	else {
		new_node->next = head;
		return new_node;
	}
}

Node* insert_at_tail(Node* head, int new_value) {
	Node* new_node = calloc(1, sizeof(Node)); //allocation of memory
	new_node->value = new_value;
	if (is_empty(&head)) return new_node;
	else {
		Node* current = head;
		while (current->next != NULL) current = current->next;
		current->next = new_node;
		return head;
	}
}

Node* insert_at_middle(Node* head, int new_value, int location) {
	Node* new_node = calloc(1, sizeof(Node)); //allocation of memory
	new_node->value = new_value;
	if (is_empty(&head)) return new_node;
	else {
		Node* current = head;

		for (int i = 0; i != location - 1; i++) {
			current = current->next;
		}
		Node* temp = current->next;
		new_node->next = temp;
		current->next = new_node;
		
		return head;
	}
}
Node* delete_at_head(Node* head)
{
	if (is_empty(&head)) return NULL;
	else
	{
		Node* to_return = head->next;
		free(head);
		return to_return;
	}
}

Node* delete_at_tail(Node* head)
{
	if (is_empty(&head)) return NULL;
	else if(head->next ==NULL)
	{
		free(head);
		return NULL;
	}
	else {
		Node* current = head;
		Node* prev = NULL;

		while (current->next != NULL) {
			prev = current;
			current = current->next;
		}
		
		prev->next = NULL;
		free(current);
		return head;
	}
}

int length(Node* head) {
	if (head == NULL) {
		return 0;
	}
	else {
		return 1 + length(head->next);
	}
}

bool is_member(Node* head, int find_val) {
	if (head == NULL)return false;
	else if (head->value == find_val)return true;
	else return is_member(head->next, find_val);
}

void freeList(Node* head)
{
	Node* tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}

}

int main() {

	Node* list1_head = NULL;

	list1_head = insert_at_head(list1_head, 7);
	list1_head = insert_at_head(list1_head, 3);

	list1_head = insert_at_tail(list1_head, 14);
	list1_head = insert_at_tail(list1_head, 44);
	print_list(list1_head);

	list1_head = insert_at_middle(list1_head, 66, 2);
	list1_head = delete_at_head(list1_head);
	
	print_list(list1_head);
	printf("The length of the list is: %d \n",length(list1_head));

	if (is_member(list1_head, 7)) printf("it is in the list");
	else printf("not here");
	freeList(list1_head);
	/*
	Node a, b, c;
	a.value = 5;
	b.value = 6;
	c.value = 7;

	a.next = &b;//will give me the memory location of b
	b.next = &c;
	c.next = NULL; //tail

	print_list(&a);
	*/
	return 0;
}
