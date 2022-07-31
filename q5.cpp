//merge two sorted arrays:

#include<iostream>
using namespace std;

int* merged_arr(int* arr1,int n1, int* arr2, int n2){
    int i=0, j=0,k=0;
    int* arr=new int[n1+n2];
    while (i==n1-1 || j==n2-1)
    {
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        if(arr1[i]>arr2[j]){
            arr[k]=arr2[j];
            j++;
        }
        if(arr1[i]==arr2[j]){
            arr[k]=arr1[i];
            k++;
            arr[k]=arr2[j];
        }
        k++;
    }
    if(i!=n1-1){
        for (int i; i < n1; i++)
        {
            arr[k]=arr1[i];
            i++;
            k++;
        }
    }
    if(j!=n2-1){
        for (int j; j < n2; j++)
        {
            arr[k]=arr2[j];
            j++;
            k++;
        }
    }
    return arr;
}

int main(){
    return 0;}
