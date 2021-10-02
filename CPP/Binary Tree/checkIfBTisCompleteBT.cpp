// To Check is Binary Tree is a Complete Binary Tree in Both Recursive and Iterative Methods
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

/*  Recursive Insetion

bstNode* Insert(bstNode* root, int x){
    if(root == NULL)    root = getNewNode(x);
    else if(root->data > x) root->left = Insert(root->left, x);
    else if(root->data < x) root->right = Insert(root->right, x);
    return root; 
}
*/

// Iterative Insertion
bstNode* Insert(bstNode* root, int x){
    bstNode* node = getNewNode(x);
    if(root == NULL)    return node;
    bstNode *parent = NULL, *current = root;
    while(current->right && current->left){
        if(current->data > x)   current = current->left;
        else if(current->data < x)  current = current->right;
    }
    if(current->data > x)    current->left = node;
    else if(current->data < x)   current->right = node;
    return root;
}

bool Search(bstNode* root, int x){
    if(root == NULL)    return false;
    // ! Optional if (root->data == x)   return true;
    else if(root->data > x)     return Search(root->left, x);
    else if (root->data < x)    return Search(root->right, x); 
    return true;    
}

bool sameTree(bstNode *root1, bstNode *root2){
    if(root1 == NULL && root2 == NULL)  return true;
    if(root1 == NULL || root2 == NULL)  return false;
    return(( root1->data == root2->data) && sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right));   

}

int size(bstNode* root){
    if(root == NULL)    return 0;
    int left = size(root->left);
    int right = size(root->right);
    return left+right+1;
}

int noOfLeaf(bstNode* root){
    if(root == NULL)    return 0;
    if(root->left== NULL && root->right == NULL)    return 1;
    int left = noOfLeaf(root->left);
    int right = noOfLeaf(root->right);
    return left+right;
}

int heightOfBT(bstNode* root){
    if(root == NULL)    return -1;
    int left = heightOfBT(root->left);
    int right = heightOfBT(root->right);
    return(max(left, right) +1);
}
int main(){
    bstNode* root = NULL, *root2 = NULL;
    root = Insert(root, 100);
    root = Insert(root, 110);
    root = Insert(root, 120);
    root = Insert(root, 10);
    root = Insert(root, 700);
    root = Insert(root, 400);
    root = Insert(root, 500);
    root = Insert(root, 60);
    root = Insert(root, 320);

    root2 = Insert(root2, 100);
    root2 = Insert(root2, 110);
    root2 = Insert(root2, 120);
    root2 = Insert(root2, 10);
    root2 = Insert(root2, 700);
    root2 = Insert(root2, 400);
    root2 = Insert(root2, 500);
    root2 = Insert(root2, 60);
    root2 = Insert(root2, 220);
    cout << sameTree(root, root2) << endl;
    

}