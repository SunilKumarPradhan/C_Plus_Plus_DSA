#include <bits/stdc++.h>
using namespace std;

// Tail recursion example
void printTail(int n, int current = 1) {
    if (current > n) return; // Base case
    cout << current << " ";
    printTail(n, current + 1); // Tail recursive call
}

int main() {
    int N = 5;
    cout << "Numbers from 1 to " << N << " using tail recursion:" << endl;
    printTail(N);
    cout << endl;
    return 0;
}
