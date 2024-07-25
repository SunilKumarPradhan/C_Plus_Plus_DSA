#include <bits/stdc++.h>
using namespace std;

void sortKSortedArray(vector<int>& arr, int k) {
    
    priority_queue<int> maxHeap;

    int n = arr.size();
    for (int i = 0; i <= k; i++) {
        maxHeap.push(arr[i]);
    }

    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = maxHeap.top();
        maxHeap.pop();
        maxHeap.push(arr[i]);
    }

    while (!maxHeap.empty()) {
        arr[index++] = maxHeap.top();
        maxHeap.pop();
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
Iss function ka naam hai sortKSortedArray aur yeh k-sorted array ko sort karta hai normal priority_queue (max-heap) ka use karke.

- Function ka logic:
  1. Pehle k+1 elements ko max-heap mein daalte hain.
  2. Phir ek-ek karke elements ko max-heap se nikalte hain aur array mein sahi position pe rakhte hain.
  3. Phir array ke baaki elements ko heap mein daal ke same process repeat karte hain.
  4. Finally, heap mein bache hue elements ko array mein daalte hain.

Process:
- Pehle, first k+1 elements ko max-heap mein daalte hain.
- Phir max-heap se top element ko nikalke array mein rakhte hain aur next element ko heap mein daalte hain.
- Yeh process array ke end tak repeat karte hain.
- Last mein heap mein bache hue elements ko array mein daalte hain.


- Agar array [6, 5, 3, 2, 8, 10, 9] hai aur k=3 hai:

 Then: 

Initial max-heap with first k+1 elements:
[6, 5, 3, 2]

 Dry Run: 

   1.  Initial array:  [6, 5, 3, 2, 8, 10, 9]
      -  Max-Heap:  [6, 5, 3, 2]  // Pehle ke 4 elements se max-heap banaya

   2.  Sabse bada element (6) ko array ke shuruat mein rakhte hain aur uski jagah par 8 ko heap mein daalte hain: 
      -  Array:  [6, _, _, _, _, _, _]
      -  Max-Heap:  [8, 5, 3, 2]  // Heap ko dobara se max-heap banane ki jarurat ho sakti hai

   3.  Sabse bada element (8) ko array ke shuruat mein rakhte hain aur uski jagah par 10 ko heap mein daalte hain: 
      -  Array:  [8, _, _, _, _, _, _]
      -  Max-Heap:  [10, 5, 3, 2]  // Heap ko dobara se max-heap banane ki jarurat ho sakti hai

   4.  Sabse bada element (10) ko array ke dusre position par rakhte hain aur uski jagah par 9 ko heap mein daalte hain: 
      -  Array:  [8, 10, _, _, _, _, _]
      -  Max-Heap:  [9, 5, 3, 2]  // Heap ko dobara se max-heap banane ki jarurat ho sakti hai

   5.  Sabse bada element (9) ko array ke teesre position par rakhte hain: 
      -  Array:  [8, 10, 9, _, _, _, _]
      -  Max-Heap:  [5, 2, 3]  // Heap ko dobara se max-heap banane ki jarurat ho sakti hai

   6.  Sabse bada element (5) ko array ke chauthe position par rakhte hain: 
      -  Array:  [8, 10, 9, 5, _, _, _]
      -  Max-Heap:  [3, 2]  // Heap ko dobara se max-heap banane ki jarurat ho sakti hai

   7.  Sabse bada element (3) ko array ke paanchwe position par rakhte hain: 
      -  Array:  [8, 10, 9, 5, 3, _, _]
      -  Max-Heap:  [2]  // Heap ko dobara se max-heap banane ki jarurat ho sakti hai

   8.  Sabse bada element (2) ko array ke chhathe position par rakhte hain: 
      -  Array:  [8, 10, 9, 5, 3, 2, _]
      -  Max-Heap:  []  // Heap khali ho gaya

 Output: 
Sorted array is: 8 10 9 5 3 2
*/

/*

 Heap Sort Algorithm

 Heap Sort  is an efficient sorting algorithm that leverages the heap data structure. Here's a breakdown of the algorithm in 5 steps:

1.  Build a Max-Heap: 
    Convert the given array into a max-heap. This involves arranging the elements such that the parent node is always greater than or equal to its children.

2.  Swap: 
    Swap the root (maximum element) with the last element of the heap.

3.  Reduce Heap Size: 
    Reduce the size of the heap by one, as the largest element is now at the end.

4.  Heapify: 
    Restore the max-heap property by heapifying the reduced heap. This involves adjusting the elements to maintain the heap structure.

5.  Repeat: 
    Repeat steps 2 to 4 until the heap size becomes 1. The array will be sorted in descending order. For ascending order, reverse the sorted array.
*/

