#include <iostream>
using namespace std;

struct Stack{
    int Top;
    int size;
    int *s;
};

void push(Stack *st, int element){
    if (st->Top == st->size -1){
        int *ptr;
        int prev_size;
        if (st->size == 0)
        ptr = new int[1];
        else 
        ptr = new int[st->size * 2];

        if (ptr == NULL){
            cout<<"Heap Full"<<endl;
            return;
        }

        prev_size = st->size;
        if (st->size == 0) st->size = 1;
        else st->size *= 2;

        for (int i=0; i< prev_size; i++){
            ptr[i] = st->s[i];
        }

        if (st->s != NULL) delete st->s;
        st->s = ptr;
        st->Top = st->Top + 1;
        st->s[st->Top] = element;
    }

    else {
        st -> Top += 1;
        st->s[st->Top] = element;
    }
}

int pop(Stack *st){
    if (st->Top +1 <= st->size/4){
        int *ptr = NULL;
        if (st->Top >= 0) ptr = new int[st->Top + 1];
        for (int i =0; i<st->Top + 1; i++){
            ptr[i] = st->s[i];
        }

        st->size = st->Top + 1;
        if (st->s !=NULL && ptr != NULL) {
        delete st->s;
        st->s = ptr;
        int x = st->s[st->Top];
        st->Top = st->Top - 1;
        return x;
        }
        else{
            cout<<"Stack Underflow"<<endl;
            return -1;
        }    
    }
    else {
        int x = st->s[st->Top];
        st->Top = st->Top - 1;
        return x;
    }
    
}

int peek(Stack st){
    if(st.size == 0){
        cout<<"Stack Empty"<<endl;
        return -1;
    }
    else return st.s[st.Top];
}

int main(){
    Stack *st = new Stack;
    st->Top = -1;
    st->size = 0;
    
    for (int i=0; i<9; i++){
        push(st, i);
    }
    cout<<st->size<<endl;

    cout<<"Stack Values:"<<endl;
    for (int i=0; i<11; i++){
        cout<<"Value: "<<pop(st)<<endl;
        cout<<"Size: "<<st->size<<endl;
        cout<<"Top: "<<st->Top<<endl;

    }
}