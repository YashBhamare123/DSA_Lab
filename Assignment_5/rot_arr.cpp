#include <iostream>
using namespace std;

void revArr(int *arr, int size){
    int index = 0;
    while(!(index == size - index - 1 || index - 1 == size - index - 1 || size == 0)){
        int tmp = arr[index];
        arr[index] = arr[size - index - 1];
        arr[size- index- 1] = tmp;
        index++;
    }
}

void rotArr(int *arr, int k, int size){
    cout<<"start";
    revArr(arr, size);
    cout<<"rev done";
    revArr(arr, k);
    cout<<"first rev";
    revArr(arr + k, size - k);
}

int main(){
    int* arr = new int[7]{1};
    rotArr(arr, 1, 1);
    for (int i=0; i< 1; i++){
        cout<<arr[i]<<endl;
    }
}
