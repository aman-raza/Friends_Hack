/*
    ! case 1: Right Subtree Exists
    * in this case we find the min element in RST
    
    ! csae 2: RST DNE:
    * In this case, we start from root and goto the last ancestor 
    * for which the current node would be in lST
    ? THAT LAST ANCSETOR IS THE ANSWER i.e. SUCCESSOR

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
// Function for finding a node having ->data == x
bstNode* findNode(bstNode* root, int x){
    if(root == NULL)    return root;
    else if(root->data > x)     return findNode(root->left, x);
    else if(root->data < x)     return findNode(root->right, x);
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
bstNode* inorderSuccessor(bstNode*root, int x){
    bstNode* current = findNode(root, x);       
    // ! Case 1
    if(current->right){                 
        return findMin(current->right);         // retturning minimum element in RST of current node
    }
    // ! Case 2
    else{
        bstNode* ancestor = root, *successor = NULL;        
        while(ancestor != current){
            if(ancestor->data > current->data){     
                successor = ancestor;              // we update successor iff we go in left
                ancestor = ancestor->left;
            }
            else    ancestor = ancestor->right;
            
        }
        return successor;
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
    cout << inorderSuccessor(root, 120)->data << endl;
}
