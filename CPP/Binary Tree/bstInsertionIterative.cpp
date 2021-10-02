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
    bstNode* node = getNewNode(x);
    if(root == NULL)    return node;                        // if empty tree return node itself as root;
    bstNode *current = root;
    while(current->right && current->left){                 // while we don't reach the correct leaf node as per BST
        if(current->data > x)   current = current->left;
        else if(current->data < x)  current = current->right;
    }
    if(current->data > x)    current->left = node;          // if node value is greater put in left
    else if(current->data < x)   current->right = node;     // if node value is lesser put in right
    return root;                                            // return updated value of root
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
    cout << Search(root, 320) << endl;

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