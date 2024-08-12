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
node* MakeTree(int in[], int pre[], int Si, int Ei) {
    if (Si > Ei) return NULL;
    node *root = new node(pre[preIndex++]);//  pre index upar declared hai

    int inIndex = Si;
    while (inIndex <= Ei && in[inIndex] != root->key) {
        inIndex++;
    }

    root->left = MakeTree(in, pre, Si, inIndex - 1);
    root->right = MakeTree(in, pre, inIndex + 1, Ei);
    
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
    int size = sizeof(in) / sizeof(in[0]);

    node *root = MakeTree(in, pre, 0, size - 1);
    
    cout << "Inorder traversal of the constructed tree: ";
    inorderPrint(root);

    return 0;
}


/*
Iss function ka naam hai MakeTree aur yeh function inorder aur preorder traversal arrays se ek binary tree banata hai.

- Function ka logic:
  1. `preIndex` ek global variable hai jo preorder array ke current node ka index track karta hai.
  2. Sabse pehle, current node ko create karte hain jo preorder array se li jaati hai (`pre[preIndex]`).
  3. Phir, us node ka position inorder array mein dhundhte hain.
  4. Us position se left aur right subtrees ko recursively build karte hain.

Process:
- Pehle, root node ko preorder array se liya jata hai (pehla element) aur usse create kiya jata hai.
- Phir, us root node ka index inorder array mein dhunda jata hai.
- Inorder array ke us index se left aur right subtree ke liye recursive calls hoti hain.
- In recursion, left subtree ko inorder array ke pehle part se banaya jata hai aur right subtree ko baad wale part se.

Example:
- Agar inorder array hai: [1, 2, 3, 4, 5]
- Aur preorder array hai: [3, 2, 1, 4, 5]

- Toh binary tree banega:
       3
      / \
     2   4
    /     \
   1       5

Dry Run:
1. Preorder: [3, 2, 1, 4, 5]
   Inorder:  [1, 2, 3, 4, 5]

2. First Call:
   - Root node `3` (preorder[0]) se banti hai.
   - Inorder array mein `3` ka index 2 hai.
   - Left subtree: inorder array ka part [1, 2], preorder array se next elements [2, 1].
   - Right subtree: inorder array ka part [4, 5], preorder array se next elements [4, 5].

3. Recursion Left Subtree:
   - Root node `2` se banti hai (preorder[1]).
   - Inorder array mein `2` ka index 1 hai.
   - Left subtree: [1], next element [1].
   - Right subtree: [], koi element nahi.

4. Recursion Right Subtree:
   - Root node `4` se banti hai (preorder[3]).
   - Inorder array mein `4` ka index 3 hai.
   - Left subtree: [], koi element nahi.
   - Right subtree: [5], next element [5].

5. Final Tree:
       3
      / \
     2   4
    /     \
   1       5

6. Inorder traversal of constructed tree: [1, 2, 3, 4, 5]
   - Output: 1 2 3 4 5
*/