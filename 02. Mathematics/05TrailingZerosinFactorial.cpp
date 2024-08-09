#include <bits/stdc++.h>
using namespace std;

int countTrailingZeros(int n) {
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    int n = 100; // example number

    cout << "Number of trailing zeros in " << n << "! is " << countTrailingZeros(n) << endl;

    return 0;
}
