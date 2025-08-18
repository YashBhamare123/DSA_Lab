#include <iostream>
using namespace std;

struct Stack{
    int size;
    int Top;
    int *s;
};

void push(Stack *st, int x){
    if (st -> Top == st->size-1)
        cout<<"Stack Overflow"<<endl;
    
    else {
        ++(st -> Top);
        st->s[st->Top] = x;
    }
}

int pop(Stack *st){
    if (st -> Top == -1)
        cout<<"Stack Underflow"<<endl; 
    else{

        int x = st->s[st->Top];
        --(st->Top);
        return x;
    }
}

int peek(Stack *st, int index){
    if (index > Top){
        cout<<"Index is greater"<<endl;
    }
    else if (index < 0){
        cout<<"Not a valid index"<<endl;
    }
    else{
        return st->s[st->Top - index];
    }
}

bool isEmpty(Stack *st){
    if (st ->Top == -1){
        return true;
    }
    else return false;
}

int stackTop(Stack *st){
    if (st -> Top == -1){
        cout <<"Stack is empty"<<endl;
    }
    else return st->s[st->Top];
}

bool isFull(Stack *st){
    if (st->Top == st->size -1){
        return true;
    }
    else return false;
}

 