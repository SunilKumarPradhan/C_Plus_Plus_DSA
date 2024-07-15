// tree.h
#ifndef TREE_H
#define TREE_H

struct node {
    int key;
    node *left;
    node *right;

    node(int k) {
        key = k;
        left = right = NULL;
    }
};

node* createSampleTree();

#endif // TREE_H
