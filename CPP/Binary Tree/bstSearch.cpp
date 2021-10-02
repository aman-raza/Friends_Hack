// To Search a node of a given value in a Binary Search Tree
// Output 1- Present, 0 - Absent
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

bool Search(bstNode* root, int x){
    if(root == NULL)    return false;
    // ! Optional if (root->data == x)   return true;
    else if(root->data > x)     return Search(root->left, x);
    else if (root->data < x)    return Search(root->right, x); 
    return true;    
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
    cout << Search(root, 100) << endl;
    cout << Search(root, 10) << endl;
    cout << Search(root, 60) << endl;
    cout << Search(root, 220) << endl;
}

