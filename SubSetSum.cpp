#include<bits/stdc++.h>
using namespace std;
#define fast_input ios_base::sync_with_stdio(false); cin.tie(NULL)
const double pi=3.141592653589793238460;

bool SubSet(long int arr[], long int size, long int sum){ // SubSet function which retrun true or false..
    
	bool mat[size+1][sum+1];
    
	for(int i=0; i<=size; i++){ //loop to check if the sum is 0 then the answer is true..
        mat[i][0]=true;
    }
    
	for(int i=1; i<=sum; i++){ //loop to check if the sum is not 0 then the answer is false..
        mat[0][i]=false;
    }
    
	for(int i=1; i<=size; i++){  //fill the k matrix with true and false..
        
		for(int j=1;j<=sum; j++){
            
			if(j>=arr[i-1]){
                mat[i][j]= mat[i-1][j] || mat[i-1][j-arr[i-1]]; 
            }
            
			if(j<arr[i-1]){
                mat[i][j]=mat[i-1][j];
            }
        }
    }

    return mat[size][sum];
    
}
int main() {
    fast_input;
	int TestCase;
	cin>>TestCase;
	while(TestCase--){   // number of Test case..
	    long int i, j, size, sum=0;
	    cin>>size;
	    long int arr[size];
	    for(i=0; i<size; i++){ 
	        cin>>arr[i];
	        sum+=arr[i];
	       }
	    
		if(SubSet(arr, size, sum/2)==true && sum%2==0) cout<<"YES"<<"\n"; // if it can partitioned into two parts such that the sum of the elements of both part is same  then print true..
	    else cout<<"NO"<<"\n"; // if not print false
	}
	
	return 0;
}
