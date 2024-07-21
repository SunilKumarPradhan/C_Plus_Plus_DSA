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
Red-Black Trees
Red-Black Trees are a type of self-balancing binary search tree. They ensure that the tree remains balanced, providing efficient search, insertion, and deletion operations. Red-Black Trees maintain balance through a set of properties that involve node coloring and rotations.

Key Concepts
Binary Search Tree (BST) Properties:

Each node has at most two children.
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Red-Black Properties:

Node Coloring: Each node is either red or black.
Root Property: The root is always black.
Red Property: Red nodes cannot have red children (no two red nodes can be adjacent).
Black Property: Every path from a node to its descendant leaves has the same number of black nodes.
Leaf Property: Every leaf (NIL node) is black.
Rotations
To maintain balance after insertion and deletion, Red-Black Trees use rotations. Rotations are local operations that change the structure of the tree while preserving the in-order sequence of the elements.

Single Rotations:
Left Rotation: Rotates a node with its right child.
Right Rotation: Rotates a node with its left child.
Operations
Insertion:

Insert the new node as in a regular BST, color it red.
Fix any violations of the Red-Black properties by using rotations and recoloring.
Cases:
Case 1: New node is the root (recolor it black).
Case 2: Parent is black (tree remains valid).
Case 3: Parent and uncle are red (recolor parent and uncle to black, grandparent to red, and fix further up).
Case 4: Parent is red, uncle is black, new node is right child (left rotation on parent, treat as Case 5).
Case 5: Parent is red, uncle is black, new node is left child (right rotation on grandparent, swap colors of parent and grandparent).
Example:

Insert node with key 30: Regular BST insertion.
Recolor and perform necessary rotations.
Deletion:

Remove the node as in a regular BST.
Fix any violations of the Red-Black properties by using rotations and recoloring.
Cases:
Case 1: Node to be deleted is red (simply remove it).
Case 2: Node to be deleted is black (requires fixing double black issues).
Fixing Double Black:
Case 1: Sibling is red (recolor sibling and parent, perform rotation).
Case 2: Sibling is black, and both children of sibling are black (recolor sibling, move double black up).
Case 3: Sibling is black, sibling's left child is red, right child is black (recolor sibling and its left child, perform rotation).
Case 4: Sibling is black, sibling's right child is red (recolor sibling and its right child, perform rotation).
Example:

Delete node with key 30: Regular BST deletion.
Recolor and perform necessary rotations.
Properties and Balance
Height: The height of a Red-Black Tree is O(log n), where 
𝑛
n is the number of nodes.
Balanced Structure: Ensures balanced height through the properties and rotations, maintaining efficient operations.
Advantages
Efficient Operations: Maintains O(log n) height, ensuring that search, insertion, and deletion operations are efficient.
Predictable Performance: Guarantees logarithmic time complexity for all operations, providing predictable performance.
Disadvantages
Complex Implementation: Insertion and deletion operations are more complex due to the need for rotations and recoloring.
Extra Storage: Requires additional space for storing the color information of each node.
Applications
Databases: Used in databases for maintaining balanced search trees, ensuring efficient query processing.
Compilers: Utilized in compilers for syntax tree management.
Networking: Employed in networking algorithms where balanced trees are needed for efficient routing and searching.
Conclusion
Red-Black Trees are an efficient data structure for maintaining a balanced binary search tree. By ensuring that the height of the tree remains logarithmic, Red-Black Trees provide reliable and predictable performance for dynamic set operations. This makes them suitable for a variety of applications in computer science and software engineering.

*/