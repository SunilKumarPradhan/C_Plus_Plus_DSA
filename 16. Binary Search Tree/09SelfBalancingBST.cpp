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
- Different types of insertion can cause different heights
- to make all the operations under log n , we need to keep in check that height doesnt exceed beyond log n 
- to achieve that we need to know all the keys in advance 
- 
Self-Balancing Binary Search Trees
Self-balancing binary search trees (BSTs) are a category of binary search trees that automatically maintain their height to ensure efficient operations. Unlike regular BSTs, where the height can degrade to O(n) in the worst case, self-balancing BSTs keep their height logarithmic in the number of nodes, i.e., O(log n). This ensures that operations like search, insertion, and deletion remain efficient.

Key Concepts
Binary Search Tree (BST) Basics:

Structure: A tree where each node has at most two children (left and right).
Property: For any node with value 𝑣, all values in the left subtree are less than 𝑣 and all values in the right subtree are greater than 𝑣

Operations:
Search: O(h), where 
h is the height of the tree.
Insertion: O(h).
Deletion: O(h).
Height-Balanced Trees:

Balanced Tree: A tree is considered balanced if the height difference between the left and right subtrees of any node is at most a constant factor.
Unbalanced Tree: Can lead to worst-case time complexity for operations if it degenerates into a linked list.
Self-Balancing BSTs:

Goal: Maintain a balanced tree structure to ensure O(log n) height.
Types:
AVL Trees: Named after inventors Adelson-Velsky and Landis, AVL trees maintain the height balance factor (difference in heights of left and right subtrees) of each node within [-1, 0, 1].
Red-Black Trees: A type of self-balancing BST where each node has a color (red or black) and the tree maintains balance through specific properties and rotations.
Splay Trees: Use splaying, a process of moving an accessed node to the root through rotations, to maintain balance.
B-Trees: Generalization of binary search trees that can have more than two children and are used in databases and file systems.
AVL Trees
Properties:

Balance Factor: For any node, the height difference between its left and right subtrees is at most 1.
Rotations: Used to maintain balance after insertion and deletion. Types include:
Single Rotation (LL or RR).
Double Rotation (LR or RL).
Operations:

Insertion: Insert node as in a regular BST and then perform rotations to restore balance.
Deletion: Delete node as in a regular BST and then perform rotations to restore balance.
Red-Black Trees
Properties:

Node Coloring: Each node is either red or black.
Root Property: The root is always black.
Red Property: Red nodes cannot have red children (no two red nodes can be adjacent).
Black Property: Every path from a node to its descendant leaves has the same number of black nodes.
Leaf Property: Every leaf (NIL node) is black.
Operations:

Insertion: Insert node as in a regular BST, color it red, and then fix any violations of red-black properties through rotations and recoloring.
Deletion: Remove node as in a regular BST and then fix any violations of red-black properties through rotations and recoloring.
Splay Trees
Properties:

Splaying: Move the accessed node to the root using a series of rotations (zig, zig-zig, zig-zag).
Amortized Time: Even though individual operations may take O(n) time, the amortized time complexity over a sequence of operations is O(log n).
Operations:

Search, Insertion, Deletion: Similar to regular BSTs but followed by splaying to move the accessed node to the root.
B-Trees
Properties:

M-ary Tree: Nodes can have more than two children (multi-way tree).
Balance: All leaf nodes are at the same depth, and internal nodes have a number of keys within a specified range.
Operations:

Insertion, Deletion, Search: Operations involve splitting and merging nodes to maintain balance and ensure all paths from the root to the leaves have the same length.
Conclusion
Self-balancing BSTs are crucial for applications where efficient and consistent performance of dynamic set operations is required, such as in databases, file systems, and networking. By maintaining a balanced structure, these trees ensure that the worst-case time complexity for fundamental operations remains logarithmic, thereby providing reliable and predictable performance.







*/
