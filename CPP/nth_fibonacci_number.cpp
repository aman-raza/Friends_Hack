#include<bits/stdc++.h>
using namespace std;
int fib(int n) 
{ 
	int a = 0, b = 1, c, i; 
	if( n == 0) 
		return a; 
	for (i = 2; i <= n; i++) 
	{ 
		c = a + b; 
		a = b; 
		b = c; 
	} 
	return b; 
} 
  
int main () 
{ 
	int n;
	cout<<"Enter the term you want to get: ";
	cin>>n;
	cout<<"The fibonacci number is: "<<fib(n)<<"\n";
	return 0; 
} 
