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

void inorderTraversal(node* root, node* &prev, node* &first, node* &second) {
    if (root == NULL) return;

    inorderTraversal(root->left, prev, first, second);

    if (prev && root->key < prev->key) {
        if (!first) {
            first = prev;
        }
        second = root;
    }
    prev = root;

    inorderTraversal(root->right, prev, first, second);
}

void fixBST(node* root) {
    node *prev = NULL, *first = NULL, *second = NULL;
    inorderTraversal(root, prev, first, second);
    if (first && second) {
        swap(first->key, second->key);
    }
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    fixBST(root);

    cout << "BST fixed if two nodes were swapped." << endl;
    return 0;
}


/*
Iss function ka naam hai inorderTraversal aur yeh BST (Binary Search Tree) mein misplaced nodes ko identify karne aur fix karne mein madad karta hai.

- Function ka logic:
  1. Inorder traversal karte hain BST ki nodes ko visit karte hue, aur previous aur current nodes ko compare karte hain.
  2. Agar previous node ka key current node ke key se bada hai, toh yeh nodes misplaced hain.
  3. `first` aur `second` variables ko set karte hain jahan misplaced nodes milti hain.

Process:
- Pehle, inorder traversal ke through tree ko traverse karte hain aur nodes ko check karte hain.
- Agar misplaced nodes milti hain, `first` aur `second` pointers ko set karte hain.
- Traversal complete hone ke baad, `first` aur `second` nodes ki keys ko swap kar dete hain.

Example:
- Agar BST mein yeh nodes hain:
       50
      /  \
     30   70
    / \   / \
   20 40 60  80

  Suppose, nodes 30 aur 60 ko swap kar diya gaya hai:
       50
      /  \
     60   70
    / \   / \
   20 40 30  80

- Function call fixBST(root) se swapped nodes fix ho jayenge aur BST wapas valid ho jayega.

Dry Run:
1. BST ka structure:
       50
      /  \
     30   70
    / \   / \
   20 40 60  80

2. FixBST(root):
   - Inorder traversal se nodes ki sequence milti hai: 20, 30, 40, 50, 60, 70, 80
   - Agar misplaced nodes detect hoti hain jaise 30 aur 60, toh unki keys swap kar dete hain.
   - Final tree structure: 
        50
       /  \
     30   70
    / \   / \
   20 40 60  80

3. Output:
   - BST fixed if two nodes were swapped.
*/