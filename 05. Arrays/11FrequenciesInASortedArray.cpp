#include <bits/stdc++.h>
using namespace std;

void freq(int arr[], int n) {
    if (n == 0) {
        return;
    }

    int freq = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1]) {
            freq++;
        } else {
            cout << arr[i - 1] << " " << freq << endl;
            freq = 1;
        }
    }
    cout << arr[n - 1] << " " << freq << endl;
}

int main() {
    int arr1[] = {1, 1, 2, 2, 2, 3, 4, 4, 5}; 
    int n = sizeof(arr1) / sizeof(arr1[0]);
    freq(arr1, n);
    return 0;
}
