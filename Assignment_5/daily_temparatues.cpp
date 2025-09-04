# include <iostream>
# include <stack>
# include <tuple>
using namespace std;

void nextGreater(int *arr, int *out, int size, stack<tuple<int, int>> st){
    for(int i =size -1; i>=0; i--){
        if (i == size -1){
            out[i] = -1;
        }

        else if(arr[i + 1] > arr[i]){
            out[i] = 1;
            st.push(make_tuple(arr[i+1], i+1));
        }

        else if(arr[i+1]<=arr[i]){
            while(!(st.empty() || (get<0>(st.top()) > arr[i]))){
                st.pop();
            }

            if (st.empty()) {
                out[i] = -1;
            }

            else{
                out[i] =get<1>(st.top()) - i;
            }
        }
    }
}

int main(){
    stack<tuple<int, int>> st;
    int size =3;
    int arr[] = {30, 60, 90};
    int *out = new int[size];

    nextGreater(arr, out, size, st);
    
    for(int i=0; i<size; i++)
    cout<<out[i]<<", ";
}