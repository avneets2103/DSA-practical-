// Write a program to implement a circular queue using an array.

#include<iostream>
using namespace std;

class CircularQueue{
    int front;
    int rear;
    int* arr;
    int size;
    int n;
    CircularQueue(int a){
        front=-1;
        rear=-1;
        n=0;
        size=a;
        arr = new int[size];
    }

    public:
    void push(int element){
        if(front==-1){
            arr[++front]=element;
            rear++;
            n++;
            return;
        }
        if ((front==0 && rear==size-1)||(front-1==rear))
        {
            cout<<"FILLED ALREADY"<<endl;
            return;
        }
        if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=element;
            n++;
            return;
        }
        arr[++rear]=element;
        n++;
        return;
    }

    int pop(){
        if(n==0){
            cout<<"Empty queue"<<endl;
            return -1;
        }
        if(front>0 && rear==0){
            rear=size-1;
            n--;
            return arr[0];
        }
        n--;
        return arr[rear--];
    }

    int size(){
        return n;
    }
};



int main(){return 0;}
