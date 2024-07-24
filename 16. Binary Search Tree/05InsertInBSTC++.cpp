#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    node *left, *right;

    node(int k) {
        key = k;
        left = right = NULL;
    }
};

// Recursive insertion function
node* recursiveInsert(node* root, int key) {
    if (root == NULL) return new node(key);

    if (key < root->key) 
        root->left = recursiveInsert(root->left, key);
    else if (key > root->key) 
        root->right = recursiveInsert(root->right, key);
    return root;
}

// Iterative insertion function
node* iterativeInsert(node* root, int key) {
    node* newNode = new node(key);
    if (root == NULL) return newNode;
    
    node* parent = NULL;
    node* curr = root;

    while (curr != NULL) {
        parent = curr;
        if (key < curr->key) 
            curr = curr->left;
        else if (key > curr->key)
            curr = curr->right;
        else return root; // Key already exists
    }
    // these cases are for , when the tree is empty
    if (key < parent->key) parent->left = newNode;
    else parent->right = newNode;
    return root;
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    node* root = NULL;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};

    // Insert using recursive method
    for (int key : keys) root = recursiveInsert(root, key);

    cout << "Inorder traversal after recursive insertion: ";
    inorder(root);
    cout << endl;

    root = NULL; // Reset the tree

    // Insert using iterative method
    for (int key : keys) root = iterativeInsert(root, key);

    cout << "Inorder traversal after iterative insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}


/*
Iss function ka naam hai recursiveInsert aur yeh ek BST (Binary Search Tree) mein key ko recursively insert karta hai.

- Function ka logic:
  1. Agar root NULL hai, toh naya node create karke return karte hain.
  2. Agar key root ke key se chhoti hai, toh left subtree mein recursively insert karte hain.
  3. Agar key root ke key se badi hai, toh right subtree mein recursively insert karte hain.
  4. Return root node after insertion.

Process:
- Pehle, root node se comparison start hoti hai.
- Uske baad, har level pe check hota hai ki key ko left subtree mein insert karna hai ya right subtree mein.
- Insert karke root node ko return karte hain.

Example:
- Agar BST structure aisa hai aur key = 25 insert karna hai:
       50
      /  \
     30   70
    / \   / \
   20 40 60 80

  - Insert 25:
    - Root = 50, 25 < 50, left subtree (30)
    - Root = 30, 25 < 30, left subtree (20)
    - Root = 20, 25 > 20, right subtree NULL, insert 25

Dry Run:
1. Initial setup: root = 50, key = 25.
2. Execution steps:
   - recursiveInsert(50, 25) -> recursiveInsert(30, 25) -> recursiveInsert(20, 25) -> return new node(25)
3. Final output: Updated BST with key 25 inserted.

Output:
Inorder traversal after recursive insertion: 20 25 30 40 50 60 70 80
*/

/*
Iss function ka naam hai iterativeInsert aur yeh ek BST (Binary Search Tree) mein key ko iteratively insert karta hai.

- Function ka logic:
  1. Agar root NULL hai, toh naya node create karke return karte hain.
  2. Parent aur current pointers use karke, key ko correct position tak pohchane tak traverse karte hain.
  3. Agar key chhoti hai current key se, toh left move karte hain, aur agar badi hai toh right move karte hain.
  4. Jab correct position mil jaye, toh parent node ke left ya right mein naya node attach karte hain.
  5. Agar key already exist karta hai, toh tree change nahi hota.

Process:
- Pehle, root node se traversal start hoti hai.
- Uske baad, parent aur current pointers ko use karke correct position pe pohchte hain.
- Naya node correct position pe insert karke tree ko return karte hain.

Example:
- Agar BST structure aisa hai aur key = 25 insert karna hai:
       50
      /  \
     30   70
    / \   / \
   20 40 60 80

  - Insert 25:
    - Root = 50, 25 < 50, left subtree (30)
    - Root = 30, 25 < 30, left subtree (20)
    - Root = 20, 25 > 20, right subtree NULL, insert 25

Dry Run:
1. Initial setup: root = 50, key = 25.
2. Execution steps:
   - iterativeInsert(50, 25) -> parent = 20 -> insert new node(25) as right child of 20
3. Final output: Updated BST with key 25 inserted.

Output:
Inorder traversal after iterative insertion: 20 25 30 40 50 60 70 80
*/
