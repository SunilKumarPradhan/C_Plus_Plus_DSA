#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    node *left, *right;

    node(int k) {
        key = k;
        left = right = NULL;
    }
};


node* findFloor(node* root, int key) {
    node* floor = NULL;
    while (root) {
        if (root->key == key) return root;
        if (key > root->key) {
            floor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    int key = 65;
    node* floorNode = findFloor(root, key);
    
    if (floorNode) {
        cout << "Floor value of " << key << " is " << floorNode->key << endl;
    } else {
        cout << "Floor value of " << key << " does not exist in the BST" << endl;
    }

    return 0;
}
/*

Iss function ka naam hai findFloor aur yeh BST (Binary Search Tree) mein ek diya hua key ka floor value nikalta hai.
Floor value wo sabse bada value hai jo given key se chhota ya uske barabar hota hai.

- Pehle, hum ek pointer floorNode ko NULL se initialize karte hain. Yeh pointer floor value ko track karega.
- Phir, hum BST ko traverse karte hain:

  1. Agar current node ka key, given key ke barabar hota hai, toh directly current node ko return kar do.
     Yeh isliye kyunki agar key match ho gaya, toh wahi floor value hoga.
     
  2. Agar given key, current node ke key se bada hota hai:
     - Hum floorNode ko current node set kar dete hain kyunki current node ka key ab tak ka largest key hai jo given key se chhota ya barabar hai.
     - Fir, hum right subtree mein move karte hain kyunki ho sakta hai waha aur bada key mil jaye jo given key se chhota ya barabar ho.
     
  3. Agar given key, current node ke key se chhota hota hai:
     - Hum left subtree mein move karte hain kyunki chhota key left side mein hi milega.
  
- Yeh process tab tak repeat hota hai jab tak hum leaf node tak nahi pahunch jate (root becomes NULL).

- Agar loop khatam ho jata hai bina exact match ke, toh floorNode ko return kar do. Yeh woh node hoga jiska key given key se chhota ya barabar hai aur largest hai.



Dry Run:
1. Humare tree ka structure:
       50
      /  \
    30    70
   / \   /  \
  20 40 60  80

2. key = 65
3. findFloor function call hota hai:
   - floorNode = NULL
   - root = 50
     - 65 > 50, floorNode = 50, root = 70
   - root = 70
     - 65 < 70, root = 60
   - root = 60
     - 65 > 60, floorNode = 60, root = NULL
4. Loop end hota hai aur floorNode (60) return hota hai.

Output:
Floor value of 65 is 60
*/