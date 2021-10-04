<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<       Program Check if two arrays are equal or not         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/*
Given two array of same size, find out if given arrays are equal or not.
Note: Two arrays are said to be equal if both of them contain same set of elements, although arrangements (or permutation) of elements may be different.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal..
For example, if A = [11, 12, 13] and B = [12, 11, 13] then answer is 1 and
if A = [11, 12, 13, 12, 13] and B = [12, 11, 13, 12, 13] then answer is 1 and
if A = [11, 12, 13] and B = [12, 13] then answer is 0.
Complete the function below to accept two arrays as parameters and return the answer as above.

Input Format

The 1st line contains an integer M, the number of elements in A and B.
The 2nd line contains M integers separated by space.
The 3rd line contains M integers separated by space.

Output Format

Print 1 or 0 as per the condition.

Sample Input->>

3
11 12 13
12 11 13

Sample Output->>

1
*/

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     Code Of Solution       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int arraysEqualorNot(vector<int> A, vector<int> B) {
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  for (int i = 0; i < A.size(); i++)
   {
       if(A[i] != B[i]){
           return 0;
       }
   }
   return 1;
}
