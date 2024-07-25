#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int root) {
    int largest = root;
    int i=root; // ye wala extra sirf  understanding ke liye daala hai
    
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    heapSort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}


/*
Iss function ka naam hai heapify aur yeh function ek max-heap banata hai given subtree ke liye.

- Function ka logic:
  1. Largest element ko root pe rakhne ke liye subtree ko adjust karta hai.
  2. Agar left ya right child root se bada hai, to unko swap karta hai aur recursion use karke subtree ko adjust karta hai.

Process:
- Pehle, root, left child, aur right child ko compare karta hai.
- Uske baad, agar left ya right child bada hai to swap karta hai aur phir se heapify call karta hai.

Example:
- Agar array [12, 11, 13, 5, 6, 7] hai aur n=6 hai:


then

[12, 11, 13, 5, 6, 7]

Dry Run:
1. Initial call: heapify(arr, 6, 0)
2. Largest = 0, left = 1, right = 2
3. arr[2] (13) > arr[0] (12), largest = 2
4. Swap arr[0] and arr[2], call heapify(arr, 6, 2)
5. heapify(arr, 6, 2): no swaps needed

Output:
[13, 11, 12, 5, 6, 7]
*/

/*
Iss function ka naam hai heapSort aur yeh function array ko sort karta hai heap sort algorithm use karke.

- Function ka logic:
  1. Pehle array ko max-heap banata hai.
  2. Phir array ke last element ko root ke sath swap karta hai aur heap size ko kam karke heapify call karta hai.

Process:
- Pehle, array ko max-heap banata hai.
- Uske baad, last element ko swap karta hai aur remaining array ko heapify karta hai.

Example:
- Agar array [12, 11, 13, 5, 6, 7] hai:


then

Heapify process:
[13, 11, 12, 5, 6, 7]

Sorting process:
[7, 11, 12, 5, 6, 13]
[6, 11, 7, 5, 12, 13]
[5, 6, 7, 11, 12, 13]
[5, 6, 7, 11, 12, 13]

Dry Run:
1. Initial array: [12, 11, 13, 5, 6, 7]
2. Max-heap: [13, 11, 12, 5, 6, 7]
3. Swap and heapify: [7, 11, 12, 5, 6, 13]
4. Swap and heapify: [6, 11, 7, 5, 12, 13]
5. Swap and heapify: [5, 6, 7, 11, 12, 13]

Output:
[5, 6, 7, 11, 12, 13]
*/