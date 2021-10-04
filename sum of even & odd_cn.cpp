#include<iostream>
using namespace std;

int main() {
	// Write your code here
	
   int n, sumEven = 0, sumOdd = 0, r;//last number

   cin>>n;

   while ( n> 0)

   {

       r = n % 10;

       if (r % 2 == 0)

       {

         sumEven = sumEven + r;

       }

     else

     {

         sumOdd = sumOdd + r;

     }

       n = n/ 10;

   }

   cout << sumEven << " " <<sumOdd;

   return 0;

}


