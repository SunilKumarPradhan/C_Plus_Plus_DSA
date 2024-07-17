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

bool findPath(node *root, vector<node*> &p, int n) {
    if (root == NULL) return false;

    p.push_back(root);

    if (root->key == n) return true;

    if (findPath(root->left, p, n) || findPath(root->right, p, n)) return true;

    p.pop_back();  // Correctly use pop_back to remove the last element
    return false;
}

node* LCAofBinTree(node *root, int n1, int n2) {
    vector<node*> path1, path2; // Create two vectors

    if (findPath(root, path1, n1) == false || findPath(root, path2, n2) == false) return NULL;

    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] != path2[i]) break;
    }
    return path1[i-1];
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    int n1 = 1, n2 = 5; // Example nodes to find LCA
    node* lca = LCAofBinTree(root, n1, n2);
    if (lca != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca->key << endl;
    else
        cout << "LCA does not exist" << endl;

    return 0;
}
