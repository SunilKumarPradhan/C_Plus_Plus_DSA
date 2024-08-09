#include <bits/stdc++.h>
using namespace std;

void printPowerSet(const vector<int>& set) {
    int n = set.size();
    int powerSetSize = 1 << n;

    for (int i = 0; i < powerSetSize; i++) {
        cout << "{ ";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << set[j] << " ";
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<int> set = {1, 2, 3}; // example set

    cout << "Power set:" << endl;
    printPowerSet(set);

    return 0;
}
