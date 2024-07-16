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

int maxWidth(node *root){
    if(root==NULL) return 0;
    queue<node*>q;
    q.push(root);

    int res=0;
    while(!q.empty()){
        int count=q.size();
        res=max(res,count);

        for(int i=0; i<count;i++){
            node *curr=q.front();
            q.pop();
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right); 
        }
    }
    return res;
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);

    cout<<"\n";
    cout << "The maxWidth of the tree is : "<<maxWidth(root);  
    return 0;
}
