#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

tuple<int, int> bracePrec(char c){
    if (c == '(') return make_tuple(0, 0);
    else if (c == ')') return make_tuple(0, 1);
    else if (c == '{') return make_tuple(1, 0);
    else if (c == '}') return make_tuple(1, 1);
    else if (c == '[') return make_tuple(2, 0);
    else if (c == ']') return make_tuple(2, 1);
    else return make_tuple(-1, -1);
}

bool isValid(string str, stack<char> st){
    int len = str.size();
    for(int i= 0; i< len; i++){
        char c = str[i];
        tuple<int, int> prec = bracePrec(c);
        if (get<0>(prec) == -1){
            continue;
        }

        else if(get<1>(prec) == 0){
            st.push(c);
        }

        else if(get<1>(prec) == 1){
            if (get<0>(bracePrec(st.top())) == get<0>(prec)){
                st.pop();
            }
            else{
                return false;
            }
        }
    }

    if (st.empty()) return true;
    else return false;
}

int main(){
    stack<char> st;
    string str = "(a+B)-{c + d}*[e{f+f+g)}]";
    cout<<isValid(str, st);
}
