#include <iostream>
#include <string>
#include <tuple>
using namespace std;

template <typename T>
struct Stack {
    int size;
    int Top;
    T *s;
};

template <typename T>
void push(Stack<T> *st, T x) {
    if (st->Top == st->size - 1)
        cout << "Stack Overflow" << endl;
    else {
        st->Top++;
        st->s[st->Top] = x;
    }
}

template <typename T>
T pop(Stack<T> *st) {
    T x;
    if (st->Top == -1)
        cout << "Stack Underflow" << endl;
    else {
        x = st->s[st->Top];
        st->Top--;
    }
    return x;
}

template <typename T>
T peek(Stack<T> st){
    if (st.Top < 0){
        cout<<"Stack Empty"<<endl;
        return NULL;
    }
    else return st.s[st.Top];
}

template <typename T>
bool isEmpty(Stack<T> st){
    if (st.Top < 0) return true;
    else return false;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' ||
            c == '^' || c == '(' || c == ')');
}

tuple<int, int> gop(char c, bool stack){
    if(c == '+' || c == '-') return make_tuple(0, 0);
    else if(c == '*' || c == '/') return make_tuple(1, 0);
    else if(c == '^') return make_tuple(2,1);
    else if(c == '('){
        if (stack) return make_tuple(-1, 1);
        else return make_tuple(3, 1);
    }
    else if(c == ')') return make_tuple(3, 1);
    else return make_tuple(4, 0);
}



string prefix_infix(string prefix, Stack<string> *st) {
    int len = prefix.length();
    for (int i = len - 1; i >= 0; i--) {
        if (!isOperator(prefix[i])) {
            string s = string(1, prefix[i]);
            push(st, s);
        } else {
            string op1 = pop(st);
            string op2 = pop(st);
            char op = prefix[i];
            string out = "(" + op1 + string(1, op) + op2 + ")";
            push(st, out);
        }
    }

    string infix = pop(st);
    return infix;
}


string infix_postfix(string infix, Stack<char> *st){
    int exp_len = infix.length();
    string postfix = "";

    for (int i=0; i<exp_len; i++){

        char a = infix[i];
        char b;
        int prec_a, prec_b, asc_a, asc_b;
        tie(prec_a, asc_a) = gop(a, false);

        if (isEmpty(*st)){
            push(st, a);
        }

        else{
            b = peek(*st);
            tie(prec_b, asc_b) = gop(b, true);

            while (prec_a < prec_b && !isEmpty(*st)){
                b = pop(st);
                postfix += string(1, b);
                if (!isEmpty(*st)){
                    b = peek(*st);
                    tie(prec_b, asc_b) = gop(b, true);
                }
            }

            if (isEmpty(*st)) push(st, a);

            else if(a == ')'){
                bool found = false;
                while (!found){
                    b =pop(st);
                    if (b != '('){
                    postfix += string(1, b);
                    }
                    else found=true;
                }
            }

            else if(prec_a > prec_b) push(st, a);

            else if(prec_a == prec_b){
                if (asc_a == 0){
                    b = pop(st);
                    postfix += string(1, b);
                    push(st, a);
                }

                else push(st, a);
            }
        }
    }

    while(!isEmpty(*st)){
        postfix += string(1, pop(st));
    }

    return postfix;
}

int main() {
    Stack<char> *st = new Stack<char>;
    st->size = 100; 
    st->Top = -1;
    st->s = new char[st->size];

    string infix = "A+B*C-D/(E+F^G)";

    cout<<infix_postfix(infix, st)<<endl;

    delete[] st->s;
    delete st;

    return 0;  
}