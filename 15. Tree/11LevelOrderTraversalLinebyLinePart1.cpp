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

// Function to print the level order traversal of the tree, line by line
void printLevelOrderLinebyLine(node *root) {
    if (root == NULL) return;

    queue<node *> q;
    q.push(root);
    q.push(NULL); // Marker for the end of the current level

    while (q.size() > 1) { // Continue until only the marker remains
        node *curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << "\n"; // Print a newline after each level
            q.push(NULL); // Add a new marker for the next level
            continue;
        }

        cout << curr->key << " "; // Print the current node's key

        if (curr->left != NULL)
            q.push(curr->left); // Add left child to the queue if exists
        if (curr->right != NULL)
            q.push(curr->right); // Add right child to the queue if exists
    }
    cout << endl; // Print a newline after the last level
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    cout << "Level Order Traversal Line by Line:" << endl;
    printLevelOrderLinebyLine(root);

    // Clean up the tree to avoid memory leaks
    delete root->right->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

/*
`printLevelOrderLinebyLine` function:
- Yeh function binary tree ko level by level, line by line print karta hai.
- `if (root == NULL) return;`: Agar root node NULL hai to function return kar jata hai, kyunki tree khali hai.
- `queue<node *> q;`: Ek queue banai jaati hai jo nodes ko store karti hai.
- `q.push(root); q.push(NULL);`: Root node ko queue mein daala jaata hai aur NULL marker daala jaata hai jo level ke end ko indicate karta hai.
- `while (q.size() > 1)`: Loop tab tak chalta hai jab tak queue mein marker ke alawa koi aur element hai.
  - `node *curr = q.front(); q.pop();`: Queue ke front se current node ko access kiya jaata hai aur queue se remove kiya jaata hai.
  - `if (curr == NULL)`: Agar current node NULL hai, matlab ek level complete ho gaya hai.
    - `cout << "\n";`: Newline print ki jaati hai.
    - `q.push(NULL);`: Agle level ke end ke liye marker daala jaata hai.
  - `cout << curr->key << " ";`: Current node ki key print ki jaati hai.
  - `if (curr->left != NULL) q.push(curr->left);`: Agar current node ka left child hai to usse queue mein daala jaata hai.
  - `if (curr->right != NULL) q.push(curr->right);`: Agar current node ka right child hai to usse queue mein daala jaata hai.
- `cout << endl;`: Last level ke baad ek newline print ki jaati hai.

Dry Run:
1. **Initial State:**
   - `root = 3`
   - Queue (`q`): [3, NULL]

2. **Step 1:**
   - `curr = q.front()`: 3
   - `q.pop()`
   - Print `3`
   - Enqueue left child (`2`) and right child (`4`):
     - Queue (`q`): [NULL, 2, 4]

3. **Step 2:**
   - `curr = q.front()`: NULL
   - `q.pop()`
   - Print `\n` (new line after first level)
   - Enqueue new NULL marker for next level:
     - Queue (`q`): [2, 4, NULL]

4. **Step 3:**
   - `curr = q.front()`: 2
   - `q.pop()`
   - Print `2`
   - Enqueue left child (`1`):
     - Queue (`q`): [4, NULL, 1]

5. **Step 4:**
   - `curr = q.front()`: 4
   - `q.pop()`
   - Print `4`
   - Enqueue right child (`5`):
     - Queue (`q`): [NULL, 1, 5]

6. **Step 5:**
   - `curr = q.front()`: NULL
   - `q.pop()`
   - Print `\n` (new line after second level)
   - Enqueue new NULL marker for next level:
     - Queue (`q`): [1, 5, NULL]

7. **Step 6:**
   - `curr = q.front()`: 1
   - `q.pop()`
   - Print `1`
   - No children to enqueue:
     - Queue (`q`): [5, NULL]

8. **Step 7:**
   - `curr = q.front()`: 5
   - `q.pop()`
   - Print `5`
   - No children to enqueue:
     - Queue (`q`): [NULL]

9. **Step 8:**
   - `curr = q.front()`: NULL
   - `q.pop()`
   - Print `\n` (new line after third level)
   - Queue is empty, exit loop.

**Final Output:**
3
2 4
1 5

*/