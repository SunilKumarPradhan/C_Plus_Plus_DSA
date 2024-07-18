import os

cpp_template = """#include <bits/stdc++.h>
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
"""

# Read the filenames from the text file
with open('QuestionList.txt', 'r') as file:
    filenames = file.readlines()

# Create .cpp files with the template
for name in filenames:
    filename = name.strip() + '.cpp'  # Remove any leading/trailing whitespace and add .cpp extension
    with open(filename, 'w') as cpp_file:
        cpp_file.write(cpp_template)
    
    print(f"Created file: {filename}")
