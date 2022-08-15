// Write a program to print the elements of a linked list in reverse order without disturbing the linked list.

#include<iostream>
#include<stack>
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



stack<int> s;
//filling
stack<int> filling_stack(Node* head){
    while (head!=NULL)
    {
        s.push(head->data);
        head=head->next;
    }
    return s;
}

//printing
void print_the_stack(stack<int> s){
    while (s.size()!=0)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

void print_reverse(Node* head){
    stack<int> s = filling_stack(head);
    print_the_stack(s);
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

int main(){
    Node* head = take_input();
    print_reverse(head);
    return 0;}
