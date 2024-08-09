#include <bits/stdc++.h>
using namespace std;

bool subsetSum(const vector<int>& set, int n, int sum) {
    if (sum == 0) return true; // Base case
    if (n == 0) return false;

    if (set[n - 1] > sum) return subsetSum(set, n - 1, sum);

    return subsetSum(set, n - 1, sum) || subsetSum(set, n - 1, sum - set[n - 1]);
}

int main() {
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (subsetSum(set, set.size(), sum)) {
        cout << "Subset with sum " << sum << " exists." << endl;
    } else {
        cout << "No subset with sum " << sum << " exists." << endl;
    }

    return 0;
}
