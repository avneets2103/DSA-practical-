// Write a program to implement a stack using an array

#include<iostream>
using namespace std;

class stack{
    int capacity = 2;
    int* arr;
    int top;
    stack(){
        arr = new int[capacity];
        top=-1;
    }

    public:
    void push(int data){
        // if((top+1)==capacity-1){
        //     //extend the array space
        //     int* temp_arr = new int[2*capacity];
        //     for (int i = 0; i < capacity; i++)
        //     {
        //         temp_arr[i]=arr[i];
        //     }
        //     arr=temp_arr;
        //     capacity=2*capacity;
        // }
        top++;
        arr[top]=data;
    }

    int pop(){
        if(top==-1){
            cout<<"Empty stack"<<endl;
            return -1;
        }
        return arr[top--];
    }

    int peek(){
        if(top==-1){
            cout<<"Empty stack"<<endl;
            return -1;
        }
        return arr[top];
    }

    int size(){
        return top+1;
    }
};

int main(){return 0;}
