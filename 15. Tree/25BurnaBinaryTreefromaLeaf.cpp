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


/*
Iss function ka naam hai burnTree aur yeh function binary tree ko burn karne ka check karta hai.
- Yeh function recursive hai aur root node se shuru hota hai.
- Function ka base case yeh hai:
  1. Agar root NULL hai, toh false return karo.

Process:
- Tree ko recursively traverse karte hain.
- Har node pe, left aur right subtree ko recursively burnTree function ke saath call karte hain.
- Agar left ya right subtree burning state mein hai, toh true return karte hain.
- Agar root node burning state mein nahi hai, toh false return karte hain.

Example:
- Agar tree hai:
       3
      / \
     2   4
    /     \
   1       5
- Function ko burnTree(root) call karte hain, lekin yeh function sirf yeh check kar raha hai ki tree burn ho raha hai ya nahi.

Dry Run:
1. burnTree function call hota hai root = 3:
   - root = 3
   - call burnTree(root->left):
     - root = 2
     - call burnTree(root->left):
       - root = 1
       - return false (left and right are NULL)
     - call burnTree(root->right):
       - root = NULL
       - return false
     - leftBurning = false, rightBurning = false
     - return false
   - call burnTree(root->right):
     - root = 4
     - call burnTree(root->left):
       - root = NULL
       - return false
     - call burnTree(root->right):
       - root = 5
       - return false (left and right are NULL)
     - leftBurning = false, rightBurning = false
     - return false
   - leftBurning = false, rightBurning = false
   - return false

Output:
- Function sirf yeh check karta hai ki tree burn ho raha hai ya nahi, lekin actual mein koi burning process yahan defined nahi hai.
*/
