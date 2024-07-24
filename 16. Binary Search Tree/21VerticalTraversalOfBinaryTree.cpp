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

void verticalTraversalUtil(node* root, int hd, map<int, vector<int>> &m) {
    if (root == NULL) return;
    m[hd].push_back(root->key);
    verticalTraversalUtil(root->left, hd - 1, m);
    verticalTraversalUtil(root->right, hd + 1, m);
}

void verticalTraversal(node* root) {
    map<int, vector<int>> m;
    verticalTraversalUtil(root, 0, m);
    for (auto it : m) {
        cout << "Vertical level " << it.first << ": ";
        for (int i : it.second) {
            cout << i << " ";
        }
        cout << endl;
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

    verticalTraversal(root);

    return 0;
}


/*
Iss function ka naam hai verticalTraversalUtil aur yeh ek binary tree ke nodes ko vertical order me traverse karta hai.

- Function ka logic:
  1. Agar root NULL hai, to function return kar jata hai.
  2. Current node ka key map me horizontal distance (hd) par add karte hai.
  3. Left subtree ko traverse karte hai aur hd ko -1 karte hai.
  4. Right subtree ko traverse karte hai aur hd ko +1 karte hai.

Process:
- Pehle, current node ka key map me horizontal distance (hd) par add karte hai.
- Phir, left subtree traverse karte hai (hd ko -1 karte hue).
- Finally, right subtree traverse karte hai (hd ko +1 karte hue).

Example:
- Agar tree hai:

      50
     /  \
    30   70
   / \   / \
  20 40 60 80

then

Tree structure:
       50
     /    \
    30     70
   / \    / \
  20 40  60 80

Dry Run:
1. Initial setup:
   - Root = 50, hd = 0, m = {}

2. Traversal:
   - 50 ka key add hota hai m[0] = [50]
   - Traverse left of 50: hd = -1
     - 30 ka key add hota hai m[-1] = [30]
     - Traverse left of 30: hd = -2
       - 20 ka key add hota hai m[-2] = [20]
     - Traverse right of 30: hd = -1
       - 40 ka key add hota hai m[-1] = [30, 40]
   - Traverse right of 50: hd = 1
     - 70 ka key add hota hai m[1] = [70]
     - Traverse left of 70: hd = 0
       - 60 ka key add hota hai m[0] = [50, 60]
     - Traverse right of 70: hd = 2
       - 80 ka key add hota hai m[2] = [80]

3. Final output:
   - m = {-2: [20], -1: [30, 40], 0: [50, 60], 1: [70], 2: [80]}

Output:
Vertical level -2: 20 
Vertical level -1: 30 40 
Vertical level 0: 50 60 
Vertical level 1: 70 
Vertical level 2: 80 
*/
