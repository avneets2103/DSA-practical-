// Write a program to reverse a linked list.

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

//iterative
Node* reverse_LL(Node* head){
    Node* temp1 = head;
    Node* temp2 = head->next;
    head->next=NULL;
    while(temp2!=NULL){
        Node* temp3 = temp2->next;
        temp2->next=temp1;
        temp1=temp2;
        temp2=temp3;
    }
    return temp1;
}

//recursive
Node* reverseLL(Node* head){
    if(!head || !(head->next)){
        return head;
    }
    auto res = reverseLL(head->next);
    head->next->next=head;
    head->next=NULL;
    return res;
}

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
    Node* head1 = reverse_LL(head);
    print_LL(head1);
    return 0;}
