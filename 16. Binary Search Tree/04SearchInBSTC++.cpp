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

// Recursive search function
bool recSearch(node* root, int key) {
    if (root == NULL) return false;
    if (root->key == key) return true;

    if (key < root->key) return recSearch(root->left, key);
    return recSearch(root->right, key);
}

// Iterative search function
bool itSearch(node* root, int key) {
    while (root != NULL) {
        if (root->key == key) return true;

        if (key < root->key) root = root->left;
        else root = root->right;
    }
    return false;
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    int key = 40;

    if (recSearch(root, key)) {
        cout << "Key " << key << " found using recursive search." << endl;
    } else {
        cout << "Key " << key << " not found using recursive search." << endl;
    }

    if (itSearch(root, key)) {
        cout << "Key " << key << " found using iterative search." << endl;
    } else {
        cout << "Key " << key << " not found using iterative search." << endl;
    }

    return 0;
}
