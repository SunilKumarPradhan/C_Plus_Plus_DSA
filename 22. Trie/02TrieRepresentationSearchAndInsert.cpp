#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode *child[26]; // ye ek array hai jiska datatype node hai
    bool isEnd;

    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }

}



int main() {
    // Your code here
    return 0;
}
