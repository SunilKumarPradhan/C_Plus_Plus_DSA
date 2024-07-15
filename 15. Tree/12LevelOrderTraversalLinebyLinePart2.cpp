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

void printLevelOrderLinebyLine(node *root) {
    if (root == NULL) return;
    queue<node*> q;
    q.push(root);
    q.push(NULL); // Marker for level separation

    while (q.size() > 1) {
        int count = q.size();  // Number of nodes in current level
        while (count > 0) {
            node* curr = q.front();
            q.pop();

            if (curr == NULL) {
                cout << "\n";  // Print newline for level separation
                q.push(NULL); // Push another marker for next level
                count--;      // Decrement count to indicate level change
                continue;   
            }

            cout << curr->key << " "; 

            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL)q.push(curr->right);
            count--;  // Decrement count for nodes processed in current level
        }
    }
}
int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    cout << "Level Order Traversal Line by Line:" << endl;
    printLevelOrderLinebyLine(root);

    // Clean up the tree to avoid memory leaks
    delete root->right->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
