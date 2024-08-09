#include <bits/stdc++.h>
using namespace std;

int findOneOddOccurring(const vector<int>& arr) {
    int res = 0;
    for (int num : arr) {
        res ^= num;
    }
    return res;
}

int main() {
    vector<int> arr = {4, 3, 4, 4, 4, 5, 5}; // example array

    cout << "One odd occurring element: " << findOneOddOccurring(arr) << endl;

    return 0;
}
