#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Queue{
   Node *Front;
   Node *Rear;

};

void enqueue(Queue *qu, int element){
    Node *tmp = new Node;
    qu->Front->next = tmp;
    qu->Front = tmp;
    qu->Front->data = element;
}

int dequeue(Queue *qu){
    if (qu->Front == qu->Rear){
        cout<<"Queue is Empty"<<endl;
        return -1;
    }
    else{
        Node *tmp = qu->Rear->next;
        delete qu->Rear;
        qu->Rear = tmp;
        return qu->Rear->data;
    }
}

bool isEmpty(Queue qu){
    if (qu.Front == qu.Rear) return true;
    else return false;
}

int peek(Queue qu){
    if (!isEmpty(qu)) return qu.Rear->next->data;
    else{
        cout<<"Queue is Empty"<<endl;
        return -1;
    }
}

void display(Queue qu){
    while(!isEmpty(qu)){
        qu.Rear = qu.Rear->next;
        cout<<qu.Rear->data<<endl;
    }
}

int main(){
    Queue *qu = new Queue;
    qu->Front = new Node;
    qu->Rear = qu->Front;

    for (int i=0; i<10; i++){
        enqueue(qu, i);
    }

    display(*qu);

    for (int i=0; i<11; i++){
        dequeue(qu);
    }

    for (int i=0; i<10; i++){
        enqueue(qu, 2*i);
    }

    display(*qu);
    cout<<peek(*qu)<<endl;   
}

