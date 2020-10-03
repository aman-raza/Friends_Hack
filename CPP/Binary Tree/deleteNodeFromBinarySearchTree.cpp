/*
    Program to delete any node from given Binary Search Tree
   
    Concept :
    ! Case 1 : No Child
    * Simply delete the node
    ! Case 2: Only One child
    *   store root in temp, make root point to left or right child and delete the temp;
    ! Case 3 : 2 Childerm
    * Find Inorder Successor or Minimum value in RST of current-root takes its place and then again apply DeleteNode on that node containing the minimum value

*/
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

// Insertion
bstNode* Insert(bstNode* root, int x){
    if(root == NULL)    root = getNewNode(x);
    else if(root->data > x) root->left = Insert(root->left, x);
    else if(root->data < x) root->right = Insert(root->right, x);
    return root; 
}

// Function for finding the minimum element in a BST
bstNode* findMin(bstNode *root){
    while(root->left){
        root = root->left;
    }
    return root;
}

// Function for finding inorderSuccessor
bstNode* deleteANode(bstNode* root, int k){
    if(root == NULL)  return root;
    if(root->data > k)  root->left = deleteANode(root->left, k);
    else if(root->data < k)     root->right = deleteANode(root->right, k);
    else{        
        if(root->left == NULL && root->right == NULL){                          // ! case 1
            delete(root);
            root = NULL;
            return root;
        }        
        else if(root->right == NULL || root->left == NULL){                    // ! case 2
            bstNode* temp = root;
            (root->right == NULL) ? root = root->left : root = root->right;
            delete(temp);
            
        }        
        else{                                                                  // ! Case 3
            bstNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right =  deleteANode(root->right,temp->data);
        }
    }
    return root;
}

void inOrder(bstNode* root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
   
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
    inOrder(root);
    cout << endl;
    root = deleteANode(root, 400);
    inOrder(root);
    cout << endl;
}
