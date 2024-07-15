#include <bits/stdc++.h> 
using namespace std;

// Node naam ka ek structure banaya gaya hai
struct node {
    int key;            // Node ka ek key value
    node *left;         // Left child pointer
    node *right;        // Right child pointer

    // Node ka constructor, jo ek nayi node create karta hai
    node(int k) {
        key = k;
        left = right = NULL;  // Shuru mein left aur right pointers NULL set kiye gaye hain
    }
};

int main() {
    node *root = new node(10);           // Root node banai gayi jiska key 10 hai
    root->left = new node(20);           // Root node ka left child banaya gaya jiska key 20 hai
    root->right = new node(30);          // Root node ka right child banaya gaya jiska key 30 hai
    root->left->left = new node(45);     // Root ke left child ka left child banaya gaya jiska key 45 hai
    return 0; 
}
