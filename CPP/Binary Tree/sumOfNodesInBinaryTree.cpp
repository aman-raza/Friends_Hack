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

void sumOfNodes1(bstNode* root){
    int sum = 0;
    queue<bstNode*> q;
    queue<int> q1;
    q.push(root);
    while(!q.empty()){
        bstNode* current = q.front();
        sum += current->data;
        if(current->left)  q.push(current->left);
        if(current->right)  q.push(current->right);
        q.pop();
    }
    cout << sum <<  endl;
}

int sumOfNodes(bstNode* root){
    if(root == NULL)    return 0;
    return (root->data + sumOfNodes(root->left) + sumOfNodes(root->right));
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
    cout << sumOfNodes(root) << endl;
    sumOfNodes1(root);
}

