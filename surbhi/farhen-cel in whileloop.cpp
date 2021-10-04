#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
  int s,e,w;
    cin>>s>>e>>w;
    int f=s;
    while(f<=e){
    	//farhen celcius......................................
        int c=(int)((5.0/9)*(f-32));
        cout<<f<<"\t"<<c<<endl;
        f=f+w;
    }
}


