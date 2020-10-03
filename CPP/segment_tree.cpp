
// Example of using segment tree ,  here we are calculating sum of intervals.

#include<bits/stdc++.h>
using namespace std;
#define vi               vector<int>
#define pii              pair<int,int>
#define vpii             vector<pii>
#define vs               vector<string>
#define si               set<int>
#define ff               first
#define ss               second
#define mii              map<int,int>
#define umii             unordered_map<int,int>
#define p_b              push_back
#define pqi               priority_queue<int>
#define loop(i,a,b)      for(int i=a;i<b;i++)
#define setbits(x)       __builtint_popcountll(x) //return no. of set bits in x
#define zerobits(x)      __buitlin_ctzll(x)       // return no. of zeroes after first set bit
#define int              long long
#define io          	 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define verify(try)      for(auto x : try)	cout<<x<<" ";
#define multipletest     int t;cin>>t;while(t--) 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////f//////////////////////////////////////////////////////////////////////////////


//val is the value which we have to store after updation , at index ind

void updateSegmentTree(int *a , int *tree , int start , int end , int treeNode , int ind , int val)
{
   
   if(start == end) // We start reflecting changes from base that is when there is only one element
   {
       a[ind] = val;
       tree[treeNode] = a[ind];
       return;
   }

   int mid = start + (end-start)/2;

   if(ind > mid)   // we have to search in right of segment tree
   	  updateSegmentTree(a , tree , mid + 1 , end , treeNode*2 + 1 , ind , val);
   
   else
      updateSegmentTree(a , tree , start , mid , treeNode*2 , ind , val);

   tree[treeNode] = tree[treeNode*2] + tree[treeNode*2 + 1];  // make an update from right and left updated segment tree.

}

int querry(int *tree , int treeNode , int start , int end , int left , int right) // return the answer between left and right inclusively
{
    // completely outside
       if(right < start || left > end)
       	  return 0;                     //cannot contribute to answer



    //completely inside
       	if( start >= left &&  end <= right)  //whole answer will be contrubuted
       		return tree[treeNode];



    //partially outside and partially inside 
       	int ans1 = querry(tree , 2*treeNode , start , (start + end)/2 , left , right);
       	int ans2 = querry(tree , 2*treeNode + 1 , (start + end)/2 + 1 , end ,left , right);

       	return ans1 + ans2; // return combined answer
}


void solve()
{
	 int n;
	 cin>>n;

	 int a[n] , tree[2*n];  // There are at max 2n - 1 nodes in a binary tree , (being n be size of array)

	 for(int i=0;i<n;i++) cin>>a[i];

     buildSegmentTree(a , tree , 1 , 0 , n-1);

     updateSegmentTree(a , tree , 0 , n-1 , 1 ,  5 , 10);

     for(int i=1 ; i < 2*n ; i++)
     	cout<<tree[i]<<endl;

     int ans = querry(tree ,  1 , 0 , n-1 , 2 , 4);

     cout<<ans<<endl;
}
int32_t main()
{
//	  multipletest
      solve();  
      return 0;
}
