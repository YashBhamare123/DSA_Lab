#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Stack{
    Node *Top;
};

void push(Stack *st, int x){
    Node *node = new Node;
    if (node == NULL){
        cout <<"Heap is full"<<endl;
    }
    else {
    node ->data = x;
    node ->next = st -> Top;
    st->Top = node;
    }
}

int pop(Stack *st){
    if(st -> Top -> next == NULL){
        cout<<"Stack Empty"<<endl;
        return -1;
    }
    else{
        int x = st->Top->data;
        Node *next = st ->Top->next;
        delete st->Top;
        st ->Top = next;
        return x;
    }
}

int peek(Stack st, int index){
    while (index != -1){
        if (st.Top -> next == NULL || index < 0)
        cout <<"Invalid Index"<<endl;

        else {
            st.Top = st.Top -> next;
        }
        index--;
    }
    return st.Top->data;
}

int main(){
    Node *head = new Node;
    Stack *st = new Stack;
    st -> Top = head;

    for (int i =0; i < 10; i ++){
        push(st, i);
    }

    for (int i =0; i < 20; i++){
        cout<<pop(st)<<endl;
    }

    push(st, 20);
    push(st, 30);

    cout<<pop(st)<<endl;
    cout<<pop(st)<<endl;
}

