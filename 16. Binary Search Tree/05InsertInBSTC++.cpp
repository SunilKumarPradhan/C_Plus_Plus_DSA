#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    node *left, *right;

    node(int k) {
        key = k;
        left = right = NULL;
    }
};

// Recursive insertion function
node* recursiveInsert(node* root, int key) {
    if (root == NULL) return new node(key);

    if (key < root->key) 
        root->left = recursiveInsert(root->left, key);
    else if (key > root->key) 
        root->right = recursiveInsert(root->right, key);
    return root;
}

// Iterative insertion function
node* iterativeInsert(node* root, int key) {
    node* newNode = new node(key);
    if (root == NULL) return newNode;
    
    node* parent = NULL;
    node* curr = root;

    while (curr != NULL) {
        parent = curr;
        if (key < curr->key) 
            curr = curr->left;
        else if (key > curr->key)
            curr = curr->right;
        else return root; // Key already exists
    }
    // these cases are for , when the tree is empty
    if (key < parent->key) parent->left = newNode;
    else parent->right = newNode;
    return root;
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    node* root = NULL;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};

    // Insert using recursive method
    for (int key : keys) root = recursiveInsert(root, key);

    cout << "Inorder traversal after recursive insertion: ";
    inorder(root);
    cout << endl;

    root = NULL; // Reset the tree

    // Insert using iterative method
    for (int key : keys) root = iterativeInsert(root, key);

    cout << "Inorder traversal after iterative insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}
