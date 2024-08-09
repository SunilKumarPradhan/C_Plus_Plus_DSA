#include <bits/stdc++.h>
using namespace std;

double power(double x, int y) {
    if (y == 0) return 1;
    double half = power(x, y / 2);
    if (y % 2 == 0) {
        return half * half;
    } else {
        return x * half * half;
    }
}

int main() {
    double x = 2.0; // base
    int y = 10; // exponent

    cout << x << " raised to the power " << y << " is " << power(x, y) << endl;

    return 0;
}
