#include <iostream>

using namespace std;
#include <vector>

vector<long long int> soe(long long int a){
vector<bool> ref(a+1);
vector<long long int> ans;
int i=2;
ans.push_back(2);
while(i<=a){
    for(int j=i*i;j<=a;j+=i){
        if(!ref[j])ref[j]=true;
    }
    i++;
    while(ref[i])i++;
   if(i<=a) ans.push_back(i);

}
return ans;

}

int main()
{
    long long int n;
    cout<<"enter number"<<endl;
    cin>>n;
    vector<long long int> primes=soe(n);
    cout<<"The primes which are less than or equal to "<<n<<" are:"<<endl;
    for(int i=0;i<primes.size();i++)cout<<primes[i]<<" ";
    cout<<endl;

}
