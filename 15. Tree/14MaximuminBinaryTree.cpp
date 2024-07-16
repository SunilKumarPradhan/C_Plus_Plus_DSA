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

int getMax(node *root){
    if(root==NULL) return INT_MIN;
    else return max( root->key ,max( getMax(root->left), getMax(root->right) ) );
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);
    cout << "The MaxNode of the tree is : " << getMax(root) << endl;
    return 0;
}
