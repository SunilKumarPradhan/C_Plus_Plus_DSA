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

node *BTtoDLL(node *root, node *&prev, node *&head) {
    if (root == NULL) return root;
    BTtoDLL(root->left, prev, head);
    if (prev == NULL) head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTtoDLL(root->right, prev, head);
    return head;
}

void printDLL(node* head) {
    while (head != NULL) {
        cout << head->key << " ";
        head = head->right;
    }
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    node *prev = NULL;
    node *head = NULL;
    head = BTtoDLL(root, prev, head);
    printDLL(head);

    return 0;
}

/*
Iss code mein ek binary tree ko doubly linked list (DLL) mein convert karne ka function hai.

- Function ka naam hai BTtoDLL aur yeh binary tree ko DLL mein convert karta hai:
  1. Agar root NULL hai, toh kuch nahi karte aur return kar dete hain. Yeh base case hai.
  2. Pehle left subtree ko convert karte hain DLL mein.
  3. Current node ko DLL mein add karte hain:
     - Agar prev NULL hai, iska matlab current node head node hai aur head ko set kar dete hain.
     - Agar prev NULL nahi hai, toh:
       - Current node ke left pointer ko prev node set karte hain.
       - Prev node ke right pointer ko current node set karte hain.
     - Prev node ko update karte hain current node ke saath.
  4. Phir, right subtree ko convert karte hain DLL mein.

Process:
- Pehle tree ke left subtree ko DLL mein convert karte hain.
- Phir, current node ko DLL mein add karte hain.
- Finally, right subtree ko DLL mein convert karte hain.

Example:
- Agar binary tree hai:
       3
      / \
     2   4
    /     \
   1       5

- BTtoDLL function call hota hai aur DLL ban jata hai:
   1 <-> 2 <-> 3 <-> 4 <-> 5

Dry Run:
1. Tree ka structure:
       3
      / \
     2   4
    /     \
   1       5

2. BTtoDLL function call hota hai root = 3:
   - root = 3, left = 2, right = 4

3. Left subtree ke liye:
   - root = 2, left = 1
   - root = 1, left = NULL, right = NULL (1 is the only value in this subtree)
   - 2 ka left pointer = 1 aur 1 ka right pointer = 2

4. 3 ka left pointer = 2 aur 2 ka right pointer = 3
   - Phir 4 ke liye:
     - root = 4, right = 5
     - 5 ka left pointer = 4 aur 4 ka right pointer = 5

5. Final DLL:
   - 1 <-> 2 <-> 3 <-> 4 <-> 5

Output:
1 2 3 4 5 
*/
