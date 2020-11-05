// Code for running Bubble Sort on any given Array with user input
// Made On C++ Language
// Made By Dhruv Sondhi on 03/10/2020

#include <bits/stdc++.h>

using namespace std;

//Bubble Sort Implementation 
void bubbleSort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
            // Swapping Of the values in the array 
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n=0;
    //No Of Elements in the array by the user 
    cin>>n;
    
    int a[n]={0};
    //Input of the elements in array 
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //Bubble Sort on the given array
    bubbleSort(a,n);
    
    //Display Of the Array
    cout<<"Sorted Array is: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
