#include <iostream>

using namespace std;

struct node {
  int val;
  node* left;
  node* right;
  node(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform preorder traversal iteratively (space-optimized)
void preorderTraversal(node* root) {
  node* current = root;

  while (current != NULL) {
    // If there's a left child, make it the next node
    if (current->left != NULL) {
      // Find the rightmost child of the left subtree
      node* pre = current->left;
      while (pre->right != NULL && pre->right != current) {
        pre = pre->right;
      }

      // If the rightmost child hasn't pointed to current yet, connect it
      // and move to the left subtree
      if (pre->right == NULL) {
        pre->right = current;
        current = current->left;
      } else { // If it has pointed before (processed), disconnect and move right
        pre->right = NULL;
        cout << current->val << " "; // Process current node
        current = current->right;
      }
    } else {
      // No left child, process current node and move right
      cout << current->val << " ";
      current = current->right;
    }
  }
}

int main() {
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->right->right = new node(5);

  cout << "Preorder traversal (space-optimized): ";
  preorderTraversal(root);
  cout << endl;

  return 0;
}
