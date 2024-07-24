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

void verticalSumUtil(node* root, int hd, map<int, int> &sums) {
    if (root == NULL) return;
    verticalSumUtil(root->left, hd - 1, sums);
    sums[hd] += root->key;
    verticalSumUtil(root->right, hd + 1, sums);
}

void verticalSum(node* root) {
    map<int, int> sums;
    verticalSumUtil(root, 0, sums);
    for (auto it : sums) {
        cout << "Vertical sum at distance " << it.first << " is " << it.second << endl;
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

    verticalSum(root);

    return 0;
}

/*
Iss function ka naam hai verticalSumUtil aur yeh ek binary tree ke nodes ki vertical sum calculate karta hai.

- Function ka logic:
  1. Agar root NULL hai, to function return kar jata hai.
  2. Left subtree ko traverse karte hai aur horizontal distance (hd) ko -1 karte hai.
  3. Current node ka key sum ke map me horizontal distance (hd) par add karte hai.
  4. Right subtree ko traverse karte hai aur horizontal distance (hd) ko +1 karte hai.

Process:
- Pehle, left subtree traverse karte hai (hd ko -1 karte hue).
- Uske baad, current node ka key map me add karte hai.
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
   - Root = 50, hd = 0, sums = {}

2. Traversal:
   - Traverse left of 50: hd = -1
     - Traverse left of 30: hd = -2
       - Traverse left of 20: hd = -3
         - 20 is added to sums at hd = -3
       - 20 ka key add hota hai, sums[-3] = 20
       - Traverse right of 20: hd = -2
     - 30 ka key add hota hai, sums[-2] = 30
     - Traverse right of 30: hd = -1
       - 40 is added to sums at hd = -1
       - 40 ka key add hota hai, sums[-1] = 40
     - 30 ka traversal complete hota hai
   - 50 ka key add hota hai, sums[0] = 50
   - Traverse right of 50: hd = 1
     - Traverse left of 70: hd = 0
       - 60 is added to sums at hd = 0
       - 60 ka key add hota hai, sums[0] = 110
     - Traverse right of 70: hd = 2
       - 80 is added to sums at hd = 2
       - 80 ka key add hota hai, sums[2] = 80

3. Final output:
   - sums = {-3: 20, -2: 30, -1: 40, 0: 110, 1: 60, 2: 80}

Output:
Vertical sum at distance -3 is 20
Vertical sum at distance -2 is 30
Vertical sum at distance -1 is 40
Vertical sum at distance 0 is 110
Vertical sum at distance 1 is 60
Vertical sum at distance 2 is 80
*/
