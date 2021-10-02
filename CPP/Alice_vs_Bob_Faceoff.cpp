#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
#include<algorithm>
#include <vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstdlib>
#include<sstream>
#include <string.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define  rep(i,n,v) for(i=n;i<v;i++)
#define per(i,n,v) for(i=n;i>v;i--)
#define ff first 
#define ss second 
#define pp pair<ll,ll>
#define ll  long long
#define ld  long double
#define endl "\n"
 
const ll mod=1e9+7;
void solve()
{
ll  n, a=0,b=0,m=1, c=-1,k=0, i=0, j=0, l=1e9+5;
string s,p, q;
    // map<ll,ll>mp;
    // mp[1]=0;
    // mp[2]=1;
    // rep(i,3,1e5+1){
    //     if(i%2) {
    //         if(mp[i-1]==0) mp[i]=1;
    //         else mp[i]=0;
    //     }
    //     else{
    //         a=2;j=0;
    //         while(a<=i){
    //             if(i%a==0 && mp[i/a]==1){
    //                 j=1;mp[i]=0;break;
    //             }
    //             a*=2;
    //         }
    //         if(!j) mp[i]=1;
    //     }
    // }

cin>>a;
rep(i,0,a){
    cin>>n;
    if(n==1) cout<<"Alice"<<endl;
    else{
        if(n%2){
            n--;
            b=0;
            while(n){
                c=0;
                while(n%2==0) {
                    n/=2;c++;
                }
                n--;
                if(c>=2) b++;
            }
            if(b>=2) cout<<"Bob"<<endl;
            else{
                if(b==0) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
            }
        }
        else{
            b=0;
            while(n){
                c=0;
                while(n%2==0) {
                    n/=2;c++;
                }
                n--;
                if(c>=2) b++;
            }
            if(b>=2) cout<<"Alice"<<endl;
            else{
                if(b==0) cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
            }
        }
    }
    // if(mp[a]==0) cout<<"Alice"<<endl;
    // else cout<<"Bob"<<endl;
}
    // if(n==2 || n==5 || n==6 || n==9 || n==11 || n==13 || n==14 || n==17 || n==19)
    // cout<<"Bob"<<endl;
    // else cout<<"Alice"<<endl;
    // for(int i=1;i<1e6;i++) cout<<i<<" ";
}
int main()
{
ios_base::sync_with_stdio(false);
cin. tie(0);cout. tie(0);
ll t=1;
 //cin>>t;
while(t--)
{
solve();
}
return 0;
}