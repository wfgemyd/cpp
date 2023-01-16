#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
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

Node* delete_first_match(Node* head, int delete_value, bool* was_deleted)
{
	if (head == NULL)
	{
		*was_deleted = false;
		return NULL;
	}

	if (head->value == delete_value)
	{
		Node* temp = head->next;
		free(head);
		*was_deleted = true;
		return temp;
	}

	Node* current = head->next;
	Node* prev = head;

	while (current != NULL)
	{

		if (current->value == delete_value)
		{
			prev->next = current->next;
			free(current);
			*was_deleted = true;
			return head;
		}

		prev = current;
		current = current->next;
	}

	*was_deleted = false;
	return head;
}

Node* delete_all_matches(Node* head, int delete_value,
	int* num_deleted)
{
	Node* current = head;
	bool deleted = false;
	*num_deleted = 0;

	do
	{
		current = delete_first_match(current, delete_value, &deleted);
		if (deleted) *num_deleted = *num_deleted + 1;
	} while (deleted);

	return current;
}

Node* efficent_delete_match(Node* head, int delete_value,
	int* num_deleted) {
	*num_deleted = 0;
	if (head == NULL)return NULL;
	
	Node* current, *temp, *new_head;
	current = head;
	while (current->value == delete_value) {
		temp = current;
		current = current->next;
		free(temp);
		*num_deleted = *num_deleted + 1;
		if (current == NULL) return NULL;
	}
	new_head = current;
	while (current->next != NULL) {
		if (current->next->value == delete_value) {
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			*num_deleted = *num_deleted + 1;
		}
		else current = current->next;
	}
	return new_head;

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

int count_matches(Node* head, int find_val) {
	if (is_empty)return 0;
	else if (head->value == find_val) return 1 + count_matches(head->next, find_val);
	else return count_matches(head->next, find_val);
}

void replace_matches(Node* head, int find_value, int replace_value)
{
	if (head != NULL)
	{
		if (head->value == find_value)
			head->value = replace_value;

		replace_matches(head->next, find_value,
			replace_value);
	}
}

Node* append_list(Node* head1, Node* head2) {
	if (head1 == NULL) return head2;

	Node* current = head1;
	while (current->next != NULL) current = current->next;
	current->next = head2;
	return head1;
}

Node* reverse_list(Node* head) {
	if (head == NULL) return NULL;
	if (head->next == NULL) return head;

	Node* current = head;
	Node* next_node = head->next;
	current->next = NULL;

	while (next_node != NULL) {
		Node* tmp = next_node->next;
		next_node->next = current;
		current = next_node;
		next_node = tmp;
	}
	return current;
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

	bool deleted =false;
	
	list1_head = insert_at_middle(list1_head, 66, 2);
	list1_head = delete_at_head(list1_head);
	
	print_list(list1_head);
	printf("The length of the list is: %d \n",length(list1_head));

	replace_matches(list1_head, 7, 33);

	if (is_member(list1_head, 7)) printf("it is in the list");
	else printf("not here");

	printf("\n \n________ \n \n");
	list1_head = delete_first_match(list1_head, 44, &deleted);
	
	print_list(list1_head);

	//______________________________________

	Node* list2_head = NULL;
	int num_deleted = 0;
	list2_head = insert_at_head(list2_head, 7);
	list2_head = insert_at_head(list2_head, 4);
	list2_head = insert_at_head(list2_head, 2);
	list2_head = insert_at_head(list2_head, 7);
	list2_head = insert_at_head(list2_head, 7);
	list2_head = insert_at_head(list2_head, 6);
	list2_head = insert_at_head(list2_head, 7);
	print_list(list2_head);

	list2_head = efficent_delete_match(list2_head, 7, &num_deleted);

	print_list(list2_head);

	//____________________________ preformance test
	Node* list_test = NULL, *list_test2 = NULL;
	for (int i = 0; i < 50000; i++)
		list_test = insert_at_head(list_test, i % 10);
	for (int i = 0; i < 50000; i++)
		list_test2 = insert_at_head(list_test2, i % 10);
	clock_t tic, toc;
	tic = clock();
	list_test = delete_all_matches(list_test, 4, &num_deleted);
	toc = clock();
	printf("delete_all_matches:%fs\n",
		(double)(toc - tic) / CLOCKS_PER_SEC);
	printf("elements deleted: %d\n", num_deleted);

	tic = clock();
	list_test2 = efficent_delete_match(list_test2, 4, &num_deleted);
	toc = clock();
	printf("efficent_delete_match:%fs\n",
		(double)(toc - tic) / CLOCKS_PER_SEC);
	printf("elements deleted: %d\n", num_deleted);
	freeList(list_test);
	freeList(list_test2);

	//__________________________
	printf("\n\n\n\n");
	print_list(list1_head); print_list(list2_head);
	list1_head = append_list(list1_head, list2_head);
	print_list(list1_head);

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
