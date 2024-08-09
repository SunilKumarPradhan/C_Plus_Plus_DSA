#include <bits/stdc++.h>
using namespace std;

void generateSubsets(const vector<int>& set, vector<int>& current, int index) {
    if (index == set.size()) {
        cout << "{ ";
        for (int num : current) {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }

    // Include the current element
    current.push_back(set[index]);
    generateSubsets(set, current, index + 1);

    // Exclude the current element
    current.pop_back();
    generateSubsets(set, current, index + 1);
}

int main() {
    vector<int> set = {1, 2, 3};
    vector<int> current;
    cout << "All subsets:" << endl;
    generateSubsets(set, current, 0);
    return 0;
}
