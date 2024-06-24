
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> findAnagrams(string pat, string txt) {
    
    int m = pat.size();
    int n = txt.size();
    
    vector <pair<int, string>> result;

    if (m > n) return result;

    vector<int> txtCount(26, 0);
    vector<int> patCount(26, 0);

    for (int i = 0; i < m; i++) {
        txtCount[txt[i] - 'a']++;
        patCount[pat[i] - 'a']++;
    }

    for (int i = m; i < n; i++) {
        if (txtCount == patCount) { // jab jab count same hua hai tab tab...
            result.push_back({i - m, txt.substr(i - m, m)}); //result naam ke vector mein humne ek pair push kar diya , iss pair mein do cheezein hai , 1: index 2: uss txt ka mein maujood anagram , usko substr karke humne extract kar liya ..
        }

        txtCount[txt[i] - 'a']++;
        txtCount[txt[i - m] - 'a']--;
    }

    if (txtCount == patCount) {
        result.push_back({n - m, txt.substr(n - m, m)});
    }

    return result;
}

// Pehli if Condition: Loop ke andar hoti hai, jo har ek possible window ko check karti hai parantu ant wala window nahi.
// Dusri if Condition: Loop ke baad hoti hai, jo final window ko check karti hai.

int main() {
    string txt = "cbaebabacd";
    string pat = "abc";
    vector<pair<int, string>> anagrams = findAnagrams(pat, txt);

    for (const auto& p : anagrams) {
        cout << "Anagram: " << p.second << ", Starting Index: " << p.first << endl;
    }

    return 0;
}
