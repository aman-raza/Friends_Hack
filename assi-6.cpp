

#include<iostream>

using namespace std;

class student

{

	double x,y;

	public:

	     void accept();

	     void calculate();

	     };

void student::accept()

{

	cout<<"Enter any two Numbers\n";

	cin>>x>>y;

}

void student::calculate()

{

	try

	{
 
	  if(y==0)

 	  throw y;

 	  cout<<x/y;

	}

	catch(double y)

	{

	 cout<<"Divide By Zero";

	}

}


int main()

{

	student s;

	s.accept();

	s.calculate();

	return 0;

}
