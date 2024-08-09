#include <bits/stdc++.h>
using namespace std;

void printPermutations(string str, int left, int right) {
    if (left == right) {
        cout << str << endl;
        return;
    }

    for (int i = left; i <= right; i++) {
        swap(str[left], str[i]); // Swap the current character
        printPermutations(str, left + 1, right); // Recursive call
        swap(str[left], str[i]); // Backtrack
    }
}

int main() {
    string str = "ABC";
    cout << "All permutations of " << str << ":" << endl;
    printPermutations(str, 0, str.size() - 1);
    return 0;
}
