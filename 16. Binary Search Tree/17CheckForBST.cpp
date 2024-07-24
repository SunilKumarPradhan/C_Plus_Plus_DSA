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


bool isBSTUtil(node* root, node* left = NULL, node* right = NULL) {
  
    if (root == NULL) return true;
    if (left != NULL && root->key <= left->key) return false; 
    if (right != NULL && root->key >= right->key) return false;  

    return isBSTUtil(root->left, left, root) && isBSTUtil(root->right, root, right);
}

/*
Iss function ka naam hai isBSTUtil aur yeh helper function hai jo check karta hai agar given tree BST (Binary Search Tree) hai ya nahi.

- Function ka logic:
  1. Agar root NULL hai, toh yeh BST hai, return true.
  2. Agar current node ka key left node se chhota ya barabar hai, ya right node se bada ya barabar hai, toh yeh BST nahi hai, return false.
  3. Recursively left aur right subtree ko check karte hain with updated constraints.

Process:
- Pehle, root se shuru karte hain aur left aur right constraints NULL se initialize karte hain.
- Har node pe check karte hain agar uska key left aur right constraints ke beech hai.
- Agar subtree valid BST hai, toh function true return karta hai, warna false return karta hai.

Example:
- Agar BST hai:
       50
      /  \
     30   70
    / \   / \
   20 40 60  80

- Function call isBST(root) ka output hoga true kyunki given tree ek valid BST hai.

Dry Run:
1. BST ka structure:
       50
      /  \
     30   70
    / \   / \
   20 40 60  80

2. isBST(root):
   - root = 50, left = NULL, right = NULL
   - isBSTUtil(root->left, NULL, 50) && isBSTUtil(root->right, 50, NULL)
   - root->left = 30, left = NULL, right = 50
     - 30 < 50, check left subtree
     - isBSTUtil(20, NULL, 30) && isBSTUtil(40, 30, 50)
     - root->left->left = 20, left = NULL, right = 30
       - 20 < 30, check left subtree (NULL) and right subtree (NULL)
     - root->left->right = 40, left = 30, right = 50
       - 40 > 30 and 40 < 50, check left subtree (NULL) and right subtree (NULL)
   - root->right = 70, left = 50, right = NULL
     - 70 > 50, check left subtree
     - isBSTUtil(60, 50, 70) && isBSTUtil(80, 70, NULL)
     - root->right->left = 60, left = 50, right = 70
       - 60 > 50 and 60 < 70, check left subtree (NULL) and right subtree (NULL)
     - root->right->right = 80, left = 70, right = NULL
       - 80 > 70, check left subtree (NULL) and right subtree (NULL)

3. Output:
   - The tree is a Binary Search Tree.
*/

bool isBST(node* root) {
    return isBSTUtil(root);
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);


    cout<<(isBST(root) ? "The tree is a Binary Search Tree." :"The tree is not a Binary Search Tree." )<<endl;

    return 0;
}
