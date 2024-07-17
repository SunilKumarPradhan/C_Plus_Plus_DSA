#include <iostream>
#include <stack>

using namespace std;

struct node {
  int val;
  node* left;
  node* right;
  node(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform inorder traversal iteratively
void inorderTraversal(node* root) {
  stack<node*> nodeStack;

  while (root != NULL || !nodeStack.empty()) {
    // Push left subtree nodes onto the stack
    while (root != NULL) {
      nodeStack.push(root);
      root = root->left;
    }

    // Pop a node, process it, and move to the right subtree
    if (!nodeStack.empty()) {
      root = nodeStack.top();
      nodeStack.pop();
      cout << root->val << " ";
      root = root->right;
    }
  }
}

int main() {
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->right->right = new node(5);

  cout << "Inorder traversal: ";
  inorderTraversal(root);
  cout << endl;

  return 0;
}
