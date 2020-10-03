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


bstNode* LCAinBST(bstNode* root, int n1, int n2){
	if(root->data > n1 && root->data > n2)	LCAinBST(root->left, n1, n2);
	else if(root->data < n1 && root->data < n2)	LCAinBST(root->right, n1, n2);
	return root;
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
    cout << LCAinBST(root, 320, 500)->data << " " << endl;
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