#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 48; // first number
    int b = 18; // second number

    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;

    return 0;
}
