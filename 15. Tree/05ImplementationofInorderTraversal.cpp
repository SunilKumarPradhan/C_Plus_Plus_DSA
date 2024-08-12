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

// Inorder traversal ka function jo tree ko inorder mein traverse karta hai

int add(int a ,int b){
    int res = a+b;
    return res;
}

void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->key<< " ";
        inorder(root->right);
    }
}

int main() {
    node *root = new node(3);

    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    //cout << "Inorder traversal: " << inorder(root)<<endl; // In C++, you cannot insert a void function call directly into a cout stream insertion operation.
    cout << "InOrder Traversal : "<<endl;

    inorder(root); // ye fucntion khud hi print kar deta hai , hence alag se print karne ki koi zarurat nahi
    cout<<"The sum ="+ to_string(add(2,3))<<endl;
    return 0; 
}


/*
Iss program mein hum ek binary tree banate hain aur uska inorder traversal karte hain.

- Function ka naam: `inorder`
  Description: Ye function binary tree ko inorder traversal karta hai.

- Function ka logic:
  1. `inorder` function root node se start hota hai aur recursively left subtree, root, aur right subtree ko traverse karta hai.
  2. Agar current node null nahi hai, toh pehle left child ko visit karo, uske baad current node ki key print karo, fir right child ko visit karo.

Process:
- Pehle, ek tree ka structure create karte hain jismein root node aur uske left aur right children hain.
- Uske baad, `inorder` function ko call karke tree ko traverse karte hain aur node keys ko print karte hain.

Example:
- Agar tree aisa hai:

       3
      / \
     2   4
    /     \
   1       5

Toh Inorder traversal aise hota hai: 1, 2, 3, 4, 5

Three Iterations:
1. **Iteration 1**: Root = 3
   - Traverse left subtree (Root = 2)
   - Traverse left subtree (Root = 1)
   - Print 1 (Leftmost node)
   - Traverse back to parent (Root = 2)
   - Print 2

2. **Iteration 2**: Continue from Root = 3
   - Print 3 (Root)
   - Traverse right subtree (Root = 4)
   - Traverse right subtree (Root = 5)
   - Print 5 (Rightmost node)

3. **Iteration 3**: Backtrack to Root = 4
   - Print 4
   - Traversal complete

Dry Run:
1. Initial setup:
   - Create nodes and set up tree structure as shown above.
   - Initialize `root` with the main node.

2. Step-by-step execution:
   - `inorder(root)` called with root = 3.
   - Traverse left: `inorder(root->left)` with root = 2.
   - Traverse left: `inorder(root->left->left)` with root = 1.
     - Print 1
   - Back to root = 2
     - Print 2
   - Back to root = 3
     - Print 3
   - Traverse right: `inorder(root->right)` with root = 4.
   - Traverse right: `inorder(root->right->right)` with root = 5.
     - Print 5
   - Back to root = 4
     - Print 4

3. Final output: 1 2 3 4 5

Output:
InOrder Traversal:
1 2 3 4 5
The sum = 5
*/
