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

int findKthSmallest(node* root, int k) {
    stack<node*> s;
    auto curr = root;

    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top(); s.pop();
        if (--k == 0) return curr->key;

        curr = curr->right;
    }
    throw runtime_error("k is out of bounds");
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
    int k = 4;
    try {
        cout << "The " << k << "th smallest element is " << findKthSmallest(root, k) << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}


/*
Iss function ka naam hai findKthSmallest aur yeh BST (Binary Search Tree) mein se k-th smallest element find karta hai.

- Function ka logic:
  1. Hum in-order traversal ka use karte hain kyunki BST mein in-order traversal sorted order mein elements return karta hai.
  2. Ek stack ka use karte hain taaki traversal ko iterative way mein implement kar sakein.
  3. Leftmost node se shuru karte hain aur stack ke through nodes ko traverse karte hain.
  4. Har baar jab hum ek node ko visit karte hain, k ko decrement karte hain. Jab k 0 ho jata hai, us samay ka node hi k-th smallest element hota hai.

Process:
- Pehle, sabse leftmost node tak jaate hain (smallest element).
- Har baar ek node ko visit karte hain aur k ko decrement karte hain.
- Jab tak k 0 nahi hota, hum nodes ko visit karte rehte hain.

Example:
- Agar tree hai:
       50
      /  \
     30   70
    / \   / \
   20 40 60 80

- Agar k = 4 hai, toh pehle 4 nodes ko in-order mein visit karenge:
  1. 20
  2. 30
  3. 40
  4. 50 (4th smallest element)

Dry Run:
1. Tree ka structure:
       50
      /  \
     30   70
    / \   / \
   20 40 60 80

2. In-order traversal shuru hota hai:
   - Start at root = 50
   - Left subtree traverse karte hain:
     - Go to node 30
     - Go to node 20 (smallest element), k = 3
     - Backtrack to 30, k = 2
     - Go to node 40, k = 1
   - Backtrack to 50, k = 0 (4th smallest element)

Output:
- The 4th smallest element is 50.
*/
