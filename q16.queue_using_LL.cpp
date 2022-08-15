// Write a program to implement a queue using a linked list.

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class queue{
    Node* head;
    Node* tail;
    int s;

    public:
    queue(){
        head=NULL;
        tail=NULL;
        s=0;
    }

    void push(int data){
        s++;
        if(head==NULL){
            head=new Node(data);
            tail=head;
            return;
        }
        Node* new_node= new Node(data);
        tail->next=new_node;
        tail=new_node;
    }

    int pop(){
        if(head==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        s--;
        int return_val=head->data;
        head=head->next;
        return return_val;
    }

    int peek(){
        if(head==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }

    int size(){
        return s;
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
    return 0;}

