#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
}

int main() {
    int n = 50; // example upper limit

    cout << "Prime numbers up to " << n << " are: ";
    sieveOfEratosthenes(n);
    cout << endl;

    return 0;
}
