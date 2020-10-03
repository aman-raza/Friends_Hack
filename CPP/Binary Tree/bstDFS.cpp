// ! To implement Depth First Search in a Binary Search Tree in all Preorder, Postorder and Inorder Traversal
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

bstNode* Insert(bstNode* root, int x){
    if(root == NULL)    root = getNewNode(x);
    else if(root->data > x) root->left = Insert(root->left, x);
    else if(root->data < x) root->right = Insert(root->right, x);
    return root; 
}

void preOrder(bstNode* root){
    if(root == NULL)    return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrderIterative(bstNode* root){
    stack<bstNode *> s1, s2;
    s1.push(root);
    while (!s1.empty()){
        bstNode* current = s1.top();
        s1.pop();
        s2.push(current);
        if(current->right != NULL)  s1.push(current->right);
        else if(current->left != NULL)  s1.push(current->left);;
    }
    while(!s2.empty()){
        cout << s2.top()->data << " ";
        s2.pop();
    }   

}
void postOrder(bstNode* root){
    if(root == NULL)    return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
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
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    postOrderIterative(root);
    cout << endl;
    inOrder(root);
    cout << endl;
}
