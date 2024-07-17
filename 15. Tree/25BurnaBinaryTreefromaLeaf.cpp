#include <bits/stdc++.h>
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

bool burnTree(node* root) {
  if (root == nullptr) {
    return false;
  }

  bool leftBurning = burnTree(root->left);
  bool rightBurning = burnTree(root->right);

  if (leftBurning || rightBurning) {
    return true;
  }

  return false;
}

int main() {
  node* root = new node(3);
  root->left = new node(2);
  root->right = new node(4);
  root->right->right = new node(5);
  root->left->left = new node(1);
  return 0;
}
