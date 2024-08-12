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

// THIS IS THE EFFICIENT APPROACH

void printSpiral(node *root) {
    if (root == NULL) return;

    stack<node*> s1; 
    stack<node*> s2; 

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            node *temp = s1.top();
            s1.pop();
            cout << temp->key << " ";

            // Push left before right
            if (temp->left) s2.push(temp->left);
            if (temp->right) s2.push(temp->right);
        }


        while (!s2.empty()) {
            node *temp = s2.top();
            s2.pop();
            cout << temp->key << " ";

            // Push right before left
            if (temp->right) s1.push(temp->right);
            if (temp->left) s1.push(temp->left);
        }
    }
}



// THE NAIVE APPROACH 

// void printSpiral(node* root) {
//     if (root == NULL) return;

//     queue<node*> q;
//     stack<int> s;
//     bool reverse = false;

//     q.push(root);

//     while (!q.empty()) {
//         int count = q.size();
        
//         for (int i = 0; i < count; i++) {  
//             node* curr = q.front(); 
//             q.pop(); 
//             if (reverse) s.push(curr->key);
//             else cout << curr->key << " ";

//             if (curr->left != NULL) q.push(curr->left);
//             if (curr->right != NULL) q.push(curr->right);
//         }

//        if (reverse) {
//             while (!s.empty()) {
//                 cout << s.top() << " ";
//                 s.pop();
//             }
//         }
//         reverse = !reverse;  
//         cout << endl;  
//     }
// }



int main() {
    
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(7);
    root->left->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(4);
    
    // this is another form of making a tree..
    //node* root = new node{ 1, new node{2, new node{4, NULL, NULL}, new node{5, NULL, NULL}}, new node{3, new node{6, NULL, NULL}, new node{7, NULL, NULL}}};


    cout << "Spiral Order Traversal of binary tree is: ";
    printSpiral(root);

    return 0;
}


/*
Iss function ka naam hai printSpiral aur yeh binary tree ko spiral order (zigzag level order) mein print karta hai.

Naive approach:
- Pehle, ek queue aur ek stack use karte hain.
- Ek boolean variable reverse ko initialize karte hain jo direction ko track karega.
- Root node ko queue mein push karte hain.
- Queue mein har level ke liye:
  1. Current level ke nodes ko process karte hain.
  2. Agar reverse true hai, toh nodes ko stack mein push karte hain.
  3. Warna directly print karte hain.
  4. Next level ke nodes ko queue mein push karte hain.
  5. Agar reverse true hai, toh stack ke contents ko print karte hain aur stack ko clear karte hain.
  6. Reverse ko toggle karte hain (true se false ya false se true).

Example:
- Agar tree hai:
       1
      / \
     2   3
    / \ / \
   7  6 5  4

- Spiral order traversal: 1 3 2 7 6 5 4

Dry Run:
1. Tree ka structure:
       1
      / \
     2   3
    / \ / \
   7  6 5  4

2. printSpiral function call hota hai:
   - root = 1

3. Queue: [1]
   - Level 1: 1
   - Print 1
   - Next level: [2, 3]
   - Toggle reverse to true

4. Queue: [2, 3]
   - Level 2: 2 3
   - Push 2, 3 to stack
   - Next level: [7, 6, 5, 4]
   - Print stack: 3 2
   - Toggle reverse to false

5. Queue: [7, 6, 5, 4]
   - Level 3: 7 6 5 4
   - Print 7 6 5 4
   - No more nodes to process

Output:
Spiral Order Traversal of binary tree is: 1 3 2 7 6 5 4
*/