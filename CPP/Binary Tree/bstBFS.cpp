// To implement Breadth First Search in a Binary Search Tree
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

void BFS(bstNode* root){
    queue<bstNode*> q;
    queue<int> q1;
    q.push(root);
    while(!q.empty()){
        bstNode* current = q.front();
        q1.push(current->data);
        if(current->left)  q.push(current->left);
        if(current->right)  q.push(current->right);
        q.pop();
    }
    while(!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
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
    BFS(root);
}
