#include <bits/stdc++.h>
using namespace std;

bool isKthBitSet(int n, int k) {
    return (n & (1 << (k - 1))) != 0;
}

int main() {
    int n = 5; // example number
    int k = 3; // position to check

    if (isKthBitSet(n, k)) {
        cout << "The " << k << "-th bit is set." << endl;
    } else {
        cout << "The " << k << "-th bit is not set." << endl;
    }
    
    return 0;
}
