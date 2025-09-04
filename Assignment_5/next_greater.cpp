# include <iostream>
# include <stack>
using namespace std;

void nextGreater(int *arr, int *out, int size, stack<int> st){
    for(int i =size -1; i>=0; i--){
        if (i == size -1){
            out[i] = -1;
        }

        else if(arr[i + 1] > arr[i]){
            out[i] = arr[i+1];
            st.push(arr[i+1]);
        }

        else if(arr[i+1]<=arr[i]){
            while(!(st.empty() || (st.top() > arr[i]))){
                st.pop();
            }

            if (st.empty()) {
                out[arr[i]] = -1;
            }

            else{
                out[i] = st.top();
            }
        }
    }
}

int main(){
    stack<int> st;
    int size =4;
    int arr[] = {1, 2, 3, 4};
    int *out = new int[size];

    nextGreater(arr, out, size, st);
    
    for(int i=0; i<size; i++)
    cout<<out[i]<<", ";
}
