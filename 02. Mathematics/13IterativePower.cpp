#include <bits/stdc++.h>
using namespace std;

double iterativePower(double x, int y) {
    double result = 1;
    while (y > 0) {
        if (y & 1) {
            result *= x;
        }
        x *= x;
        y >>= 1;
    }
    return result;
}

int main() {
    double x = 2.0; // base
    int y = 10; // exponent

    cout << x << " raised to the power " << y << " is " << iterativePower(x, y) << endl;

    return 0;
}
