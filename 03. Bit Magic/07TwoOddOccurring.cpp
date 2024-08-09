#include <bits/stdc++.h>
using namespace std;

pair<int, int> findTwoOddOccurring(const vector<int>& arr) {
    int xor2 = 0;
    for (int num : arr) {
        xor2 ^= num;
    }

    int setBit = xor2 & ~(xor2 - 1);

    int x = 0, y = 0;
    for (int num : arr) {
        if (num & setBit) {
            x ^= num;
        } else {
            y ^= num;
        }
    }

    return {x, y};
}

int main() {
    vector<int> arr = {4, 3, 4, 5, 3, 5, 6, 7}; // example array

    auto result = findTwoOddOccurring(arr);
    cout << "Two odd occurring elements: " << result.first << " and " << result.second << endl;

    return 0;
}
