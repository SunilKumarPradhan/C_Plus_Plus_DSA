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

int getMax(node *root){
    if(root==NULL) return INT_MIN;
    else return max( root->key ,max( getMax(root->left), getMax(root->right) ) );
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);
    cout << "The MaxNode of the tree is : " << getMax(root) << endl;
    return 0;
}

/*
Iss function ka naam hai getMax aur yeh BST (Binary Search Tree) ya kisi bhi binary tree mein sabse bada node value return karta hai.

- Function recursive hai aur har node pe call hota hai:
  1. Agar root NULL hai (i.e., empty tree ya leaf node ka child), toh INT_MIN return karte hain. Yeh base case hai.
  2. Agar root NULL nahi hai, toh:
     - Left subtree aur right subtree mein se maximum value nikalte hain.
     - Current node ka key aur subtree maximum ke beech maximum value return karte hain.

Process:
- Pehle, left subtree aur right subtree mein maximum values calculate hoti hain.
- Uske baad, in maximum values ko current node ke key ke saath compare karke sabse bada value return karte hain.

Example:
- Agar tree hai:
       3
      / \
     2   4
    /     \
   1       5

- getMax function call hota hai aur output 5 hoga kyunki 5 is the largest value in the tree.

Dry Run:
1. Tree ka structure:
       3
      / \
     2   4
    /     \
   1       5

2. getMax function call hota hai root = 3:
   - root = 3, left = 2, right = 4

3. getMax(root->left) ke liye root = 2:
   - root = 2, left = 1, right = NULL
   - getMax(root->left) ke liye root = 1:
     - root = 1, left = NULL, right = NULL
     - Return 1 (1 is the only value in this subtree)
   - getMax(root->right) ke liye root = NULL:
     - Return INT_MIN (No node)

   - Maximum value in left subtree = max(1, INT_MIN) = 1
   - Maximum value of node 2 = max(2, 1) = 2

4. getMax(root->right) ke liye root = 4:
   - root = 4, right = 5
   - getMax(root->left) ke liye root = NULL:
     - Return INT_MIN (No node)
   - getMax(root->right) ke liye root = 5:
     - root = 5, left = NULL, right = NULL
     - Return 5 (5 is the only value in this subtree)
   
   - Maximum value in right subtree = max(INT_MIN, 5) = 5
   - Maximum value of node 4 = max(4, 5) = 5

5. Maximum value in the entire tree = max(3, max(2, 5)) = 5

Output:
The MaxNode of the tree is : 5
*/
