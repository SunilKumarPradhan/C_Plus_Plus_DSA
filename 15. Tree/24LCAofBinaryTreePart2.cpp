#include <iostream>
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

node* findLCA(node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->key == n1 || root->key == n2) return root;
        
    node* leftLCA = findLCA(root->left, n1, n2);
    node* rightLCA = findLCA(root->right, n1, n2);
    if (leftLCA && rightLCA) return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    node* root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    int n1 = 1, n2 = 5;
    node* lca = findLCA(root, n1, n2);
    if (lca != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca->key << endl;
    else
        cout << "LCA does not exist" << endl;
    return 0;
}
