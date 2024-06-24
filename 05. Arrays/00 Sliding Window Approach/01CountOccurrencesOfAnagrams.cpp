#include <bits/stdc++.h>
using namespace std;

int countAna(string pat, string txt) {
    int n = txt.size();
    int m = pat.size();
    if (m > n) return 0; 

    vector<int> patCount(26, 0);
    vector<int> windowCount(26, 0);
    
    for (int i = 0; i < m; i++) {
        patCount[pat[i] - 'a']++;   // at this point first m characters ki frequency store ho chuki hai , hence loop i=m se start hota hai
        windowCount[txt[i] - 'a']++; 
    }

    int count = 0;

    if (patCount == windowCount) count++;

    // Slide the window over the text
    for (int i = m; i < n; i++) {
        windowCount[txt[i] - 'a']++; // i posn ,window ka end hai i.e i=m tha na  
        windowCount[txt[i - m] - 'a']--; // i-m karenge toh window ka starting hoga, toh hum ab window ke starting se character ke window mein jaake uss se character ki freq, redudce karte hain
        if (patCount == windowCount) count++; // jab jab patCount and windowCount ka value same hoga , tab tab hum count ka value increase kar denge aur iss se total anagram ka count bhi pata chall jaayega.
    }

    return count;
}

int main() {
    string txt = "cbaebabacd";
    string pat = "abc";
    cout << countAna(pat, txt) << endl; // Output should be 2
    return 0;
}
