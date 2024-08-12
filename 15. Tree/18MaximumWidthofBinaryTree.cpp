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


int maxWidth(node *root) {
  if (root == NULL) return 0;
    queue<node*> q;
    
    q.push(root);
    int maxWidth = 0;
    
    while (!q.empty()) {
        int count = q.size();
        maxWidth = max(maxWidth, count);

        for (int i = 0; i < count; i++) {
            node *curr = q.front();
            q.pop();

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return maxWidth;
}


int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->right = new node(8);

    cout << "The maxWidth of the tree is : " << maxWidth(root) << endl;
  
    return 0; 
}



/*
Iss function ka naam hai maxWidth aur yeh function ek binary tree ki maximum width calculate karta hai. Maximum width ka matlab hota hai ek level par sabse zyada nodes ki sankhya.

- Function ka logic:
  1. Agar tree ka root NULL hai, toh width 0 return karte hain.
  2. Hum ek queue ka use karte hain level-wise traversal ke liye. Har level ke nodes ko count karte hain aur maximum width ko update karte hain.
  3. Queue mein nodes ko push karte hain aur unke left aur right children ko agle level ke nodes ke roop mein add karte hain.
  4. Har iteration mein, queue ki size ko check karte hain jo ki current level par nodes ki sankhya batata hai. Is value ko maxWidth se compare karte hain aur zyada hone par maxWidth ko update karte hain.

Process:
- Pehle, root node ko queue mein push karte hain.
- Phir, har level par jitne nodes hain unko process karte hain, aur unke children ko queue mein push karte hain.
- Har level ke nodes ki count ko check karte hain aur maximum width ko update karte hain.

Example:
- Agar tree hai:

       1
      / \
     2   3
    / \  / \
   4   5 6  7
            \
             8

- Is tree ka maxWidth 4 hoga kyunki third level par 4 nodes hain (4, 5, 6, 7).

Dry Run:
1. Tree ka structure:
       1
      / \
     2   3
    / \  / \
   4   5 6  7
            \
             8

2. maxWidth function call hota hai root = 1:
   - Queue mein sirf root node 1 hoti hai. Is level ki width 1 hai.
   - Next level mein 2 aur 3 nodes queue mein push hoti hain. Is level ki width 2 hai.
   - Next level mein 4, 5, 6 aur 7 nodes queue mein push hoti hain. Is level ki width 4 hai.
   - Next level mein 8 node queue mein push hoti hai. Is level ki width 1 hai.
   - Max width ab tak ki highest width (4) hoti hai.

3. Final result:
   - Tree ki maximum width 4 hai.
   - Output: 4
*/

