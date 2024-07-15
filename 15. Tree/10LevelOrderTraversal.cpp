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

void printLevelOrder(node *root) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    if (root == NULL) return;

    queue<node *> q;
    q.push(root);

    while (!q.empty()) {
        node *curr = q.front();
        q.pop();

        cout << curr->key << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main() {
    node *root = new node(3);

    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    cout << "PostOrder Traversal : "<<endl;

    printLevelOrder(root);

    return 0; 
}
