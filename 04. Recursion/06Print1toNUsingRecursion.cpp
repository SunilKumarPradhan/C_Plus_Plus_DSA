#include <bits/stdc++.h>
using namespace std;

void print1toN(int n) {
    if (n < 1) return; // Base case
    print1toN(n - 1);  // Recursive call
    cout << n << " ";
}

int main() {
    int N = 5;
    cout << "Numbers from 1 to " << N << ":" << endl;
    print1toN(N);
    cout << endl;
    return 0;
}
