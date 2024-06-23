#include <bits/stdc++.h>
using namespace std;

int main() {
    array<int,5> arr = {10, 4, 8, 15, 6};
    int n = arr.size();

    int maxElement = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

cout << "The largest element in the array is: " << maxElement << endl;

    return 0;
}
