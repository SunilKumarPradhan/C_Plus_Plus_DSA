#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;

    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->key == n1 || root->key == n2) return root;

    Node* leftLCA = findLCA(root->left, n1, n2);
    Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) return root;
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);

    Node* lca = findLCA(root, 5, 4);
    if (lca != NULL) {
        cout << "LCA of 5 and 4 is " << lca->key << endl;
    } else {
        cout << "Keys are not present in the tree" << endl;
    }

    cout<<()<<endl;
    return 0;
}



/*
Iss function ka naam hai findPath aur yeh function diya hua node tak ka path nikalta hai.
- Yeh vector p ko update karta hai jo root se given node tak ka path store karta hai.
- Function recursive hai:
  1. Agar root NULL hai, toh false return karo.
  2. Current node ko path mein add karo.
  3. Agar current node ka key, given key ke barabar hai, toh true return karo.
  4. Left aur right subtree ko recursively check karo.
  5. Agar node nahi mila, toh path se current node ko remove kar do (pop_back).

Process:
- Har node pe recursive call hota hai aur path update hota hai.

Example:
- Agar tree hai:
       3
      / \
     2   4
    /     \
   1       5
- Given nodes n1 = 1, n2 = 5
- Paths nikalenge:
  - Path1: 3 -> 2 -> 1
  - Path2: 3 -> 4 -> 5

Dry Run:
1. findPath function call hota hai root = 3:
   - root = 3, add 3 to path
   - call findPath(root->left, path, 1):
     - root = 2, add 2 to path
     - call findPath(root->left, path, 1):
       - root = 1, add 1 to path
       - return true (path1 = {3, 2, 1})
   - call findPath(root->right, path, 5):
     - root = 4, add 4 to path
     - call findPath(root->right, path, 5):
       - root = 5, add 5 to path
       - return true (path2 = {3, 4, 5})

2. LCA find karne ke liye, common path elements compare karte hain.
   - path1 = {3, 2, 1}
   - path2 = {3, 4, 5}
   - Common node 3 tak traverse karo. 3 is the LCA.

Output:
LCA of 1 and 5 is 3
*/

node* findLCA(node* root , int n1 , int n2){
    if(root==NULL) return ;
    if(root->key==n1 || root->key==n2 ) return root;

    node* leftLCA= findLCA(root->left, n1,n2);
    node* rightLCA= findLCA(root->right,n1,n2);

    if(leftLCA == NULL && rightLCA == NULL) return root;
    return (leftLCA != NULL) ?  leftLCA : rightLCA;
}