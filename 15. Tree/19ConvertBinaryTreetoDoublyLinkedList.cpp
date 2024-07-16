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

node *prev = NULL, *head = NULL;

node* BTtoDLL(node *root) {
    if (root == NULL) return root;
    BTtoDLL(root->left);
    if (prev == NULL) head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTtoDLL(root->right);
    return head;
}

void printDLL(node* head) {
    while (head != NULL) {
        cout << head->key << " ";
        head = head->right;
    }
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    node *head = BTtoDLL(root);
    printDLL(head);
}
