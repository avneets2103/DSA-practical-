#include<iostream>
using namespace std;

void bubbleSort(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionSort(int* arr, int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i; j<n ; j++)
        {
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

void insertionSort(int* arr, int size){
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i-1;
        //shifting 
        while (arr[j]>current && j>-1)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
} 

//Quick SORT
//Time complexity: n.logn
 
//Algo:
// Step1: We maintain a pivot element for every iteration, it is the first element of thw array (GENERALLY)
// Step2: Now we will find its correct position in the array using two variables i and j where i starts from the pivot, while j starts from the end of the array
// Step3: For this we do i++ till a[i]>pivot and a[j]<pivot and get values of i and j
// Step4: We then swap a[i] and a[j] in the array and this loops works until i<=j
// Step5: At the end of the loop we swap a[j] and pivot and pivot is now at its right pos
// Step6: As now the array is split into 2 halves i.e. left and right of the pivot thus we call recursion to repeat the same for them and we are done sorting.

void swap(int &a,int &b){
    int c = a;
    a=b;
    b=c;
}

int partition(int* arr, int low, int high){
    int pivot=arr[low];
    int i = low;
    int j = high;
    while (i<=j){
        while(arr[i]<=pivot){
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if(j>i){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[low]);
    return j;
}

void quick_sort(int* arr, int low, int high){
    if(low<high){
        int index=partition(arr,low,high);
        quick_sort(arr,low,index-1);
        quick_sort(arr,index+1,high);    
    }
}

//Merge Sort

int* merge(int* arr1,int low, int mid, int high){
    int i=0;
    int j=mid+1;
    int k=0;
    int* new_arr = new int[high-low+1];
    while (i<=mid && j<=high)
    {
        if(arr1[i]>arr1[j]){
            new_arr[k]=arr1[j];
            j++;
        }
        if(arr1[i]<arr1[j]){
            new_arr[k]=arr1[i];
            i++;
        }
        if(arr1[i]==arr1[j]){
            new_arr[k]=arr1[i];
            i++;
            k++;
            new_arr[k]=arr1[j];
            j++;
        }
        k++;
    }
    if(i!=mid){
        while (i!=mid+1)
        {
            new_arr[k]=arr1[i];
            i++;
            k++;
        }  
    }
    if(j!=high){
        while (j!=high+1)
        {
            new_arr[k]=arr1[j];
            j++;
            k++;
        }
    }
    return new_arr;
}

void merge_sort(int* arr, int low, int high){
    int n = high-low+1;
    if(low<high){
    merge_sort(arr,low,(n/2));
    merge_sort(arr,(n/2)+1,high);
    arr=merge(arr,low,n/2,high);
    }
}

int main(){
    cout<<"SIZE: "<<endl;
    int size;
    cin>>size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    // bubbleSort(arr,size);
    // selectionSort(arr,size);
    // quick_sort(arr,0,size-1);
    merge_sort(arr,0,size-1);

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;} 

