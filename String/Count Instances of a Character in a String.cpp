
#include<iostream>
using namespace std;

int charCount(char myChar, string str) {
	int length;
	length = str.length();
	int Count = 0;

	for(int i =0;i<length;i++)
	{
		if(myChar==str[i])
		{
			Count++;
		}
	}
	return Count;

}
int main()
{
    string userstring;
    char finding;
cout<<"------------This is a program That  Count Instances of a given Character in a String.----------------"<<endl;
cout<<endl;
cout<<"Enter any string of any length? "<<endl;
    getline(cin,userstring);
    cout<<endl;
    cout<<"Enter the character that you want to search from String and count that instances?"<<endl;
    cin>>finding;
	cout<<endl;
    cout<<"Count of  given character in string is: "<<charCount(finding,userstring);
    cout<<endl;
return 0;

}

