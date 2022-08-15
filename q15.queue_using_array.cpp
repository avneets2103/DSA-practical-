// Write a program to implement a queue using an array.
#include<iostream>
using namespace std;

class queue{
    int front;
    int top;
    int capacity=2;
    int* arr;

    public:
    queue(){
        arr=new int[capacity];
        top=-1;
        front=-1;
    }

    int pop(){
        if(front>top || front==-1){
            cout<<"Empty queue"<<endl;
            return -1;
        }
        return arr[front++];
    }

    void push(int data){

        if(front==-1){
            arr[++front]=data;
            top++;
            return;
        }
        if (front>top)
        {
            arr[front]=data;
            top++;
            return;
        }
        

        if(top+1==capacity){
            int* new_arr = new int[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                new_arr[i]=arr[i];
            }
            arr=new_arr;
            capacity*=2;
        }
        arr[++top]=data;
    }

    int peek(){
        if(front>top || front==-1){
            cout<<"Empty queue"<<endl;
            return -1;
        }
        return arr[front];
    }

    int size(){
        if(front==-1){
            return 0;
        }
        return top-front+1;
    }
};

int main(){
    queue* q = new queue();
    q->push(0);
    q->push(1);
    q->push(2);
    q->push(3);
    cout<<q->pop()<<endl;
    cout<<q->pop()<<endl;
    cout<<q->peek()<<endl;
    cout<<q->size()<<endl;
    return 0;
}
