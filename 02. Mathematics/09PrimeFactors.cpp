#include <bits/stdc++.h>
using namespace std;

void printPrimeFactors(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 2) {
        cout << n << " ";
    }
}

int main() {
    int n = 315; // example number

    cout << "Prime factors of " << n << " are: ";
    printPrimeFactors(n);
    cout << endl;

    return 0;
}
