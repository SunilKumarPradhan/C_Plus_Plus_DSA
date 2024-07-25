#include <bits/stdc++.h>
using namespace std;

void sortKSortedArray(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int n = arr.size();
    for (int i = 0; i <= k; i++) {
        minHeap.push(arr[i]);
    }

    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[i]);
    }

    while (!minHeap.empty()) {
        arr[index++] = minHeap.top();
        minHeap.pop();
    }
}

int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    sortKSortedArray(arr, k);

    cout << "Sorted array is \n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}

/*
Iss function ka naam hai sortKSortedArray aur yeh k-sorted array ko sort karta hai.

- Function ka logic:
  1. Pehle k+1 elements ko min-heap mein daalte hain.
  2. Phir ek-ek karke elements ko min-heap se nikalte hain aur array mein sahi position pe rakhte hain.
  3. Phir array ke baaki elements ko heap mein daal ke same process repeat karte hain.
  4. Finally, heap mein bache hue elements ko array mein daalte hain.

Process:
- Pehle, first k+1 elements ko min-heap mein daalte hain.
- Phir min-heap se top element ko nikalke array mein rakhte hain aur next element ko heap mein daalte hain.
- Yeh process array ke end tak repeat karte hain.
- Last mein heap mein bache hue elements ko array mein daalte hain.

Example:
- Agar array [6, 5, 3, 2, 8, 10, 9] hai aur k=3 hai:


then

Initial min-heap with first k+1 elements:
[2, 5, 3, 6]

Dry Run:
1. Initial array: [6, 5, 3, 2, 8, 10, 9]
   - Min-Heap: [2, 5, 3, 6]
2. Element 2 ko position 0 pe rakha aur 8 ko heap mein daala:
   - Array: [2, _, _, _, _, _, _]
   - Min-Heap: [3, 5, 6, 8]
3. Element 3 ko position 1 pe rakha aur 10 ko heap mein daala:
   - Array: [2, 3, _, _, _, _, _]
   - Min-Heap: [5, 8, 6, 10]
4. Element 5 ko position 2 pe rakha aur 9 ko heap mein daala:
   - Array: [2, 3, 5, _, _, _, _]
   - Min-Heap: [6, 8, 10, 9]
5. Element 6 ko position 3 pe rakha:
   - Array: [2, 3, 5, 6, _, _, _]
   - Min-Heap: [8, 9, 10]
6. Element 8 ko position 4 pe rakha:
   - Array: [2, 3, 5, 6, 8, _, _]
   - Min-Heap: [9, 10]
7. Element 9 ko position 5 pe rakha:
   - Array: [2, 3, 5, 6, 8, 9, _]
   - Min-Heap: [10]
8. Element 10 ko position 6 pe rakha:
   - Array: [2, 3, 5, 6, 8, 9, 10]
   - Min-Heap: []

Output:
Sorted array is: 2 3 5 6 8 9 10
*/

