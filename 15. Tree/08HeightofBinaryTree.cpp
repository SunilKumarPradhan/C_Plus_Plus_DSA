#include <bits/stdc++.h> 
using namespace std;

struct node {
    int key;
    node *left;
    node *right;

    node(int k) {
        key = k;
        left = right = NULL;
    }
};

int height(node *root){
    if(root==NULL) return 0;
    else return max( height(root->left) ,  height(root->right)+1 ); 
}

int main() {
    node *root = new node(3);

    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);
    
    cout<<"The height of this binary tree is : "<< endl;
    cout<<height(root)<<endl;

    return 0; 
}