/******************************************************************************

 a program to print all the LEADERS in the array. An element is leader if it is greater 
 than all the elements to its right side. And the rightmost element is always a leader. 
 For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2. 

*******************************************************************************/

#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int size, *arr;
	cout << "Enter size:: ";
	cin >> size;
	arr = new int[size];		
	cout << "Enter Leader elements:: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];		//input array element.		
	}
	cout << "Leaders are:: " << endl;

	for (int i = 0; i < size; i++)
	{
		int temp = arr[i];

		for (int j = i + 1; j < size; j++)
		{
			if (temp < arr[j])	//if it is greater than all the elements to its right side
				temp = arr[j];
		}

		if (arr[i] == temp)
			cout << temp<< endl;
	}
	
	return 0;
}
