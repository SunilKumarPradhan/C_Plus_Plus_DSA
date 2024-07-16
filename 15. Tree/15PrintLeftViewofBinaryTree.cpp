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

// THIS IS THE RECURSIVE APPROACH--------

// int maxLevel=0;
// void leftView(node *root,int level){
//     if(root==NULL) return;
//     if(maxLevel <level){
//         cout<<root->key <<" ";
//         maxLevel=level;
//     }
//     leftView(root->left , level+1);
//     leftView(root->right , level+1);
// }

// void printLeftView(node *root ){
//     leftView(root,1);
// }

// THIS IS THE ITERATIVE APPROACH -----
void printLeftView(node *root) {
    if (root == NULL) return;
    queue<node *> q;
    q.push(root);

    while (!q.empty()) {
        int count = q.size();

        for (int i = 0; i < count; i++) {
            node *curr = q.front();
            q.pop();
            
            if (i == 0) cout << curr->key << " ";
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
        }
    }
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);
    cout << "The LeftView of the tree is : " << endl;
    printLeftView(root);
    return 0;
}
