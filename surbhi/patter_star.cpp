#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
  int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int s=1;
        while(s<=n-i)
        {
            cout<<" ";
            s=s+1;
        }
        int star=1;
        while (star<=2*i-1)
        {
            cout<<"*";
            star=star+1;
        }
        cout<<endl;
        i=i+1;
        }
}

