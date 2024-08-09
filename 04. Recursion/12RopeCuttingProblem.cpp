#include <bits/stdc++.h>
using namespace std;

int maxCuts(int n, int a, int b, int c) {
    if (n == 0) return 0;     // Base case
    if (n < 0) return -1;     // Impossible case

    int res = max({maxCuts(n - a, a, b, c), maxCuts(n - b, a, b, c), maxCuts(n - c, a, b, c)});

    if (res == -1) return -1; // If no valid cuts found
    return res + 1;           // Add one to the result for the current cut
}

int main() {
    int N = 5, a = 1, b = 2, c = 3;
    int result = maxCuts(N, a, b, c);
    if (result != -1) {
        cout << "Maximum number of cuts: " << result << endl;
    } else {
        cout << "Cutting is not possible." << endl;
    }
    return 0;
}
