#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k) {
    if (n == 1) return 0; // Base case
    return (josephus(n - 1, k) + k) % n; // Recursive case
}

int main() {
    int N = 7, K = 3;
    cout << "The survivor's position is: " << josephus(N, K) + 1 << endl; // Adding 1 for 1-based index
    return 0;
}
