#include <iostream>
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

node* findLCA(node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->key == n1 || root->key == n2) return root;
        
    node* leftLCA = findLCA(root->left, n1, n2);
    node* rightLCA = findLCA(root->right, n1, n2);
    if (leftLCA && rightLCA) return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    node* root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    int n1 = 1, n2 = 5;
    node* lca = findLCA(root, n1, n2);
    if (lca != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca->key << endl;
    else
        cout << "LCA does not exist" << endl;
    return 0;
}


/*
Iss function ka naam hai findLCA aur yeh function binary tree mein given do nodes ka Lowest Common Ancestor (LCA) nikalta hai.
- Yeh function recursive hai aur root node se shuru hota hai.
- Function ka base case yeh hai:
  1. Agar root NULL hai, toh NULL return karo.
  2. Agar root ka key n1 ya n2 ke barabar hai, toh root return karo.
- Left aur right subtree ko recursively call karte hain:
  1. Agar left aur right subtree dono mein se ek ek LCA milta hai, toh current root LCA hai.
  2. Agar sirf left subtree ya sirf right subtree mein LCA milta hai, toh wahi LCA hoga.

Process:
- Tree ko recursively traverse karte hain.
- Agar kisi node pe, dono given nodes left aur right subtree mein milte hain, toh woh node LCA hota hai.
- Agar sirf ek subtree mein milte hain, toh wahi subtree ka result LCA hota hai.

Example:
- Agar tree hai:
       3
      / \
     2   4
    /     \
   1       5
- Given nodes n1 = 1, n2 = 5
- Tree ko traverse karte hain aur 3 common ancestor milta hai.

Dry Run:
1. findLCA function call hota hai root = 3:
   - root = 3, n1 = 1, n2 = 5
   - call findLCA(root->left, n1, n2):
     - root = 2
     - call findLCA(root->left, n1, n2):
       - root = 1 (matches n1)
       - return node 1
     - call findLCA(root->right, n1, n2):
       - root = NULL
       - return NULL
     - leftLCA = node 1, rightLCA = NULL
     - return node 1
   - call findLCA(root->right, n1, n2):
     - root = 4
     - call findLCA(root->left, n1, n2):
       - root = NULL
       - return NULL
     - call findLCA(root->right, n1, n2):
       - root = 5 (matches n2)
       - return node 5
     - leftLCA = NULL, rightLCA = node 5
     - return node 5
   - leftLCA = node 1, rightLCA = node 5
   - return node 3

Output:
LCA of 1 and 5 is 3
*/