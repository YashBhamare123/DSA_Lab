#include <iostream>
using namespace std;


template <typename T>
class Array{
    public: 
    int num_elements = 0;
    int size = 2;
    T *arr = new T[size];

    void push(T element){
        if (num_elements == size){
            T* new_arr = new T[size * 2];
            size = size * 2;

            for (int i =0; i <num_elements; i++){
                new_arr[i] = arr[i];
            }

            delete[] arr;
            arr = new_arr;

            arr[num_elements] = element;
            num_elements = num_elements + 1;
        }

        else{
            arr[num_elements] = element;
            num_elements = num_elements + 1;
        }
    }

    T pop(){

        if (num_elements == 0){
            cout<< "Nothing to Pop"<<endl;
        }


        else if(size == num_elements * 4){
            T* new_arr = new T[size / 4];
            size = size / 4;

            for (int i=0; i <num_elements; i++){
                new_arr[i] = arr[i];
            }

            delete []arr;
            arr = new_arr;
            
            T tmp = arr[num_elements - 1];
            arr[num_elements - 1] = NULL;
            num_elements = num_elements -1;
            return tmp;
        }
        else{
            T tmp = arr[num_elements - 1];
            num_elements = num_elements -1;
            arr[num_elements] = NULL;
            return tmp;
        }
    }

    void peek(){
        if (num_elements != 0){
        cout << arr[num_elements - 1]<<endl;
        }
        else cout<< "Stack is empty"<<endl;
    }

    int isFull(){
        if (num_elements == size){
            return 1;
        }
        else 
        return 0;
    }

    int isEmpty(){
        if (num_elements == 0){
            return 1;
        }
        else return 0;
    }
};


int main(){
    Array <char>arr;
    for (int i = 0; i < 10; i++){
        arr.push('c');
    }
    arr.pop();
    arr.pop();
    arr.peek();
    for (int i =0; i < 20; i++){
        arr.pop();
        arr.peek();
    }
    arr.isEmpty();
    arr.push('c');
    cout<<"Array Size: "<<arr.size<<endl;
    arr.push('c');
    arr.peek();
    cout<<arr.size<<endl;
    cout << "Is Array Full"<< arr.isFull()<< endl;
}
