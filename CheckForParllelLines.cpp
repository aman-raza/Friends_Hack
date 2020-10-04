//Code is for checking Parallel Lines using the coefficients of the equations 
//Made in C++
//Made by Dhruv Sondhi on 03/10/2020

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Line 1 coefficients
    int a1=0,b1=0,c1=0;
    //Line 2 coefficients
    int a2=0,b2=0,c2=0;
    cout<<"Enter coefficient of x in first eqaution :";
    cin>>a1;
    cout<<"Enter coefficient of y in first eqaution :";
    cin>>b1;
    cout<<"Enter coefficient of z in first eqaution :";
    cin>>c1;
    cout<<"Line Equation 1: "<<a1<<"x+"<<b1<<"y+"<<c1<<"z=0"<<endl;

    cout<<"Enter coefficient of x in second eqaution :";
    cin>>a2;
    cout<<"Enter coefficient of y in second eqaution :";
    cin>>b2;
    cout<<"Enter coefficient of z in second eqaution :";
    cin>>c2;
    cout<<"Line Equation 2: "<<a2<<"x+"<<b2<<"y+"<<c2<<"z=0"<<endl;

    double coeff1 = (double)a1/(double)a2;
    double coeff2 = (double)b1/(double)b2;

    if(coeff1==coeff2){
        cout<<"The Given Lines Are Parallel"<<endl;
    }
    else{
        cout<<"The Given Lines Are Not Parallel"<<endl;
    }
    return 0;
}
