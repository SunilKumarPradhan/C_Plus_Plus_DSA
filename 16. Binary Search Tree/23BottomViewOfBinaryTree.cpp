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

void bottomView(node* root) {
    if (root == NULL) return;

    map<int, int> m;
    queue<pair<node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        node* n = p.first;
        int hd = p.second;
        q.pop();

        m[hd] = n->key;

        if (n->left) q.push({n->left, hd - 1});
        if (n->right) q.push({n->right, hd + 1});
    }

    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    bottomView(root);

    return 0;
}

/*
Iss function ka naam hai bottomView aur yeh ek binary tree ke nodes ko bottom view me display karta hai.

- Function ka logic:
  1. Agar root NULL hai, to function return kar jata hai.
  2. Ek map `m` aur queue `q` banate hai. Queue me node aur uski horizontal distance (hd) ko store karte hai.
  3. Queue me root node ko hd = 0 ke saath push karte hai.
  4. Jab tak queue khali nahi hoti, tab tak:
     - Queue se front element ko pop karte hai.
     - Map me current hd ke liye node ka key update karte hai.
     - Left aur right children ko queue me push karte hai, respective hd ke sath.
  5. Map ko iterate karte hai aur vertical level ke nodes ko print karte hai.

Process:
- Pehle, root node ko queue me push karte hai with hd = 0.
- Queue se nodes ko process karte hai aur unke horizontal distance ko update karte hai.
- Jo bhi node bottom view me pehli baar ya last encounter hoti hai, uska key map me update hota hai.
- Left aur right children ko respective hd ke sath queue me push karte hai.
- Map me stored values ko print karte hai, jo bottom view ke nodes hain.

Example:
- Agar tree hai:

      50
     /  \
    30   70
   / \   / \
  20 40 60 80

then

Tree structure:
       50
     /    \
    30     70
   / \    / \
  20 40  60 80

Dry Run:
1. Initial setup:
   - Root = 50, hd = 0, m = {}, queue = {(50, 0)}

2. Traversal:
   - Process node 50, hd = 0:
     - m[0] = 50
     - Push left child (30, -1) and right child (70, 1) to queue.
     - Queue = {(30, -1), (70, 1)}

   - Process node 30, hd = -1:
     - m[-1] = 30
     - Push left child (20, -2) and right child (40, 0) to queue.
     - Queue = {(70, 1), (20, -2), (40, 0)}

   - Process node 70, hd = 1:
     - m[1] = 70
     - Push left child (60, 0) and right child (80, 2) to queue.
     - Queue = {(20, -2), (40, 0), (60, 0), (80, 2)}

   - Process node 20, hd = -2:
     - m[-2] = 20
     - Queue = {(40, 0), (60, 0), (80, 2)}

   - Process node 40, hd = 0:
     - m[0] = 40 (Updated with new node key)
     - Queue = {(60, 0), (80, 2)}

   - Process node 60, hd = 0:
     - m[0] = 60 (Updated with new node key)
     - Queue = {(80, 2)}

   - Process node 80, hd = 2:
     - m[2] = 80
     - Queue = {}

3. Final output:
   - m = {-2: 20, -1: 30, 0: 60, 1: 70, 2: 80}

Output:
20 30 60 70 80
*/
