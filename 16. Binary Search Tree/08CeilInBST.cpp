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

int findCeiling(node* root, int k) {
    int ceiling = -1;
    
    while (root != NULL) {
        if (root->key == k) return root->key;
        
        if (k > root->key) root = root->right;
        else {
            ceiling = root->key;
            root = root->left;
        }
    }
    return ceiling;
}


int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    cout << "  ";

    int result = findCeiling(root, 35);
    if (result == -1)
        cout << "Ceiling doesn't exist in the BST" << endl;
    else
        cout << "The Ceiling is: " << result << endl;

    return 0;
}
