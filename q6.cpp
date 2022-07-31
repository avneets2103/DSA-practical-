#include<iostream>
using namespace std;

int main(){
    //static
    int arr[10][5];

    //dynamic
    int** arr2 = new int* [10];
    for (int i = 0; i < 10; i++)
    {
        arr2[i]=new int[5];    
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<"Enter marks of student "<<i+1<<" in subject number "<<j+1<<endl; 
            cin>>arr2[i][j];
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<"Marks of student "<<i+1<<" in subject number "<<j+1<<endl; 
            cout<<arr2[i][j]<<endl;
        }
    }
    
    return 0;}
