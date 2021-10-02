/*
    Function to Find the Lowest Common Ancestor in a Binary Tree, Have a look at the tree

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

// Insertion in a Binary Search Tree
bstNode* Insert(bstNode* root, int x){
    if(root == NULL)    root = getNewNode(x);
    else if(root->data > x) root->left = Insert(root->left, x);
    else if(root->data < x) root->right = Insert(root->right, x);
    return root; 
}
// Function to find LCA in BT
bstNode* LCAinBT(bstNode* root, int n1, int n2){
    if(root == NULL)    return NULL;                            // if tree is empty, return NULL
    if(root->data == n1 || root->data == n2)    return root;    // if you find any node in starting, Bingo! its the LCA
    bstNode* left = LCAinBT(root->left, n1, n2);                // FInd LCA in Letf
    bstNode* right = LCAinBT(root->right, n1, n2);              // Find LCA in right
    if( left != NULL && right != NULL)  return root;            // if Both bound One -One Node therefore root is LCA
    if( left == NULL && right == NULL)  return NULL;            // if Both are NULL, no lCA

    return (left!= NULL) ? left : right;                        // if only has found a node that means its the LCA

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
    cout << LCAinBT(root, 320, 60)->data << endl;
}
