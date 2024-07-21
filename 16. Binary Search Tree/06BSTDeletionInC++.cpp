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

// Function to perform inorder traversal of the BST
void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Function to find the minimum value node in a BST
node* findMin(node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Function to delete a node from the BST
node* deleteNode(node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get the inorder successor
        node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
