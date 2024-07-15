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


int size(node *root) {
    if (root == NULL) return 0;
    else return 1 + size(root->left) + size(root->right);
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);
    cout << "The Size of the tree is : " << size(root) << endl;
    return 0;
}
