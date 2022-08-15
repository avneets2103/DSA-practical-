// Write a program to search for a number in an array.

#include<iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        return binarySearch(arr, mid + 1, r, x);
    } 
    return -1;
}
  
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int element;
    cout<<"Entet element to enter: "<<endl;
    cin>>element;
    cout<<"The index of "<<element<<" is: "<<binarySearch(arr,0,n-1,element);
    return 0;}
