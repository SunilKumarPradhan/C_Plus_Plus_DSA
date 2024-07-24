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

bool findPair(node* root, unordered_set<int> &set, int sum) {
    if (root == NULL) return false;
    if (findPair(root->left, set, sum)) return true;
    if (set.find(sum - root->key) != set.end()) return true;
    set.insert(root->key);
    return findPair(root->right, set, sum);
}

bool isPairPresent(node* root, int sum) {
    unordered_set<int> set;
    return findPair(root, set, sum);
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    int sum = 100;
    cout<< (isPairPresent(root, sum) ? "Pair found with the given sum "+ to_string(sum): "No pair found with the given sum "+ to_string(sum) )<< endl;
    
    return 0;
}

/*
Iss function ka naam hai findPair aur yeh BST (Binary Search Tree) mein do nodes ka pair find karta hai jinki sum diya gaya target sum ke barabar hoti hai.

- Function ka logic:
  1. Traverse karte hain BST ko inorder traversal ke through.
  2. Har node ke value ko check karte hain ki kya sum minus current node value already set mein maujood hai.
  3. Agar hai, toh pair mil gaya, otherwise, current node value ko set mein add kar dete hain aur next node ko traverse karte hain.

Process:
- Pehle, left subtree ko traverse karte hain.
- Fir, check karte hain ki kya current node ki value se sum minus current node ki value set mein hai.
- Agar set mein value milti hai, toh true return kar dete hain.
- Agar nahi milti, toh current node ki value ko set mein add karte hain aur right subtree ko traverse karte hain.

Example:
- Agar BST mein yeh nodes hain:
       50
      /  \
     30   70
    / \   / \
   20 40 60  80

  Aur target sum hai 100, toh:
  - Pairs check karte hain:
    - 50 + 50 = 100 (Not possible as pair should be distinct nodes)
    - 30 + 70 = 100 (Valid pair)

- Function call isPairPresent(root, sum) se pair mil jayega aur output hoga "Pair found with the given sum 100".

Dry Run:
1. BST ka structure:
       50
      /  \
     30   70
    / \   / \
   20 40 60  80

2. Function call isPairPresent(root, 100):
   - Traverse left subtree:
     - Node 20: set = {}
     - Node 30: set = {20}
     - Node 40: set = {20, 30}
   - Node 50: set = {20, 30, 40}
   - Node 70: set = {20, 30, 40, 50}
   - Node 80: set = {20, 30, 40, 50, 70}

   - Node 50 ke sum (100 - 50 = 50) found in set.
   - Pair 30 + 70 is found.

3. Output:
   - Pair found with the given sum 100
*/
