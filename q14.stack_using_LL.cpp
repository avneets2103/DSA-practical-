// Write a program to implement a stack using a linked list.

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next=NULL;
    }
};

class stack{
    public:
    Node* head;
    int top;
    stack(){
        top=-1;
        head=NULL;
    }

    void push(int data){
        Node* temp = head;
        if(top==-1){
            temp=new Node(data);
            head=temp;
            top++;
            return;
        }
        Node* new_node=new Node(data);
        new_node->next=temp;
        temp=new_node;
        head=temp;
        top++;
    }

    int pop(){
        if(top==-1){
            cout<<"Empty stack: "<<endl;
            return -1;
        }
        Node* temp = head;
        int d = temp->data;
        temp=temp->next;
        head=temp;
        top--;
        return d;
    }

    int peek(){
        Node* temp = head;
        int d = temp->data;
        return d;
    }

    int size(){
        return top+1;
    }
};

int main(){
    stack* s= new stack();
    s->push(3);
    s->push(5);
    s->push(2);
    s->push(8);
    cout<<s->pop()<<endl;
    cout<<s->pop()<<endl;
    cout<<s->peek()<<endl;
    cout<<s->size()<<endl;
    return 0;}
