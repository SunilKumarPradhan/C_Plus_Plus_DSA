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

// This is naive approach takes about big oh : n^2

// int height(node *root){
//     if(root==NULL) return 0;
//     else return 1+max(height(root->left),height(root->right));
// }


//This is the efficient solution.
int res=0;
int height(node *root){
    if (root==NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    res=max(res,lh+rh+1);
    return 1+max(lh,rh);
}

int treeDiam(node *root){
    if(root==NULL) return 0;

    int d1= 1 + height(root->left) + height(root->right);
    int d2= treeDiam(root->left);
    int d3= treeDiam(root->right);

    return max(d1,max(d2,d3));
}


// the above function returns height but sets the "res" variable to diameter
// this means res= diameter.
// this function simply replaces the height function and solves it in big oh : n 

int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(7);
    root->left->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(4);
    cout<<"\n";
    cout <<"The diameter of binary tree is: "<<treeDiam(root);
    
    return 0;
}
