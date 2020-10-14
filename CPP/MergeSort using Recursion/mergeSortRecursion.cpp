// Sorting of an array using Merge sorting algorithm with the help of recursion technique.
// Example input array with n=5 [98, 45, 10, 56, 5] the output array will be [5, 10, 45, 56, 98].

#include<iostream>
using namespace std;

void merge(int *a, int s, int e){
	int mid = (s+e)/2;
	int i=s;
	int j=mid+1;
	int k=s;
	int temp[100];
	while(i<=mid && j<=e){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}else{
			temp[k++]=a[j++];
		}
	}
	
	while(i<=mid){
		temp[k++]=a[i++];
	}
	while(j<=e){
		temp[k++]=a[j++];
	}
	for(int i=s;i<=e;i++){
		a[i]=temp[i];
	}
}
void mergeSort(int a[], int s, int e){
	//base case
	if(s>=e){
		return ;
	}
	
	int mid= (s+e)/2;
	
	mergeSort(a,s,mid);
	mergeSort(a,mid+1,e);
	
	merge(a, s, e);
}
int main(){
	int a[100], x;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		a[i]=x;
	}
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
