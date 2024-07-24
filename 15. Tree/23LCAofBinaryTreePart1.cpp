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

bool findPath(node *root, vector<node*> &p, int n) {
    if (root == NULL) return false;

    p.push_back(root);

    if (root->key == n) return true;

    if (findPath(root->left, p, n) || findPath(root->right, p, n)) return true;

    p.pop_back();  // Correctly use pop_back to remove the last element
    return false;
}

node* LCAofBinTree(node *root, int n1, int n2) {
    vector<node*> path1, path2; // Create two vectors

    if (findPath(root, path1, n1) == false || findPath(root, path2, n2) == false) return NULL;

    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] != path2[i]) break;
    }
    return path1[i-1];
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    int n1 = 1, n2 = 5; // Example nodes to find LCA
    node* lca = LCAofBinTree(root, n1, n2);
    if (lca != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca->key << endl;
    else
        cout << "LCA does not exist" << endl;

    return 0;
}


/*
Iss function ka naam hai findPath aur yeh function diya hua node tak ka path nikalta hai.
- Yeh vector p ko update karta hai jo root se given node tak ka path store karta hai.
- Function recursive hai:
  1. Agar root NULL hai, toh false return karo.
  2. Current node ko path mein add karo.
  3. Agar current node ka key, given key ke barabar hai, toh true return karo.
  4. Left aur right subtree ko recursively check karo.
  5. Agar node nahi mila, toh path se current node ko remove kar do (pop_back).

Process:
- Har node pe recursive call hota hai aur path update hota hai.

Example:
- Agar tree hai:
       3
      / \
     2   4
    /     \
   1       5
- Given nodes n1 = 1, n2 = 5
- Paths nikalenge:
  - Path1: 3 -> 2 -> 1
  - Path2: 3 -> 4 -> 5

Dry Run:
1. findPath function call hota hai root = 3:
   - root = 3, add 3 to path
   - call findPath(root->left, path, 1):
     - root = 2, add 2 to path
     - call findPath(root->left, path, 1):
       - root = 1, add 1 to path
       - return true (path1 = {3, 2, 1})
   - call findPath(root->right, path, 5):
     - root = 4, add 4 to path
     - call findPath(root->right, path, 5):
       - root = 5, add 5 to path
       - return true (path2 = {3, 4, 5})

2. LCA find karne ke liye, common path elements compare karte hain.
   - path1 = {3, 2, 1}
   - path2 = {3, 4, 5}
   - Common node 3 tak traverse karo. 3 is the LCA.

Output:
LCA of 1 and 5 is 3
*/