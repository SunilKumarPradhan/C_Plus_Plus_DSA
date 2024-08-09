#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0) return 0; // Base case
    return n % 10 + sumOfDigits(n / 10); // Recursive call
}

int main() {
    int number = 12345;
    cout << "Sum of the digits of " << number << ": " << sumOfDigits(number) << endl;
    return 0;
}
