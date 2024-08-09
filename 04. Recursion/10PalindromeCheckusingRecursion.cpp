#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &str, int start, int end) {
    if (start >= end) return true; // Base case
    if (str[start] != str[end]) return false;
    return isPalindrome(str, start + 1, end - 1); // Recursive call
}

int main() {
    string str = "racecar";
    if (isPalindrome(str, 0, str.length() - 1)) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }
    return 0;
}
