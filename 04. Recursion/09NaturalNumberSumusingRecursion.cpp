#include <bits/stdc++.h>
using namespace std;

int sumOfNaturalNumbers(int n) {
    if (n == 0) return 0; // Base case
    return n + sumOfNaturalNumbers(n - 1); // Recursive call
}

int main() {
    int N = 5;
    cout << "Sum of the first " << N << " natural numbers: " << sumOfNaturalNumbers(N) << endl;
    return 0;
}
