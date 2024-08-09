#include <bits/stdc++.h>
using namespace std;

void printDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    for (int div : divisors) {
        cout << div << " ";
    }
}

int main() {
    int n = 36; // example number

    cout << "Divisors of " << n << " are: ";
    printDivisors(n);
    cout << endl;

    return 0;
}
