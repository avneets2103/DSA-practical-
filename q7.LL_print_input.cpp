// Write a program to implement a linked list.

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

Node* take_input(){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* head = new Node(data);
    Node* temp = head;
    while (data!=-1)
    {
        cout<<"Enter data: "<<endl;
        cin>>data;
        if(data!=-1)
        {
        Node* next = new Node(data);
        temp->next=next;
        temp=temp->next;
        }
    }
    return head;
}

void print_LL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* head = take_input();
    print_LL(head);
    return 0;}
