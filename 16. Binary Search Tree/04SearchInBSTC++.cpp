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

// Recursive search function
bool recSearch(node* root, int key) {
    if (root == NULL) return false;
    if (root->key == key) return true;

    if (key < root->key) return recSearch(root->left, key);
    return recSearch(root->right, key);
}

// Iterative search function
bool itSearch(node* root, int key) {
    while (root != NULL) {
        if (root->key == key) return true;

        if (key < root->key) root = root->left;
        else root = root->right;
    }
    return false;
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    int key = 40;

    cout << (recSearch(root, key) ? "Key " + to_string(key) + " found using recursive search." : "Key " + to_string(key) + " not found using recursive search.") << endl;
    cout << (itSearch(root, key) ? "Key "+to_string(key)+" found using iterative search." : "Key" + to_string(key) + " not found using iterative search." )<< endl;
    

    return 0;
}

/*
Iss function ka naam hai recSearch aur yeh ek BST (Binary Search Tree) mein ek given key ko recursively search karta hai.

- Function ka logic:
  1. Agar root NULL hai, toh return false (key nahi mila).
  2. Agar root ka key search key ke barabar hai, toh return true (key mil gaya).
  3. Agar search key choti hai root ke key se, toh left subtree mein recursively search karo.
  4. Agar search key badi hai root ke key se, toh right subtree mein recursively search karo.

Process:
- Pehle, root node se search start hoti hai.
- Uske baad, har level pe check hota hai ki current node ka key search key ke barabar hai ya nahi.
- Agar barabar hai toh true, nahi toh left ya right subtree mein search continue hoti hai.

Example:
- Agar BST structure aisa hai:
       50
      /  \
     30   70
    / \   / \
   20 40 60 80
   
- Aur key = 40 search karna hai:
  - Root = 50, 40 < 50, left subtree (30)
  - Root = 30, 40 > 30, right subtree (40)
  - Root = 40, 40 == 40, key mil gaya, return true

Dry Run:
1. Initial setup: root = 50, key = 40.
2. Execution steps:
   - recSearch(50, 40) -> recSearch(30, 40) -> recSearch(40, 40) -> return true.
3. Final output: Key 40 found using recursive search.

Output:
Recursive Search: Key 40 found using recursive search.
*/

/*
Iss function ka naam hai itSearch aur yeh ek BST (Binary Search Tree) mein ek given key ko iteratively search karta hai.

- Function ka logic:
  1. Jab tak root NULL nahi hota:
     - Agar root ka key search key ke barabar hai, toh return true (key mil gaya).
     - Agar search key choti hai root ke key se, toh left subtree mein move karo.
     - Agar search key badi hai root ke key se, toh right subtree mein move karo.
  2. Agar loop ke baad bhi key nahi milti, toh return false.

Process:
- Pehle, root node se search start hoti hai.
- Uske baad, har level pe check hota hai ki current node ka key search key ke barabar hai ya nahi.
- Agar barabar hai toh true, nahi toh left ya right subtree mein search continue hoti hai.

Example:
- Agar BST structure aisa hai:
       50
      /  \
     30   70
    / \   / \
   20 40 60 80
   
- Aur key = 40 search karna hai:
  - Root = 50, 40 < 50, left subtree (30)
  - Root = 30, 40 > 30, right subtree (40)
  - Root = 40, 40 == 40, key mil gaya, return true

Dry Run:
1. Initial setup: root = 50, key = 40.
2. Execution steps:
   - itSearch(50, 40) -> root = 30 -> root = 40 -> return true.
3. Final output: Key 40 found using iterative search.

Output:
Iterative Search: Key 40 found using iterative search.
*/
