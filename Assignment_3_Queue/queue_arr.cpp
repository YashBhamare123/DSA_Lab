#include <iostream>
using namespace std;

struct Queue {
    int size;
    int *q;
    int Front;
    int Rear;
};

void enqueue(Queue *qu, int element){
    if ((qu->Front + 1)%qu->size == qu->Rear){
        cout<<"Queue Full"<<endl;
    }
    else{
        qu->Front = (qu->Front + 1)%qu->size;
        qu->q[qu->Front] = element;
    }
}

int dequeue(Queue *qu){
    if (qu->Rear == qu->Front){
        cout<<"Queue Empty"<<endl;
        return -1;
    }
    else{
        qu->Rear = (qu->Rear + 1)%qu->size;
        return qu->q[qu->Rear];
    }
}

bool isEmpty(Queue qu){
    if(qu.Front == qu.Rear) return true;
    else return false;
}
bool isFull(Queue qu){
    if((qu.Front + 1)%qu.size == qu.Rear) return true;
    else return false;
    
}
int peek(Queue qu){
    if (!isEmpty(qu)) return qu.q[qu.Front];
    else{
        cout<<"Queue is Empty, nothing to peek"<<endl;
        return -1;
    }
}

void display(Queue qu){
    while(!isEmpty(qu)){
        qu.Rear = (qu.Rear + 1)%qu.size;
        cout<<qu.q[qu.Rear]<<endl;
    }
}


int main(){
    cout<<"Hi"<<endl;
    Queue *qu = new Queue;
    qu->size = 100;
    qu->Rear = 0;
    qu->Front = 0;
    qu->q = new int[qu->size];

    for (int i=0; i< 10; i++){
        enqueue(qu, i);
    }

    display(*qu);
    
    for (int i=0; i<11; i++){
        dequeue(qu);
    }

    for (int i=0; i< 101; i++){
        enqueue(qu, i);
    }

    display(*qu);
}
