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

int findCeiling(node* root, int k) {
    int ceiling = -1;
    
    while (root != NULL) {
        if (root->key == k) return root->key;
        
        if (k > root->key) root = root->right;
        else {
            ceiling = root->key;
            root = root->left;
        }
    }
    return ceiling;
}


int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    cout << "  ";

    int result = findCeiling(root, 35);
    if (result == -1)
        cout << "Ceiling doesn't exist in the BST" << endl;
    else
        cout << "The Ceiling is: " << result << endl;

    return 0;
}


/*
Iss function ka naam hai findCeiling aur yeh BST (Binary Search Tree) mein given key se bada ya barabar sabse chhota value (ceiling) dhoondhta hai.

- Function ka logic:
  1. Agar root NULL hai, toh ceiling nahi mil sakta, return -1.
  2. Har step pe, agar current node ka key given key ke barabar hai, toh wahi ceiling hai, return kar do.
  3. Agar current node ka key given key se chhota hai, toh right subtree mein search karo.
  4. Agar current node ka key given key se bada hai, toh current node ko potential ceiling set karo aur left subtree mein search karo.

Process:
- Pehle, root se shuru karte hain aur ceiling ko -1 se initialize karte hain.
- Har node pe check karte hain agar key barabar hai toh wahi ceiling return karte hain.
- Agar key chhoti hai, toh right subtree mein search karte hain.
- Agar key badi hai, toh current node ko ceiling set karte hain aur left subtree mein search karte hain.

Example:
- Agar BST hai:
       50
      /  \
     30   70
    / \   / \
   20 40 60  80

- Function call findCeiling(root, 35) ka output hoga 40 kyunki 35 ke liye ceiling 40 hai.

Dry Run:
1. BST ka structure:
       50
      /  \
     30   70
    / \   / \
   20 40 60  80

2. findCeiling(root, 35):
   - root = 50, ceiling = -1
   - 35 < 50, ceiling = 50, move to left subtree (root = 30)
   - root = 30, ceiling = 50
   - 35 > 30, move to right subtree (root = 40)
   - root = 40, ceiling = 50
   - 35 < 40, ceiling = 40, move to left subtree (root = NULL)
   - root = NULL, end of search

3. Output:
   - The Ceiling is: 40
*/
