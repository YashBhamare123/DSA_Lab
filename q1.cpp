#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next = NULL;
};

Node* insert_beg(Node* head, Node *current){
	current -> next = head;
	return current;
}

void insert_end(Node* head, Node *current){
	while (head -> next != NULL){
		head = head -> next;
	}

	head -> next = current;
}

void insert_index(Node* head, Node *current, int index){
	for (int i = 0; i< index -1; i++){
		if (head -> next != NULL)
		head = head -> next;
	}

	Node *tmp = head -> next;
	head -> next = current;
	current -> next = tmp;
}

Node* delete_beg(Node *head){
	if (head -> next != NULL)
	Node *tmp = head -> next;
	delete head;
	return tmp;
}

void delete_end(Node *head){
	while ((head -> next) -> next != NULL)
		head = head -> next;

	delete head-> next;
	head -> next = NULL;
}

void delete_index(Node *head, int index){
 	for (int i = 0; i< index - 2; i++){
		if (head -> next != NULL)
		head = head -> next;
	}

	 




int main(){
	
}
