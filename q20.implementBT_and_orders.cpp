// Write a program to construct a binary tree and display its preorder, inorder and postorder traversals.

#include<iostream>
using namespace std;

class BinaryTree{
    public:
    int data;
    BinaryTree*left;
    BinaryTree*right;
    BinaryTree(int data){
        this->data=data;
        right=NULL;
        left=NULL;
    }
};

BinaryTree* takeInput(){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTree* root = new BinaryTree(data);
    root->left=takeInput();
    root->right=takeInput();
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

void PreOrder(BinaryTree* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(BinaryTree* root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

void inOrder(BinaryTree* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){return 0;}
