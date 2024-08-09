#include <bits/stdc++.h>
using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = 5; // example number

    cout << "Factorial of " << n << " is " << factorial(n) << endl;

    return 0;
}
