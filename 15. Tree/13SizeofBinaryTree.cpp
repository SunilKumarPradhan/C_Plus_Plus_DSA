#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int size(node *root){
    if(root==NULL) return 0;
    else return 1+size(root->left)+size(root->right);
}

int main() {
    node *root = makeTree();
    cout <<"The Size of the tree is : "<<size(root)<<endl;
    
    return 0;
}
