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

// Inorder traversal ka function jo tree ko inorder mein traverse karta hai

int add(int a ,int b){
    int res = a+b;
    return res;
}

void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->key<< " ";
        inorder(root->right);
    }
}

int main() {
    node *root = new node(3);

    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    //cout << "Inorder traversal: " << inorder(root)<<endl; // In C++, you cannot insert a void function call directly into a cout stream insertion operation.
    cout << "InOrder Traversal : "<<endl;

    inorder(root); // ye fucntion khud hi print kar deta hai , hence alag se print karne ki koi zarurat nahi
    cout<<"The sum ="+ to_string(add(2,3))<<endl;
    return 0; 
}
