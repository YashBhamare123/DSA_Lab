#include <iostream>
#include <deque>
#include <tuple>
using namespace std;

void slidingWindow(int *arr, int *out, int size, int k, deque<tuple<int, int>> dq){
    for (int i=0; i<size; i++){
        if (i < k-1){
            while(!dq.empty() && arr[i] > get<0>(dq.back())){
                dq.pop_back();
            }
                dq.push_back(make_tuple(arr[i], i));
        }

        else{
            if (!dq.empty() && get<1>(dq.front()) == i -k){
                dq.pop_front();
            }

            while(!dq.empty() && arr[i] > get<0>(dq.back())){
                dq.pop_back();
            }
            dq.push_back(make_tuple(arr[i], i));

            out[i - k + 1] = get<0>(dq.front());
        }
    }
}

int main(){
    int size = 6;
    int *arr = new int[size]{1, 2, 5, 2, 7, 9};
    int k = 1;
    deque<tuple<int, int>> dq;
    int *out = new int[size -k + 1];
    slidingWindow(arr, out, size, k, dq);
    
    for (int i =0; i<size -k + 1; i++){
        cout<<out[i]<<endl;
    }
}