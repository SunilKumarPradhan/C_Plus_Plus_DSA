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

int preIndex = 0;

node *cTree(int in[], int pre[], int is, int ie) {
    if (is > ie) return NULL;
    node *root = new node(pre[preIndex++]);

    int inIndex;
    for (int i = is; i <= ie; i++) {
        if (in[i] == root->key) {
            inIndex = i;
            break;
        }
    }
    root->left = cTree(in, pre, is, inIndex - 1);
    root->right = cTree(in, pre, inIndex + 1, ie);
    return root;
}

void inorderPrint(node *root) {
    if (root == NULL) return;
    inorderPrint(root->left);
    cout << root->key << " ";
    inorderPrint(root->right);
}

int main() {
    int in[] = {1, 2, 3, 4, 5};
    int pre[] = {3, 2, 1, 4, 5};
    int len = sizeof(in)/sizeof(in[0]);

    node *root = cTree(in, pre, 0, len - 1);

    cout << "Inorder traversal of the constructed tree: ";
    inorderPrint(root);

    return 0;
}
