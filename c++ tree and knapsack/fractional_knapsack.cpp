//program to implement fractional knapsack in c++.

#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;
int main()
    {
     vector <pair <double,pair<int,int>>>v;
     int n,cap;
     cin>>n>>cap;
     int value,weight;
     for(int i=0;i<n;i++)
     {
         cin>>value>>weight;
         v.pb(mp((double)value/weight,mp(value,weight)));
     }
     sort(v.begin(),v.end());
     //int i=n-1;
     int maxCap=0;
     double maxVal=0.0;
     
     for(int i=n-1;i>=0;i--)
     {
         if(maxCap + v[i].s.s <= cap)
         {
         maxCap+=v[i].s.s;
         maxVal+=v[i].s.f;
         
         }
         else
         {
             int remain = cap-maxCap; 
            maxVal += v[i].s.f * ((double) remain / v[i].s.s); 
            break; 
             
             
         }
     }//while
     
     cout<<maxVal<<endl;
     return 0;
    }