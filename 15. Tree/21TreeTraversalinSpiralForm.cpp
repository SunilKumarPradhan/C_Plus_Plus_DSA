#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    node *left, *right;

    node(int k) {
        key = k;
        left = right = NULL;
    }
};

// THIS IS THE EFFICIENT APPROACH

// void printSpiral(node *root) {
//     if (root == NULL) return;

//     stack<node*> s1; 
//     stack<node*> s2; 

//     s1.push(root);

//     while (!s1.empty() || !s2.empty()) {
//         while (!s1.empty()) {
//             node *temp = s1.top();
//             s1.pop();
//             cout << temp->key << " ";

//             // Push left before right
//             if (temp->left) s2.push(temp->left);
//             if (temp->right) s2.push(temp->right);
//         }

//         while (!s2.empty()) {
//             node *temp = s2.top();
//             s2.pop();
//             cout << temp->key << " ";

//             // Push right before left
//             if (temp->right) s1.push(temp->right);
//             if (temp->left) s1.push(temp->left);
//         }
//     }
// }

// THE NAIVE APPROACH 

void printSpiral(node* root) {
    if (root == NULL) return;

    queue<node*> q;
    stack<int> s;
    bool reverse = false;

    q.push(root);

    while (!q.empty()) {
        int count = q.size();
        for (int i = 0; i < count; i++) {  // Initialize i to 0
            node* curr = q.front();  // Use q.front() to get the front element
            q.pop();  // Correctly use q.pop()

            if (reverse) s.push(curr->key);
            else cout << curr->key << " ";

            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
        }

       if (reverse) {
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        }
        reverse = !reverse;  
        cout << endl;  
    }
}



int main() {
    
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(7);
    root->left->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(4);
    
    // this is another form of making a tree..
    //node* root = new node{ 1, new node{2, new node{4, NULL, NULL}, new node{5, NULL, NULL}}, new node{3, new node{6, NULL, NULL}, new node{7, NULL, NULL}}};


    cout << "Spiral Order Traversal of binary tree is: ";
    printSpiral(root);

    return 0;
}
