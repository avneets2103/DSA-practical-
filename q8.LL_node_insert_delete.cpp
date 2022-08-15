// Write a program to insert a node in a linked list and delete a node from a linked list.
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

Node* insertion(Node* head, int index, int element){
    if(index==0){//working
        Node* new_node= new Node(element);
        new_node->next=head;
        return new_node;
    }
    Node* new_node= insertion(head->next,index-1,element);//breaking
    head->next=new_node;//join again
    return head;
}

Node* deletion(Node* head, int index){
    if(index==0){
        return head->next;
    }
    Node* new_node=deletion(head->next, index-1);
    head->next=new_node;
    return head;
}

int main(){return 0;}
