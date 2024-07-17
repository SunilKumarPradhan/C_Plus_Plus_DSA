#include <iostream>
#include <stack>

using namespace std;

struct node {
  int val;
  node* left;
  node* right;
  node(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform preorder traversal iteratively
void preorderTraversal(node* root) {
  if (root == NULL) {
    return;
  }

  stack<node*> nodeStack;
  nodeStack.push(root);

  while (!nodeStack.empty()) {
    node* node = nodeStack.top();
    nodeStack.pop();
    cout << node->val << " ";  // Process current node

    // Push right child first (processed later)
    if (node->right != NULL) {
      nodeStack.push(node->right);
    }
    // Push left child second (processed earlier)
    if (node->left != NULL) {
      nodeStack.push(node->left);
    }
  }
}

int main() {
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->right->right = new node(5);

  cout << "Preorder traversal: ";
  preorderTraversal(root);
  cout << endl;

  return 0;
}
