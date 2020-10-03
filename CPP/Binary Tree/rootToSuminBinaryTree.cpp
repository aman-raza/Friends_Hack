#include<bits/stdc++.h>
using namespace std;

struct bstNode{
    int data;
    bstNode* right;
    bstNode* left;
};

bstNode* getNewNode(int x){
    bstNode* temp = new bstNode;
    temp->data = x;
    temp->right = temp->left = NULL;
    return temp;
}

bstNode* Insert(bstNode* root, int x){
    if(root == NULL)    root = getNewNode(x);
    else if(root->data > x) root->left = Insert(root->left, x);
    else if(root->data < x) root->right = Insert(root->right, x);
    return root; 
}

bool rootToLeafSum(bstNode* root, int sum, vector<int> &list){
    if(root == NULL)    return false;
    if(root->left == NULL && root->right == NULL){  // check for Leaf Node
        if(root->data == sum){
            list.push_back(root->data);
            return true;
        }
        else    return false;
    }
    if(rootToLeafSum(root->left, sum -root->data, list)){
        list.push_back(root->data);
        return true;
    }
    else if(rootToLeafSum(root->right, sum- root->data, list)){
        list.push_back(root->data);
        return true;
    }
    return false;
}


int main(){
    bstNode* root = NULL;
    root = Insert(root, 100);
    root = Insert(root, 110);
    root = Insert(root, 120);
    root = Insert(root, 10);
    root = Insert(root, 700);
    root = Insert(root, 400);
    root = Insert(root, 500);
    root = Insert(root, 60);
    root = Insert(root, 320);
    vector<int> hello;
    rootToLeafSum(root, 170, hello);
    for (auto i = hello.end()-1; i >=hello.begin(); i--)
    {
        cout << *i << " ";
    }
    
}

/*
The given tree:

            100
           /   \      
          10    110
          \       \
          60      120
                    \
                     700
                    /
                   400
                  /   \
                 320   500


*/