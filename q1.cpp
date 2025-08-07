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
	Node *tmp;

	if (head -> next != NULL){
		cout << "inside";
		tmp = head -> next;
		cout<<head -> data<<endl;
		delete head;
		return tmp;
	}

	else{
		cout << "Nothing to Delete" << endl;
		return head;
	}
}

void delete_end(Node *head){
	while (head -> next != NULL && (head -> next) -> next != NULL)
		head = head -> next;
		delete head-> next;
		head -> next = NULL;
}

void delete_index(Node *head, int index){
 	for (int i = 0; i< index - 2; i++){
		if (head -> next != NULL)
		head = head -> next;
	}
	Node *tmp = (head -> next) -> next;
	delete head->next;
	head -> next = tmp;
}

void delete_element(Node *head, int element){
	int flag = 1;
	int index = 0;
	while (flag == 1){
		if ((head -> next) -> next != NULL && (head -> next) -> data != element){
			head = head -> next;
		}

		else if ((head -> next) -> data == element){
			Node *tmp = (head -> next) -> next ;
			delete head -> next;
			head -> next = tmp;
			flag = 0;
		}

		else if (((head -> next) -> next) -> data  == element){ ;
			delete (head -> next) -> next;
			flag = 0;
	
		}
	}
}

int search(Node *head, int element){
	int flag = 1;
	int index = 0;
	while (flag == 1){
		if (head -> next != NULL && head -> data != element){
			head = head -> next;
			index++;

		}
		else if (head -> data == element){
			flag = 0;
			return index;
		}

		else
		{
			return -1;
		}
	}

}


int main(){
	int num = 2;
	Node *head = new Node;
	while (true){
		cin >> num;
		if (num == 0){
			break;
		}

		else if (num != 1){
		Node *new_node = new Node;
		new_node -> data = num;
		head = insert_beg(head, new_node);		
		}
		else if (num == 1){
				head = delete_beg(head);
		}
		else{
			cout << "no ex";
		}
}
}
