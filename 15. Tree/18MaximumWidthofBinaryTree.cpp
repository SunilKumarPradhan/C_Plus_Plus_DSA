#include <bits/stdc++.h>
using namespace std;

// Define the structure for each node in the binary tree
struct node {
    int key;
    node *left;
    node *right;

    // Constructor to initialize a node with a key value
    node(int k) {
        key = k;
        left = right = NULL;
    }
};

// Function to calculate the maximum width of a binary tree
int maxWidth(node *root) {
    // If the root is NULL, the width is 0
    if (root == NULL) return 0;
    
    // Queue to perform level order traversal
    queue<node*> q;
    q.push(root);

    // Variable to store the maximum width encountered
    int maxWidth = 0;
    
    // Perform level order traversal using the queue
    while (!q.empty()) {
        // Get the current size of the queue (number of nodes at this level)
        int count = q.size();
        
        // Update maxWidth with the maximum of itself and the current size
        maxWidth = max(maxWidth, count);

        // Process each node in the current level
        for (int i = 0; i < count; i++) {
            // Dequeue the front node
            node *curr = q.front();
            q.pop();

            // Enqueue the left child if it exists
            if (curr->left != NULL) q.push(curr->left);

            // Enqueue the right child if it exists
            if (curr->right != NULL) q.push(curr->right);
        }
    }

    // Return the maximum width of the binary tree
    return maxWidth;
}

int main() {
    // Creating the binary tree
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    // Printing the maximum width of the tree
    cout << "The maxWidth of the tree is : " << maxWidth(root) << endl;
  
    return 0; // Program execution starts here
}

/*

Explanation (Hinglish):

Iss program mein hum ek binary tree ka maximum width calculate kar rahe hain. Maximum width ka matlab hai ki sabse zyada nodes kaun se level par hain.

Binary tree ke har node ko represent karne ke liye ek structure node define kiya gaya hai. Har node mein ek key value hoti hai, aur left aur right pointers hote hain.

1. Structure node:
   - int key: Node ki value.
   - node *left: Left child ka pointer.
   - node *right: Right child ka pointer.
   
2. maxWidth function:
   - maxWidth function binary tree ka maximum width nikalne ke liye use hota hai.
   - Agar root NULL hai, to width 0 return hota hai.
   - Queue use hoti hai level order traversal ke liye, jisme root node initially push ki jati hai.
   - maxWidth naam ka variable initialize kiya jata hai 0 se, jo maximum width ko store karega.
   - Jab tak queue khali nahi hoti:
     - Har iteration mein queue ka size count kiya jata hai (current level ke nodes ka count).
     - maxWidth ko update kiya jata hai current level ke nodes ka count se.
     - Har node ke liye current level mein:
       - Queue se front node remove kiya jata hai (dequeue).
       - Agar node ka left child exist karta hai, to use queue mein push kiya jata hai.
       - Agar node ka right child exist karta hai, to use queue mein push kiya jata hai.
   - Jab queue empty ho jati hai, tab maxWidth mein maximum width stored hota hai.
   - Finally, maxWidth return kiya jata hai.

3. Main function:
   - Ek binary tree create kiya gaya hai jisme predefined values se nodes initialize kiye gaye hain.
   - maxWidth function call kiya gaya hai root node ke saath, aur result ko print kiya gaya hai.

Output:
The maxWidth of the tree is : 2

Dry Run:
1. Humare tree ka structure:
       3
      / \
     2   4
    /     \
   1       5

2. maxWidth function ka execution:
   - root = 3, queue mein push kiya jata hai.

3. While loop shuru hota hai (jab tak queue khali na ho):
   - count = 1, maxWidth = max(0, 1) = 1
     - curr = 3, queue se pop kiya jata hai.
     - Left child (2) queue mein push kiya jata hai.
     - Right child (4) queue mein push kiya jata hai.

   - count = 2, maxWidth = max(1, 2) = 2
     - curr = 2, queue se pop kiya jata hai.
     - Left child (1) queue mein push kiya jata hai.

   - count = 1, maxWidth = max(2, 1) = 2
     - curr = 4, queue se pop kiya jata hai.
     - Right child (5) queue mein push kiya jata hai.

   - count = 1, maxWidth = max(2, 1) = 2
     - curr = 1, queue se pop kiya jata hai.

   - count = 1, maxWidth = max(2, 1) = 2
     - curr = 5, queue se pop kiya jata hai.

4. While loop khatam ho jata hai aur output "The maxWidth of the tree is :" ke saath 2 print hota hai.

Output:
The maxWidth of the tree is : 2

*/
