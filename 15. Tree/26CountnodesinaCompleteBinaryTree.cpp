#include <iostream>
using namespace std;

struct node {
  int key;
  node* left;
  node* right;

  node(int k) {
    key = k;
    left = right = nullptr;
  }
};


int getHeight(node* root) {
  if (root == nullptr) return 0;
  return 1 + getHeight(root->left);
}

int countNodes(node* root) {
    if (root == nullptr) return 0;

    int height = getHeight(root);
    if (getHeight(root->left) == height - 1)return (1 << height) - 1;
    return (1 << height) - 1;
            // Use the formula 2^height - 1 to count nodes in a complete binary tree
            // If not complete, recurse on left and right subtrees
    return countNodes(root->left) + countNodes(root->right);
}

int main() {
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);

  int nodeCount = countNodes(root);
  cout << "Number of nodes in the tree: " << nodeCount <<endl;

  return 0;
}
