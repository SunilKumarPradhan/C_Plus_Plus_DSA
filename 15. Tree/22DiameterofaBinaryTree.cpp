#include <bits/stdc++.h> 
using namespace std;

struct node {
    int key;
    node *left, *right;
    node(int k) : key(k), left(NULL), right(NULL) {}
};

int height(node* root, int& diameter) {
    if (!root) return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(node* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(45);
    root->left->right = new node(25);
    root->right->right = new node(35);

    cout << "Diameter: " << diameterOfBinaryTree(root) << endl;
    return 0; 
}


/*
Iss function ka naam hai height aur yeh tree ka height return karta hai aur saath hi saath tree ka diameter calculate karta hai.

Efficient approach:
- Function height recursive hai aur har node pe call hota hai.
- Har call mein left aur right subtree ka height calculate karte hain.
- Phir, un heights ka sum aur root ko include karke diameter ka maximum value res variable mein store karte hain.
- Return karte hain current node ka height (1 + max(left height, right height)).

Example:
- Agar tree hai:
       1
      / \
     2   3
    / \ / \
   7  6 5  4

- Diameter of tree: Maximum number of nodes on the longest path between two leaf nodes (in this case, path from 7 to 4 via root 1).

Process:
- Har node pe height function call hota hai aur res update hota hai.

Dry Run:
1. Tree ka structure:
       1
      / \
     2   3
    / \ / \
   7  6 5  4

2. height function call hota hai root = 1:
   - root = 1, lh = height(root->left) = 2, rh = height(root->right) = 2
   - res = max(res, lh + rh + 1) = 5

3. height function call hota hai root->left = 2:
   - root = 2, lh = height(root->left) = 1, rh = height(root->right) = 1
   - res = max(res, lh + rh + 1) = 3

4. height function call hota hai root->right = 3:
   - root = 3, lh = height(root->left) = 1, rh = height(root->right) = 1
   - res = max(res, lh + rh + 1) = 3

5. Continue recursive calls for leaf nodes.

Output:
The diameter of binary tree is: 5
*/