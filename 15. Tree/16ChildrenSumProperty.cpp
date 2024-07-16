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

bool isChildSum(node *root){
    if(root==NULL) return 0;
    if(root->left == NULL && root->right==NULL) return true;

    int sum=0;
    if(root->left!=NULL) sum+=root->left->key;
    if(root->right!=NULL) sum+=root->right->key;

    return (root->key == sum && isChildSum(root->left) && isChildSum(root->right));
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);
    cout << "The isChildSum of the tree is : ";

    if (isChildSum(root)) cout<<"True";
    else cout<< "False";
  
    return 0;
}
