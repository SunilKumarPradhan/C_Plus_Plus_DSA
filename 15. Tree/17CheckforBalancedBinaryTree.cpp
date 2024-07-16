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

int isBalanced(node *root){
    if(root==NULL) return 0;

    int lh= isBalanced(root->left);
    if(lh==-1) return -1;

    int rh=isBalanced(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh) > 1 ) return -1;
    else return max(lh,rh)+1;


}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    cout<<"\n";
    cout << "The isBalanced of the tree is : ";

    if (isBalanced(root)) cout<<"True";
    else cout<< "False";
  
    return 0;
}
