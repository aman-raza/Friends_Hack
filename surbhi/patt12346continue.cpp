#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int n,i,j,k;
	cout << "Enter n"  << endl;
	cin >> n;
    for(i=1;i<=n;i++)
    {
        k=i;
        //logicto print number..........
        for(j=1;j<=i;j++,k++)
        {
            cout<<k;
        }
    cout<<endl;
	}
    return 0;
}
  
