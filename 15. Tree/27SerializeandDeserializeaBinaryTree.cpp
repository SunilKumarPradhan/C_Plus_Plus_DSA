#include<bits/stdc++.h>
using namespace std;

struct node {
  int val;
  node* left;
  node* right;
  node(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(node* root) {
  if (root == NULL) {
    return "X"; 
  }

  string data = to_string(root->val);
  data += "," + serialize(root->left);
  data += "," + serialize(root->right);
  return data;
}


node* deserialize(string& data) {
  if (data.empty() || data[0] == 'X') {
    if (data.empty()) {
      cerr << "Error: Empty data string" << endl;
    }
    data.erase(0, 1);
    return NULL;
  }

  int value;
  stringstream ss(data);
  getline(ss, data, ',');
  ss >> value;

  node* root = new node(value);
  root->left = deserialize(data);
  root->right = deserialize(data);

  return root;
}

int main() {
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->right->right = new node(5);

  string serializedData = serialize(root);
  cout << "Serialized data: " << serializedData << endl;

  node* deserializedRoot = deserialize(serializedData);
 
  return 0;
}


/*
Iss code ka maqsad hai binary tree ko serialize (string format mein convert) aur deserialize (string se tree banane) karna.

1. `serialize` function:
   - Binary tree ko string format mein convert karta hai.
   - Agar node NULL hai, toh "X" return karta hai (marker for NULL).
   - Non-NULL nodes ko value se represent karta hai aur recursively left aur right subtrees ko serialize karta hai.
   - Output string format: "nodeValue,leftSubtree,rightSubtree".

2. `deserialize` function:
   - String ko wapas tree mein convert karta hai.
   - Agar string empty hai ya 'X' hai, toh NULL return karta hai.
   - Agar non-NULL node hai, toh value ko extract karta hai aur recursively left aur right subtrees ko deserialize karta hai.

**Process:**

1. **Serialization:**
   - Input Tree:
     ```
       1
      / \
     2   3
    /     \
   4       5
     ```
   - Serialized string: "1,2,4,X,X,X,3,X,5,X,X"

2. **Deserialization:**
   - Input Serialized string: "1,2,4,X,X,X,3,X,5,X,X"
   - Convert string back to tree structure using recursion.

**Dry Run:**
1. Serialize function:
   - Root = 1
   - Left subtree serialized to "2,4,X,X,X"
   - Right subtree serialized to "3,X,5,X,X"
   - Combined serialized string: "1,2,4,X,X,X,3,X,5,X,X"

2. Deserialize function:
   - Deserialize "1,2,4,X,X,X,3,X,5,X,X":
     - Root node value = 1
     - Left child node = 2, its left child = 4, its children = NULL
     - Right child node = 3, its right child = 5, its children = NULL

**Output:**
Serialized data: 1,2,4,X,X,X,3,X,5,X,X
*/