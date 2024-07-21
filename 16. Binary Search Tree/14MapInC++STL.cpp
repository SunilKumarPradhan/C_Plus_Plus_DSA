#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m;

    m.insert(pair<int, string>(1, "One"));  // Style 1: Using insert method with pair
    m.insert(make_pair(2, "Two"));  // Style 2: Using insert method with make_pair
   
    m[3] = "Three";  // Style 3: Using subscript operator (least keywords)
    m[4] = "Four";
    m[5] = "Five";

    cout << "Elements in the map: " << endl;
    cout << "Elements in the map (range-based for loop): " << endl;
    for (auto it: m) {
        cout << it.first << " : " << it.second << endl;
    }


    int x = 3;
    auto it = m.find(x);

    cout << (it != m.end() ? "Element with key " + to_string(x) + " found: " + it->second : "Element with key " + to_string(x) + " not found.") << endl;

    // Style 1: Using erase method with key
    int deleteKey = 2;
    m.erase(deleteKey);

    // Style 2: Using erase method with iterator (least keywords)
    it = m.find(1);
    if (it != m.end()) {
        m.erase(it);
    }

    cout << "Elements in the map after deletion: " << endl;
    for (auto it: m) cout << it.first << " : " << it.second << endl;

    cout << "Size of the map: " << m.size() << endl;

    cout << (m.empty() ? "The map is empty." : "The map is not empty.") << endl;

    m.clear();
    cout << "Elements in the map after clearing: " << m.size() << endl;
    return 0;
}
