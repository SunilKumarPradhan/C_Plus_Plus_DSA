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

int findKthSmallest(node* root, int k) {
    stack<node*> s;
    auto curr = root;

    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top(); s.pop();
        if (--k == 0) return curr->key;

        curr = curr->right;
    }
    throw runtime_error("k is out of bounds");
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
    int k = 4;
    try {
        cout << "The " << k << "th smallest element is " << findKthSmallest(root, k) << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}
