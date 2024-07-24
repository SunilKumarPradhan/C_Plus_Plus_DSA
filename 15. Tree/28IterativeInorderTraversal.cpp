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

/*
Is code ka maqsad hai binary tree ka inorder traversal iteratively (without recursion) karna.

1. `inorderTraversal` function:
   - **Stack** ka use karke binary tree ko inorder traversal karte hain.
   - **While loop**:
     - Pehle, left subtree ke nodes ko stack mein push karte hain.
     - Jab left subtree complete ho jata hai, tab stack se node ko pop karte hain, us node ka value print karte hain, aur phir right subtree pe move karte hain.
     - Yeh process tab tak chalta hai jab tak stack empty na ho jaye aur root NULL na ho.

**Process:**

1. **Traversal Steps:**
   - **Tree ka Structure:**
     ```
       1
      / \
     2   3
    /     \
   4       5
     ```
   - **Traversal:**
     - **Start** at root = 1
     - **Push** nodes 1 and 2 to stack, move left to node 4
     - **Push** node 4 to stack, move left which is NULL
     - **Pop** node 4, print 4
     - Move right which is NULL
     - **Pop** node 2, print 2
     - Move right which is NULL, **Pop** node 1, print 1
     - Move right to node 3
     - **Push** node 3 to stack, move left which is NULL
     - **Pop** node 3, print 3
     - Move right to node 5
     - **Push** node 5 to stack, move left which is NULL
     - **Pop** node 5, print 5
     - Move right which is NULL, stack is empty

2. **Output:**
   - **Inorder Traversal**: 4 2 1 3 5
*/
