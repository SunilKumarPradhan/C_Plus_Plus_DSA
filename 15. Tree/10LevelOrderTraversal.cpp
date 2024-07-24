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

void printLevelOrder(node *root) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    if (root == NULL) return;

    queue<node *> q;
    q.push(root);

    while (!q.empty()) {
        node *curr = q.front();
        q.pop();

        cout << curr->key << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main() {
    node *root = new node(3);

    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    cout << "PostOrder Traversal : "<<endl;

    printLevelOrder(root);

    return 0; 
}

/*
`printLevelOrder` function:
- Yeh function binary tree ke nodes ko level order mein traverse karta hai aur print karta hai.
- `ios::sync_with_stdio(false);`: Isse cin aur cout ko synchronize nahi kiya jaata, jo ki input/output speed ko increase karta hai.
- `cin.tie(0);cout.tie(0);`: Isse cin aur cout ko tie nahi kiya jaata, jo ki performance ko improve karta hai.
- `if (root == NULL) return;`: Agar root node NULL hai to function return kar jata hai, kyunki tree khali hai.
- `queue<node *> q;`: Ek queue banai jaati hai jo node pointers ko store karti hai.
- `q.push(root);`: Root node ko queue mein daal diya jaata hai.
- `while (!q.empty())`: Loop tab tak chalta hai jab tak queue empty nahi hoti.
  - `node *curr = q.front();`: Queue ke front se current node ko access kiya jaata hai.
  - `q.pop();`: Current node ko queue se hata diya jaata hai.
  - `cout << curr->key << " ";`: Current node ki key print ki jaati hai.
  - `if (curr->left) q.push(curr->left);`: Agar current node ka left child hai to usse queue mein daala jaata hai.
  - `if (curr->right) q.push(curr->right);`: Agar current node ka right child hai to usse queue mein daala jaata hai.

Dry Run:
1. **Initial State:**
   - `root = 3`
   - Queue (`q`): Empty

2. **Step 1:**
   - `q.push(root);`
   - Queue (`q`): [3]

3. **Step 2:**
   - `curr = q.front()`: 3
   - `q.pop()`
   - Print `3`
   - Enqueue left child (`2`) and right child (`4`):
     - Queue (`q`): [2, 4]

4. **Step 3:**
   - `curr = q.front()`: 2
   - `q.pop()`
   - Print `2`
   - Enqueue left child (`1`):
     - Queue (`q`): [4, 1]

5. **Step 4:**
   - `curr = q.front()`: 4
   - `q.pop()`
   - Print `4`
   - Enqueue right child (`5`):
     - Queue (`q`): [1, 5]

6. **Step 5:**
   - `curr = q.front()`: 1
   - `q.pop()`
   - Print `1`
   - No children to enqueue:
     - Queue (`q`): [5]

7. **Step 6:**
   - `curr = q.front()`: 5
   - `q.pop()`
   - Print `5`
   - No children to enqueue:
     - Queue (`q`): Empty

8. **End of Loop:**
   - Queue is empty, exit loop.

**Final Output:** : 3 2 4 1 5

*/
