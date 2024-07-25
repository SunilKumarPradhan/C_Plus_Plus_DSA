#include <bits/stdc++.h>
using namespace std;

vector<int> kClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < arr.size(); i++) {
        maxHeap.push({abs(arr[i] - x), arr[i]});
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9};
    int k = 3;
    int x = 7;

    vector<int> result = kClosestElements(arr, k, x);

    cout << k << " closest elements to " << x << " are: ";
    for (int num : result)
        cout << num << " ";

    return 0;
}

/*
Iss function ka naam hai kClosestElements aur yeh function array se k sabse nazdeek ke elements ko find karta hai ek given number x ke around.

- Function ka logic:
  1. Pehle ek max-heap banate hain, jisme elements ka distance x se calculate kiya jayega. Max-heap largest distance ko root pe rakhta hai.
  2. Array ke har element ka distance x se calculate karte hain aur max-heap mein daalte hain.
  3. Agar max-heap ka size k se bada hota hai, to max-heap ke top element ko remove kar dete hain. Isse hum hamesha k closest elements ko heap mein rakhte hain.
  4. Heap se sab elements ko result vector mein daalte hain aur vector ko sort kar dete hain kyunki heap mein elements unordered hote hain.

Process:
- Pehle, har element ka distance x se calculate kar ke heap mein daalte hain.
- Agar heap ka size k se bada ho jata hai, to largest distance wale element ko remove karte hain.
- Last mein, heap ke elements ko result vector mein daalte hain aur sort kar dete hain.

Example:
- Agar array [5, 6, 7, 8, 9] hai, k=3 hai aur x=7 hai:

1. Distance calculation and max-heap:
   - Distance of 5 from 7: |5 - 7| = 2
   - Distance of 6 from 7: |6 - 7| = 1
   - Distance of 7 from 7: |7 - 7| = 0
   - Distance of 8 from 7: |8 - 7| = 1
   - Distance of 9 from 7: |9 - 7| = 2

   Heap after inserting all elements:
   - Max-Heap: [(2, 5), (1, 6), (0, 7), (1, 8), (2, 9)]

2. Heap size is 5, but k=3, so remove top elements:
   - Remove (2, 5) and (2, 9), remaining heap: [(1, 6), (1, 8), (0, 7)]

3. Result vector after heap extraction and sorting:
   - Result vector: [7, 6, 8] (sorted to [6, 7, 8])

Output:
3 closest elements to 7 are: 6 7 8
*/

