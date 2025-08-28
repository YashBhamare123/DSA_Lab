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


// Stack Functions using Queue
struct Stack{
    Queue *qu;
    int num_elements;
};

void pushStack(Stack *st, int element){
    if (isFull(*st->qu)){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    else{
        if (isEmpty(*st->qu)){
            st->num_elements ++;
            enqueue(st->qu, element);
        }
        else{
            enqueue(st->qu, element);
            st->num_elements ++;
            for (int i=0; i< st->num_elements -1; i++){
                int tmp = dequeue(st->qu);
                enqueue(st->qu, tmp);
            }
        }
    }
}

int popStack(Stack *st){
    if (!isEmpty(*st->qu)){
        return dequeue(st->qu);
        st->num_elements--;
    }
    else{
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
}

bool isEmptyStack(Stack st){
    if (isEmpty(*st.qu)) return true;
    else return false;
}

int peekStack(Stack st){
    if (isEmptyStack(st)){
        cout<<"Nothing to Peek"<<endl;
        return -1;
    }
    else return peek(*st.qu);
}

int main(){
    Queue *qu = new Queue;
    qu->size = 100;
    qu->Front = -1;
    qu->Rear = -1;
    qu->q = new int[qu->size];

    Stack *st = new Stack;
    st->qu = qu;
    st->num_elements = 0;

    for (int i=0; i<10; i++){
        pushStack(st, i);
    }

    for (int i=0; i< 11; i++){
        cout<<popStack(st)<<endl;
    }

    for (int i=0; i<101; i++){
        pushStack(st, i);
    }
}