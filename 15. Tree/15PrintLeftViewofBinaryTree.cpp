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

// THIS IS THE RECURSIVE APPROACH--------

// int maxLevel=0;
// void leftView(node *root,int level){
//     if(root==NULL) return;
//     if(maxLevel <level){
//         cout<<root->key <<" ";
//         maxLevel=level;
//     }
//     leftView(root->left , level+1);
//     leftView(root->right , level+1);
// }

// void printLeftView(node *root ){
//     leftView(root,1);
// }

// THIS IS THE ITERATIVE APPROACH -----
void printLeftView(node *root) {
    if (root == NULL) return;
    queue<node *> q;
    q.push(root);
    

    while (!q.empty()) {
        int count = q.size();
        for (int i = 0; i < count; i++) {
            node *curr = q.front();
            q.pop();
            
            if (i == 0) cout << curr->key << " "; 
            if (curr->left) q.push(curr->left); 
            if (curr->right) q.push(curr->right);
        }
    }
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);
    cout << "The LeftView of the tree is : " << endl;
    printLeftView(root);
    return 0; // Program ka execution yaha se shuru hota hai.
}

/*

Iss program mein hum left view of a binary tree ko find kar rahe hai, iterative approach mein.

Ek queue use kiya jata hai jo nodes ke addresses ko store karta hai.
Queue mein root node initially push kiya jata hai.

While loop chalta hai jab tak queue khali na ho:
  - Har iteration mein queue ka size count kiya jata hai.
  - Har level ke nodes ko print karne ke liye ek loop chalate hai:
    - Queue se current node ko pop kiya jata hai.
    - Agar ye first node of current level hai (i == 0), to uska key print kiya jata hai.
    - Agar left child exist karta hai, to queue mein push kiya jata hai.
    - Agar right child exist karta hai, to queue mein push kiya jata hai.

Dry Run:
1. Humare tree ka structure:
       3
      / \
     2   4
    /     \
   1       5

2. printLeftView function call hota hai:
   - queue mein root (3) push kiya jata hai.

3. While loop shuru hota hai (jab tak queue khali na ho):
   - count = 1, i = 0
     - curr = 3, queue se pop kiya jata hai, aur 3 print kiya jata hai.
     - Left child (2) queue mein push kiya jata hai.
     - Right child (4) queue mein push kiya jata hai.

   - count = 2, i = 0
     - curr = 2, queue se pop kiya jata hai, aur 2 print kiya jata hai.
     - Left child (1) queue mein push kiya jata hai.

   - count = 1, i = 0
     - curr = 4, queue se pop kiya jata hai, aur 4 print kiya jata hai.
     - Right child (5) queue mein push kiya jata hai.

   - count = 1, i = 0
     - curr = 1, queue se pop kiya jata hai, aur 1 print kiya jata hai.

   - count = 1, i = 0
     - curr = 5, queue se pop kiya jata hai, aur 5 print kiya jata hai.

4. While loop khatam ho jata hai aur output "The LeftView of the tree is :" ke saath 3 2 1 print hota hai.

Output:
The LeftView of the tree is :
3 2 1
*/
