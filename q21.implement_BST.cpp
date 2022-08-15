// Write a program to construct a binary search tree.

#include<iostream>
using namespace std;

class BinaryTree{
    public:
    int data;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

BinaryTree* takeInput(){
    cout<<"Enter the root data: "<<endl;
    int root_data;
    cin>>root_data;

    if(root_data==-1){
        return NULL;
    }

    BinaryTree* root = new BinaryTree(root_data);
    BinaryTree* temp = root;
    while(1){
        BinaryTree* new_node=takeInput();
        if(new_node->data<root_data){
            root->left=new_node;
        }
        if(new_node->data>root_data){
            root->right=new_node;
        }
        if(new_node==NULL){
            break;
        }
    }
    return root;
}

void printBT(BinaryTree* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    printBT(root->left);
    printBT(root->right);
}

int main(){
    BinaryTree* root = takeInput();
    printBT(root);
    return 0;}
