/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//#author-Preeti
//Program to find the level of a binary tree which has the maximum sum of the values of node.
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root==0)
            return 0;
        int res=INT_MIN;
        int point=1;
        int lev=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            int sum=0;
            for(int i=0;i<len;i++)
            {
                
                auto z=q.front();
                q.pop();
                sum+=z->val;
                if(z->left!=NULL)
                    q.push(z->left);
                if(z->right!=NULL)
                    q.push(z->right);
                
            }//for loop
            if(sum>res)
            {
                res=sum;
                lev=point;
            }
            point++;
            
        }
        return lev;
    }
};