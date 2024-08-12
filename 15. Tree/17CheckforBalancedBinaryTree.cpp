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

int isBalanced(node *root) {
    if (root == NULL) return 0;

    int lh = isBalanced(root->left);
    if (lh == -1) return -1;

    int rh = isBalanced(root->right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;

    else return max(lh, rh) + 1;
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    cout << "\nThe isBalanced of the tree is : ";

    if (isBalanced(root))
        cout << "True";
    else
        cout << "False";

    return 0; // Program ka execution yaha se shuru hota hai.
}

/*

Iss program mein hum isBalanced function ka use karke check kar rahe hai ki ek binary tree balanced hai ya nahi.

Ek binary tree balanced hota hai agar har node ka left aur right subtree ka height difference 1 se jyada nahi hota hai.

isBalanced function recursive approach mein implement kiya gaya hai:
- Agar root NULL hai, to 0 return kiya jata hai.
- Left subtree ke liye isBalanced function ko call kiya jata hai (lh).
- Agar left subtree unbalanced hai (-1 return karta hai), to -1 return kiya jata hai.
- Right subtree ke liye isBalanced function ko call kiya jata hai (rh).
- Agar right subtree unbalanced hai (-1 return karta hai), to -1 return kiya jata hai.
- Agar current node ka left aur right subtree ka height difference 1 se jyada hai, to -1 return kiya jata hai.
- Agar sab thik hai, to max(lh, rh) + 1 return kiya jata hai.

Dry Run:
1. Humare tree ka structure:
       3
      / \
     2   4
    /     \
   1       5

2. isBalanced function call hota hai:
   - root = 3
   - lh = isBalanced(2)
     - root = 2
     - lh = isBalanced(1)
       - root = 1
       - isBalanced(NULL) return 0
       - rh = 0
       - abs(0 - 0) = 0 <= 1, max(0, 0) + 1 = 1 return
     - rh = isBalanced(NULL) return 0
     - abs(1 - 0) = 1 <= 1, max(1, 0) + 1 = 2 return
   - rh = isBalanced(4)
     - root = 4
     - lh = isBalanced(NULL) return 0
     - rh = isBalanced(5)
       - root = 5
       - isBalanced(NULL) return 0
       - lh = 0
       - rh = 0
       - abs(0 - 0) = 0 <= 1, max(0, 0) + 1 = 1 return
     - abs(0 - 1) = 1 <= 1, max(0, 1) + 1 = 2 return
   - abs(2 - 2) = 0 <= 1, max(2, 2) + 1 = 3 return

3. isBalanced(root) return 3, which is not equal to -1, so True print hoga.

Output:
The isBalanced of the tree is : True
*/
