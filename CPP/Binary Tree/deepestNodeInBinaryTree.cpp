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

int heightOfBT(bstNode* root){
    if(root == NULL)    return -1;
    int left = heightOfBT(root->left);
    int right = heightOfBT(root->right);
    return(max(left, right) +1);
}

void deepestNodeInBT(bstNode* root, int level,vector<int> &deepestNode ){
    if(root == NULL)    return;
    if(level == 0){
        deepestNode.push_back(root->data);
    }
    deepestNodeInBT(root->left, level -1, deepestNode);
    deepestNodeInBT(root->right, level -1, deepestNode);
    return;
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
    root = Insert(root, 800);
    root = Insert(root, 920);
    vector<int> nodes;
    deepestNodeInBT(root, heightOfBT(root), nodes);
    for(auto i = nodes.begin(); i!= nodes.end(); i++){
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
                    /   \
                   400   800
                  /   \     \
                 320   500   920

*/