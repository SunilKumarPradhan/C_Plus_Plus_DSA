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

int preIndex = 0;

node *cTree(int in[], int pre[], int is, int ie) {
    if (is > ie) return NULL;
    node *root = new node(pre[preIndex++]);

    int inIndex;
    for (int i = is; i <= ie; i++) {
        if (in[i] == root->key) {
            inIndex = i;
            break;
        }
    }
    root->left = cTree(in, pre, is, inIndex - 1);
    root->right = cTree(in, pre, inIndex + 1, ie);
    return root;
}

void inorderPrint(node *root) {
    if (root == NULL) return;
    inorderPrint(root->left);
    cout << root->key << " ";
    inorderPrint(root->right);
}

int main() {
    int in[] = {1, 2, 3, 4, 5};
    int pre[] = {3, 2, 1, 4, 5};
    int len = sizeof(in)/sizeof(in[0]);

    node *root = cTree(in, pre, 0, len - 1);

    cout << "Inorder traversal of the constructed tree: ";
    inorderPrint(root);

    return 0;
}

/*
Iss code mein ek function hai jo inorder aur preorder traversal se binary tree ko construct karta hai aur uske baad us tree ka inorder traversal print karta hai.

- Function ka naam hai cTree aur yeh binary tree ko construct karta hai inorder aur preorder traversal arrays se:
  1. Agar is (starting index) > ie (ending index), toh NULL return karte hain. Yeh base case hai.
  2. Naya node create karte hain preorder array ke current index se aur preIndex ko increment karte hain.
  3. Inorder array mein current node ki position (inIndex) ko find karte hain.
  4. Left subtree aur right subtree ko recursively construct karte hain using inorder array ke segments:
     - Left subtree: is se inIndex - 1 tak.
     - Right subtree: inIndex + 1 se ie tak.
  5. Root node ko return karte hain.

Process:
- Pehle, root node create hota hai preorder array ke pehle element se.
- Phir, inorder array mein us root node ka index find hota hai.
- Left aur right subtrees recursively construct hote hain.

Example:
- Agar inorder array hai: [1, 2, 3, 4, 5]
- Aur preorder array hai: [3, 2, 1, 4, 5]

- cTree function call hota hai aur tree ban jata hai:
      3
     / \
    2   4
   /     \
  1       5

Dry Run:
1. Inorder array: [1, 2, 3, 4, 5]
   Preorder array: [3, 2, 1, 4, 5]

2. cTree function call hota hai:
   - Root = 3 (pre[0])
   - Inorder index of 3 = 2

3. Left subtree:
   - Inorder array: [1, 2]
   - Preorder array: [2, 1]

4. Right subtree:
   - Inorder array: [4, 5]
   - Preorder array: [4, 5]

5. Tree ka structure:
      3
     / \
    2   4
   /     \
  1       5

Output:
Inorder traversal of the constructed tree: 1 2 3 4 5
*/
