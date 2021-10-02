#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *left, *right;

        node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

    node* insertBST(node* root, int val){

        if(root == NULL)
            return new node(val);

        if(val<root->data)
            root->left = insertBST(root->left, val);
        else
            root->right = insertBST(root->right, val);

        return root;
    }

    void inorder(node* root){
        if(root == NULL) return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    node* searchInBST(node* root, int key){

        if(root == NULL) return NULL;

        if(root->data == key) return root;

        // data>key
        if(root->data > key) return searchInBST(root->left, key);

        //data<key
        return searchInBST(root->right, key);
    }

    node* inorderSucc(node* root){
        node* curr = root;

        while(curr && curr->left != NULL)
            curr = curr->left;

        return curr;
    }

    node* deleteInBST(node* root, int val){

        if(val < root->data)
            root->left = deleteInBST(root->left, val);

        else if(val > root->data)
            root->right = deleteInBST(root->right, val);

        else{
            if(root->left == NULL){
                node* temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right == NULL){
                node* temp = root->left;
                free(root);
                return temp;
            }
            //case 3
            node* temp = inorderSucc(root->right);
            root->data = temp->data;
            root->right = deleteInBST(root->right, temp->data);
        }
        return root;
    }

int main(){
    
    node *root = NULL;

/*
        4
      /   \
     2     5
    / \     \
   1   3     7
*/
    int option;
    int data;

    while(true){

        cout<<"\n1. Create a Node  2. Insert  3. Display (In-order)  4. Search  5. Delete  0. Exit"<<endl;
        cin>>option;

        switch(option){
            case 1:
                cout<<"Enter the root data: ";
                cin>>data;
                root = insertBST(root, data);
                break;

            case 2:
                cout<<"Enter the data: ";
                cin>>data;
                insertBST(root, data);
                break;

            case 3:
                inorder(root);
                cout<<endl;
                break;

            case 4:
                cout<<"Enter the key: ";
                cin>>data;
                if(searchInBST(root, data) == NULL) 
                    cout<<"Does not exists"<<endl;
                else
                    cout<<"Exists"<<endl;
                break;

            case 5:
                cout<<"Enter the value to be deleted: ";
                cin>>data;
                root = deleteInBST(root, data);
                break;

        }
        if(option == 0){
            break;
        }
    }

    return 0;
}
