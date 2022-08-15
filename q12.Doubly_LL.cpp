// Write a program to implement a doubly-linked list.

#include<iostream>
using namespace std;

class DoubleNode{
    public:
    int data;
    DoubleNode* next;
    DoubleNode* prev;
    DoubleNode(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};

DoubleNode* takeInput(){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    DoubleNode* head = new DoubleNode(data);
    DoubleNode* temp = head;
    while(1){
        cin>>data;
        if(data==-1){
            break;
        }
        DoubleNode* new_node=new DoubleNode(data);
        temp->next=new_node;
        new_node->prev=temp;
        temp=temp->next;
    } 
    return head;
}

void print_doublyLL(DoubleNode* head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    DoubleNode* head = takeInput();
    print_doublyLL(head);
    return 0;}
