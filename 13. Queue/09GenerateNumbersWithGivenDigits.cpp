#include <bits/stdc++.h>
using namespace std;

vector<int> generateNumbersWithGivenDigits(const vector<int>& digits, int n) {
    vector<int> result;
    queue<int> q;

    // Initialize the queue with the given digits
    for (int digit : digits) {
        if (digit != 0) { // Ignore leading zeros
            q.push(digit);
        }
    }

    // BFS to generate numbers
    while (!q.empty()) {
        int num = q.front();
        q.pop();

        // If the number has n digits, add it to the result
        if (to_string(num).length() == n) {
            result.push_back(num);
        }

        // If the number has fewer than n digits, add the next digit
        if (to_string(num).length() < n) {
            for (int digit : digits) {
                int newNum = num * 10 + digit;
                q.push(newNum);
            }
        }
    }

    return result;
}

int main() {
    vector<int> digits = {1, 2, 3};
    int n = 2;

    vector<int> numbers = generateNumbersWithGivenDigits(digits, n);

    cout << "Generated numbers with given digits: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
