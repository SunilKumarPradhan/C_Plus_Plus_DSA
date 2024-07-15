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

void NodeAtKdist(node *root, int k){
    if(root==NULL) return;
    if(k==0){cout<<root->key<<" ";}
    else{
        NodeAtKdist(root->left , k-1);
        NodeAtKdist(root->right , k-1);
    }
}

int main() {
    node *root = new node(3);

    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);
    
    cout<<"The Nodes at 2 distance : "<<endl;
    NodeAtKdist(root,2);

    return 0; 
}