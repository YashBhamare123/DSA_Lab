# include <iostream>
using namespace std;

// Stack Code
struct Stack{
    int size;
    int Top;
    int *s;
};

void push(Stack *st, int element){
    if(st->Top + 1 == st->size){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    else{
        st->Top++;
        st->s[st->Top] = element;
    }
}

int pop(Stack *st){
    if (st->Top < 0){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }

    else{
        int x = st->s[st->Top];
        st->Top--;
        return x;
    }
}

bool isEmpty(Stack st){
   if(st.Top < 0) return true;
   else return false;
}

int peek(Stack st){
    if(isEmpty(st)){
        cout<<"Nothing to peek"<<endl;
        return -1;
    }
    else return st.s[st.Top];
}

bool isFull(Stack st){
    if (st.Top + 1 == st.size) return true;
    else return false;
}


// Queue Implementation using 2 Stacks
struct Queue{
    Stack *inStack;
    Stack *outStack;
};

void enqueue(Queue *qu, int element){
    if (isFull(*qu->inStack)){
        cout<<"Queue is Full"<<endl;
        return;
    }
    else{
        push(qu->inStack, element);
    }
}

int dequeue(Queue *qu){
    if(!isEmpty(*qu->outStack)){
        return pop(qu->outStack);
    }
    else{
        if(isEmpty(*qu->inStack)){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else{
            while(!isEmpty(*qu->inStack)){
                push(qu->outStack, pop(qu->inStack));
            }
            return pop(qu->outStack);
        }
    }
}

bool isEmptyQueue(Queue qu){
    if (isEmpty(*qu.inStack) && isEmpty(*qu.outStack)) return true;
    else return false;
}

int peekStack(Queue *qu){
    if(isEmptyQueue(*qu)){
        cout<<"Nothing to peek in queue"<<endl;
        return -1;
    }
    else{
        if(!isEmpty(*qu->outStack)) return peek(*qu->outStack);
        else{
            while(!isEmpty(*qu->inStack)){
                push(qu->outStack, pop(qu->inStack));
            }
            return peek(*qu->outStack);
        }
    }
}


int main(){
    Stack *inStack = new Stack;
    inStack->size = 100;
    inStack->Top = -1;
    inStack->s = new int[inStack->size];

    Stack *outStack = new Stack;
    outStack->size = 100;
    outStack->Top = -1;
    outStack->s = new int[outStack->size];

    Queue *qu = new Queue;
    qu->inStack = inStack;
    qu->outStack = outStack;

    for (int i=0; i<10; i++){
        enqueue(qu, i);
    }


    for (int i=0; i<11; i++){
        dequeue(qu);
    }

    for (int i=0; i<10; i++){
        enqueue(qu, 2*i);
    }

    cout<<peekStack(qu)<<endl;   
}
     
