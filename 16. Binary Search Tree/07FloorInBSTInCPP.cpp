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


node* findFloor(node* root, int key) {
    node* floor = NULL;
    while (root) {
        if (root->key == key) return root;
        if (key > root->key) {
            floor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    int key = 65;
    node* floorNode = findFloor(root, key);
    
    if (floorNode) {
        cout << "Floor value of " << key << " is " << floorNode->key << endl;
    } else {
        cout << "Floor value of " << key << " does not exist in the BST" << endl;
    }

    return 0;
}
