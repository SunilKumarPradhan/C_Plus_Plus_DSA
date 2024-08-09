#include <bits/stdc++.h>
using namespace std;

int countDigits(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int main() {
    int n = 12345; // example number

    cout << "Number of digits: " << countDigits(n) << endl;

    return 0;
}
