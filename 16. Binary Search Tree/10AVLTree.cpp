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



int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    cout << "  ";
    (root); 
    cout << endl;

    return 0;
}


/*
AVL Trees
AVL trees are a type of self-balancing binary search tree (BST) named after their inventors, Adelson-Velsky and Landis. They maintain a balanced height to ensure efficient search, insertion, and deletion operations.

Key Concepts
Balance Factor:

Defined as the height difference between the left and right subtrees of a node.
For an AVL tree, the balance factor of every node must be in the range [-1, 0, 1].
Height-Balanced:

The tree is height-balanced, ensuring that the height of the tree is always O(log n), where 
𝑛
n is the number of nodes.
This guarantees that search, insertion, and deletion operations remain efficient.
AVL Tree Properties
Binary Search Tree Properties:

Each node has at most two children.
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Balance Factor:

Calculated as the height of the left subtree minus the height of the right subtree.
For every node in the AVL tree, the balance factor must be -1, 0, or 1.
Rotations
To maintain balance after insertion and deletion, AVL trees use rotations. Rotations are local operations that change the structure of the tree while preserving the in-order sequence of the elements.

Single Rotations:

Left Rotation (LL Rotation): Used when the left subtree of the left child is causing the imbalance.
Right Rotation (RR Rotation): Used when the right subtree of the right child is causing the imbalance.
Double Rotations:

Left-Right Rotation (LR Rotation): Used when the right subtree of the left child is causing the imbalance.
Right-Left Rotation (RL Rotation): Used when the left subtree of the right child is causing the imbalance.
Operations
Insertion:

Insert the new node as in a regular BST.
After insertion, update the heights of the ancestors of the inserted node.
Check the balance factor of the ancestors and perform rotations to restore balance if necessary.
Example:

Insert node with key 30: Regular BST insertion.
Check balance factor and perform necessary rotations.
Deletion:

Remove the node as in a regular BST.
After deletion, update the heights of the ancestors of the deleted node.
Check the balance factor of the ancestors and perform rotations to restore balance if necessary.
Example:

Delete node with key 30: Regular BST deletion.
Check balance factor and perform necessary rotations.
Advantages
Efficient Operations: The height of the tree is always O(log n), ensuring that search, insertion, and deletion operations are efficient.
Balanced Structure: Maintains a balanced structure, preventing the worst-case performance of a regular BST.
Predictable Performance: Guarantees logarithmic time complexity for all operations, providing predictable performance.
Disadvantages
Complex Rotations: Insertion and deletion operations can be more complex due to the need for rotations.
Additional Space: Requires additional space to store the height information for each node.
Applications
Databases: Used in databases where balanced search trees are required for efficient query processing.
File Systems: Utilized in file systems to maintain balanced directory structures.
Networking: Employed in networking algorithms where balanced trees are needed for efficient routing and searching.
Conclusion
AVL trees are a robust and efficient data structure for maintaining a balanced binary search tree. By ensuring that the height of the tree remains logarithmic, AVL trees provide reliable and predictable performance for dynamic set operations, making them suitable for a variety of applications in computer science and software engineering.







*/