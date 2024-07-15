// tree.cpp
#include "tree.h"

node* makeTree() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);
    return root;
}
