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


/*
Iss function ka naam hai countNodes aur yeh binary tree mein nodes ki count karne ke liye use hota hai.

- Function do helper functions ko use karta hai:
  1. getHeight(root) - Tree ka height calculate karta hai.
  2. countNodes(root) - Total number of nodes count karta hai.

Process:
1. getHeight function:
   - Agar root NULL hai, toh height 0 return karte hain.
   - Agar root NULL nahi hai, toh left subtree ki height ko calculate karte hain aur 1 add karte hain.

2. countNodes function:
   - Agar root NULL hai, toh node count 0 return karte hain.
   - Height ko calculate karte hain.
   - Agar left subtree ki height (getHeight(root->left)) height - 1 ke equal hai, toh yeh ek complete binary tree hai aur node count = 2^height - 1 calculate karte hain.
   - Agar tree complete nahi hai, left aur right subtrees pe recursively countNodes function call karte hain aur unka total count return karte hain.

Example:
- Agar tree hai:
       1
      / \
     2   3
    / \  / 
   4   5 6

- getHeight(root) se height = 3 aayega.
- countNodes(root) function ko call karte hain, yeh left subtree aur right subtree ko recursively count karega aur total nodes return karega.

Dry Run:
1. Tree ka structure:
       1
      / \
     2   3
    / \  / 
   4   5 6

2. getHeight(root) call:
   - Height of root 1 = 1 + height of left subtree (2) = 3

3. countNodes(root) call:
   - Root node 1 ke left subtree height = 2 (left subtree is complete)
   - Node count for complete tree of height 2 = 2^2 - 1 = 3
   - Recursively calculate for left and right subtrees:
     - Left subtree count (root = 2) = 2^2 - 1 = 3
     - Right subtree count (root = 3) = 1 (only one node 6)
   - Total node count = 3 + 3 + 1 = 7

Output:
Number of nodes in the tree: 7
*/