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
bool sameTree(bstNode *root1, bstNode *root2){
    if(root1 == NULL && root2 == NULL)  return true;
    if(root1 == NULL || root2 == NULL)  return false;
    return(( root1->data == root2->data) && sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right));   

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