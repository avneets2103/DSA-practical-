// Write a program to find the mean and the median of the numbers stored in an array.

#include<iostream>
using namespace std;

pair<float,float>* mean_and_median(float* arr, float n){
    pair<float,float>* p;

    float sum;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    p->first=(sum/n);
    int m = n;
    if(m%2!=0){
        p->second=arr[m/2];
    }
    else{
        float n1 = arr[m/2];
        float n2 = arr[(m/2)-1];
        p->second=(n1+n2)/2.0;
    }
    return p;
} 

int main(){
    int n;
    cin>>n;
    float* arr = new float[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    float m = n;
    float mean=mean_and_median(arr,m)->first;
    float median=mean_and_median(arr,m)->second;
    cout<<"MEAN: "<<mean<<endl;
    cout<<"MEDIAN: "<<median<<endl;
    return 0;}
