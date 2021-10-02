#include<iostream>
using namespace std;

int Fib(int n)
{
	if(n<=1)
	return n;
	return Fib(n-1)+Fib(n-2);	/*recusively add the numbers*/
}

int main()
{
	int n;  /*position of the element starting from 0...n*/
	cout<<"Enter the number :";
	cin>>n;
	cout<<"Number at "<<n<<"th place is "<<Fib(n)<<endl;
	return 0;
}

