#include <bits/stdc++.h>
using namespace std;

void printNto1(int n) {
    if (n < 1) return; // Base case
    cout << n << " ";
    printNto1(n - 1); // Recursive call
}

int main() {
    int N = 5;
    cout << "Numbers from " << N << " to 1:" << endl;
    printNto1(N);
    cout << endl;
    return 0;
}
