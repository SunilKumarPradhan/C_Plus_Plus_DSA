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