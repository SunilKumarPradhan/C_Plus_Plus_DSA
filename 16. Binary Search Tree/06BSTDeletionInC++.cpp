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

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}


node* findMin(node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}


node* deleteNode(node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } 
        
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }


        // Node with two children: Get the inorder successor(right subtree ka smallest value)
        node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}


/*
Iss function ka naam hai findMin aur yeh BST (Binary Search Tree) mein minimum value node ko find karta hai.

- Function ka logic:
  1. Yeh iterative function hai jo tree ke leftmost node tak traverse karta hai.
  2. Jab tak current node ka left child NULL nahi hota, tab tak left child pe move karte hain.

Process:
- Pehle, root node se start karte hain.
- Uske baad, har step pe left child pe move karte hain jab tak left child NULL na ho jaye.

Example:
- Agar BST structure aisa hai:
       50
      /  \
     30   70
    / \   / \
   20 40 60 80

  - findMin(50):
    - Move to left child: 30
    - Move to left child: 20 (leftmost node)

Dry Run:
1. Initial setup: root = 50.
2. Execution steps:
   - findMin(50) -> move to 30 -> move to 20
3. Final output: Node with minimum value = 20

Output:
Node with minimum value = 20
*/

/*
Iss function ka naam hai deleteNode aur yeh BST (Binary Search Tree) mein ek node ko delete karta hai.

- Function ka logic:
  1. Agar root NULL hai, toh return karte hain.
  2. Agar key root ke key se chhoti hai, toh left subtree mein deleteNode function call karte hain.
  3. Agar key root ke key se badi hai, toh right subtree mein deleteNode function call karte hain.
  4. Agar key root ke key ke barabar hai, toh:
     - Agar node ke sirf ek ya zero child hain, toh node ko delete kar dete hain aur uske child ko return karte hain.
     - Agar node ke do children hain, toh node ke inorder successor (minimum value node in right subtree) ko find karte hain.
     - Root key ko inorder successor key se replace karte hain aur inorder successor ko delete karte hain.

Process:
- Pehle, key ko root se compare karte hain.
- Uske baad, subtree mein search aur delete operation perform karte hain.
- Agar node mil jaye, toh uske children ke basis pe delete operation karte hain.

Example:
- Agar BST structure aisa hai aur key = 50 delete karna hai:
       50
      /  \
     30   70
    / \   / \
   20 40 60 80

  - deleteNode(50):
    - Root = 50, match found
    - Node with two children, findMin in right subtree (60)
    - Replace root key with 60
    - Delete node 60 from right subtree

Dry Run:
1. Initial setup: root = 50, key = 50.
2. Execution steps:
   - deleteNode(50) -> findMin(70) -> replace key with 60 -> deleteNode(70, 60)
3. Final output: Updated BST after deleting node with key 50.

Output:
Inorder traversal after deletion: 20 30 40 60 70 80
*/
