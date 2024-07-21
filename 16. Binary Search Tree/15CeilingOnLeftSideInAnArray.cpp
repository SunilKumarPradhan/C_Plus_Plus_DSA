#include <bits/stdc++.h>
using namespace std;

vector<int> findCeilingOnLeftSide(vector<int>& arr) {
    
    vector<int> res; // Result vector to store ceilings
    set<int> seen;   // Set to store the elements seen so far in a sorted order

    for ( int& num : arr) {
        auto it = seen.lower_bound(num);

        res.push_back(it != seen.end() ? *it : -1);  //action( condion ? if : else) ;
        seen.insert(num);
    }
    return res;
}

int main() {
    vector<int> arr = {2, 8, 30, 15, 25, 12}; // Example array
    vector<int> result = findCeilingOnLeftSide(arr);

    cout << "Ceiling on the left side for each element: ";
    for (const int& num : result){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
