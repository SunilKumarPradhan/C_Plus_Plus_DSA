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





/*
Is code ka maqsad hai binary tree ka preorder traversal iteratively (space-optimized) karna.

1. `preorderTraversal` function:
   - **Morris Traversal** technique ka use karke binary tree ko preorder traversal karte hain.
   - **While loop**:
     - **Current node pe** focus karte hain.
     - Agar current node ka left child hai:
       - Left subtree ke rightmost child ko dhundhte hain.
       - Agar rightmost child ka right pointer NULL hai, toh usko current node se connect karte hain aur left subtree mein move karte hain.
       - Agar right pointer already current node pe point kar raha hai (matlab left subtree already processed hai), toh usko NULL set karte hain, current node ko process karte hain (print), aur right subtree mein move karte hain.
     - Agar current node ka left child nahi hai:
       - Current node ko process karte hain (print) aur right subtree mein move karte hain.

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
   - **Traversal**:
     - **Start** at root = 1:
       - Root = 1, left child = 2 hai
       - 2 ke left subtree ke rightmost child 4 ko dhundho
       - Rightmost child 4 ka right NULL hai, usko current node 1 se connect karo aur left subtree 2 mein move karo
     - **Move to node 2**:
       - 2 ke left child = 4 hai
       - 4 ke left aur right children nahi hain, toh 4 ko process karo (print 4)
       - 2 ke right child NULL hai, rightmost child (4) ka right NULL set karo aur current node 2 ko process karo (print 2)
       - 2 ke right child NULL hai, move to parent node 1
     - **Move back to node 1**:
       - 1 ko process karo (print 1) aur right subtree 3 mein move karo
     - **Move to node 3**:
       - 3 ka left child NULL hai, toh 3 ko process karo (print 3) aur right subtree 5 mein move karo
     - **Move to node 5**:
       - 5 ka left aur right children nahi hain, toh 5 ko process karo (print 5)
       - Traversal complete

2. **Output:**
   - **Preorder Traversal**: 1 2 4 3 5
*/
