// Write a program to insert one element in an array and delete an element from an array.

#include<iostream>
using namespace std;

void arr_insertion(int* arr, int n, int new_element, int pos){
    if(n<pos){
        return;
    }
    for (int i = n; i>pos ; i++)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=new_element;
}

void arr_deletion(int* arr, int pos, int n){
    if(pos>=n){
        return;
    }
    for (int i = pos; i < n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n]='\0';
}

void print_arr(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"INSERTION:"<<endl;
    cout<<"Enter position for insertion: "<<endl;
    int pos_i;
    cin>>pos_i;
    int new_number;
    cout<<"Enter number to add at the "<<pos_i<<" position: "<<endl;
    cin>>new_number;
    arr_insertion(arr,n,new_number,pos_i);
    n++;
    cout<<"DELETION:"<<endl;
    int pos_d;
    cout<<"Enter position for deletion: "<<endl;
    cin>>pos_d;
    arr_deletion(arr,pos_d,n);
    n--;
    cout<<"Final array is: "<<endl;
    print_arr(arr,n);
    return 0;}
