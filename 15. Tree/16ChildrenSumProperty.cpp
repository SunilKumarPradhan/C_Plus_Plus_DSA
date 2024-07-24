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

bool isChildSum(node *root){
    if(root==NULL) return 0;
    if(root->left == NULL && root->right==NULL) return true;

    int sum=0;
    if(root->left!=NULL) sum+=root->left->key;
    if(root->right!=NULL) sum+=root->right->key;

    return (root->key == sum && isChildSum(root->left) && isChildSum(root->right));
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);
    cout << "The isChildSum of the tree is : ";

    if (isChildSum(root)) cout<<"True";
    else cout<< "False";
  
    return 0;
}

/*
Iss function ka naam hai isChildSum aur yeh check karta hai ki binary tree mein har node ka key value uske children ke keys ka sum hai ya nahi.

- Function recursive hai aur har node ke liye check karta hai:
  1. Agar root NULL hai, toh false return karte hain. Yeh base case hai.
  2. Agar root ke paas left aur right dono children nahi hain (i.e., leaf node hai), toh true return karte hain. Yeh isliye kyunki leaf nodes ka sum condition ke under hota hai (koi child nahi hota).
  3. Agar root ke paas children hain, toh:
     - Hum left aur right children ke keys ka sum calculate karte hain.
     - Check karte hain ki root ka key sum ke barabar hai ya nahi.
     - Aur yeh bhi check karte hain ki left aur right subtrees bhi isChildSum condition ko satisfy karte hain ya nahi.

Process:
- Pehle, har node ke children ke keys ka sum calculate hota hai.
- Phir, root node ke key aur sum compare karte hain.
- Agar root node ka key sum ke barabar hai aur left aur right subtrees bhi isChildSum condition ko satisfy karte hain, toh true return karte hain.

Example:
- Agar tree hai:
       3
      / \
     2   4
    /     \
   1       5

- 3 = 2 + 4, isliye function false return karega.

Dry Run:
1. Tree ka structure:
       3
      / \
     2   4
    /     \
   1       5

2. isChildSum function call hota hai root = 3:
   - root = 3, left = 2, right = 4
   - left aur right ke keys ka sum = 2 + 4 = 6 (not equal to 3)
   - Function call for left subtree with root = 2:
     - root = 2, left = 1, right = NULL
     - 2 = 1 (key of left child), condition satisfy nahi hota hai for this subtree
   - Function call for right subtree with root = 4:
     - root = 4, left = NULL, right = 5
     - 4 = 5 (key of right child), condition satisfy nahi hota

3. Final result:
   - Root node 3 ki condition satisfy nahi hoti hai kyunki 3 ≠ 6
   - Output: False
*/
