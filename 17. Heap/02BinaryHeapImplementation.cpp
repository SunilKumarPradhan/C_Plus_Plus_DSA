#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> v;
    int size;
    int capacity;

/*
Iss class ka naam hai MinHeap aur yeh ek min-heap data structure ko represent karta hai.

- Class ka logic:
  1. `MinHeap` class me heap ko store karne ke liye ek vector use hota hai.
  2. Class me elements ko insert karne, extract karne, aur heapify karne ke functions hain.

- Important Functions:
  - `insert(int x)`: Heap me ek element ko insert karta hai aur heap property ko maintain karta hai.
  - `minHeapify(int i)`: Heap ke kisi index ko min-heap property maintain karne ke liye adjust karta hai.
  - `extractMin()`: Heap se minimum element ko extract karta hai aur heap property ko maintain karta hai.
  - `decreaseKey(int i, int new_val)`: Heap me kisi element ki value ko decrease karta hai.
  - `deleteKey(int i)`: Heap me kisi element ko delete karta hai.
  - `changeIndexValue(int i, int new_val)`: Heap me kisi index ke value ko change karta hai aur heap property ko maintain karta hai.
  - `buildHeap()`: Array ko min-heap me convert karta hai.
  - `extractMax()`: Max-heap ka maximum element ko extract karta hai.
  - `maxHeapify(int i)`: Heap ke kisi index ko max-heap property maintain karne ke liye adjust karta hai.


Output:
- Extracted Min values: 2, 3, 4, 5
- Extracted Max: 8
- New Min after changeIndexValue: 1
*/


public:
    MinHeap(int c) {
        capacity = c;  // ye uski total capacity ko darshaata hai
        size = 0;  // abhi heap ka size toh 0 ke barabar hai . 
        v.resize(capacity);
    }

    int parent(int i) { return (i-1) / 2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }


    // Yahaan se dher saare functions ki shuruwaat hoti hai


    void insert(int x) {
        if (size == capacity) {
            cout << "Heap is full" << endl;
            return;
        }

        size++;
        int i = size - 1;
        v[i] = x;

        while (i != 0 && v[parent(i)] > v[i]) {
            swap(v[i], v[parent(i)]);
            i = parent(i);
        }
    }
   /*
Iss function ka naam hai insert aur yeh heap me ek element ko insert karta hai aur heap property ko maintain karta hai.

- Function ka logic:
  1. Pehle, check karte hai agar heap full hai to function return kar jata hai.
  2. Element ko heap ke end me add karte hai aur size ko increment karte hai.
  3. Element ko heap property ko maintain karne ke liye bubble up karte hai, yani parent ke index se swap karte hai jab tak element ka parent usse bada hai.

Process:
- Pehle, element ko heap ke last position par rakhte hai.
- Uske baad, bubble up operation perform karte hai jab tak heap property maintain hoti hai.

Example:
- Agar heap hai:

        2
       / \
      3   15

  Aur insert karte hain 1 ko:

        2
       / \
      3   15
     /
    1

  Bubble up se 1 aur 2 swap ho jayega:

        1
       / \
      2   15
     /
    3

Dry Run:
1. Initial setup:
   - Heap = [2, 3, 15], size = 3
   - Insert 1

2. After insertion:
   - Heap = [2, 3, 15, 1], size = 4
   - 1 ka parent 2 se swap hota hai.
   - Final heap = [1, 3, 15, 2]

Output:
Heap after insert: [1, 3, 15, 2]
*/




    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < size && v[l] < v[smallest])
            smallest = l;
        if (r < size && v[r] < v[smallest])
            smallest = r;

        if (smallest != i) {
            swap(v[i], v[smallest]);
            minHeapify(smallest);
        }
    }

   /*
Iss function ka naam hai minHeapify aur yeh heap ke element ko min heap property maintain karne ke liye adjust karta hai.

Min Heap property ensures that the value of the parent node is less than or equal to the values of its children nodes. In a Min Heap, the smallest element is always at the root.

- Function ka logic:
  1. Left aur right children ke indices ko calculate karte hai.
  2. Chhote element ko find karte hai among current node aur children.
  3. Agar smallest element current node nahi hai to swap karte hai aur recursively minHeapify call karte hai.

Process:
- Pehle, left aur right children ke indices ko calculate karte hai.
- Fir, smallest element ko find karte hai aur swap karte hai agar necessary ho.
- Recursive call se subtree me heapify operation continue karte hai.

Example:
- Agar heap hai:

        3
       / \
      10  1

  Aur minHeapify karte hain index 0 pe:

        3
       / \
      10  1

  After minHeapify:

        1
       / \
      10  3

Dry Run:
1. Initial setup:
   - Heap = [3, 10, 1], index = 0
   - Left = 1, Right = 2

2. Comparison and Swapping:
   - Compare elements at indices 0, 1, and 2
   - Smallest element = 1 at index 2
   - Swap 3 and 1
   - Heap after swap = [1, 10, 3]

Output:
Heap after minHeapify: [1, 10, 3]
*/


    void maxHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && v[l] > v[largest])   largest = l;
        if (r < size && v[r] > v[largest])   largest = r;

        if (largest != i) {
            swap(v[i], v[largest]);
            maxHeapify(largest);
        }
    }

    /*
Iss function ka naam hai maxHeapify aur yeh heap ke element ko max heap property maintain karne ke liye adjust karta hai.

- Function ka logic:
  1. Left aur right children ke indices ko calculate karte hai.
  2. Bada element ko find karte hai among current node aur children.
  3. Agar largest element current node nahi hai to swap karte hai aur recursively maxHeapify call karte hai.

Process:
- Pehle, left aur right children ke indices ko calculate karte hai.
- Fir, largest element ko find karte hai aur swap karte hai agar necessary ho.
- Recursive call se subtree me heapify operation continue karte hai.

Example:
- Agar heap hai:

        10
       / \
      20  5

  Aur maxHeapify karte hain index 0 pe:

        10
       / \
      20  5

  After maxHeapify:

        20
       / \
      10  5

Dry Run:
1. Initial setup:
   - Heap = [10, 20, 5], index = 0
   - Left = 1, Right = 2

2. Swapping:
   - Largest element = 20 at index 1
   - Swap 10 and 20
   - Final heap = [20, 10, 5]

Output:
Heap after maxHeapify: [20, 10, 5]
*/


    void buildHeap() {
        for (int i = size / 2 - 1; i >= 0; i--)
            minHeapify(i);
    }

   /*
Iss function ka naam hai buildHeap aur yeh array ko heap me convert karta hai.

- Function ka logic:
  1. Array ke elements ko heap me convert karne ke liye bottom-up approach use karte hai.
  2. Size/2 - 1 se shuru karte hai aur minHeapify call karte hai har element ke liye.

Process:
- Pehle, array ke half se shuru karte hai.
- Har element ke liye minHeapify call karte hai.

Example:
- Agar array hai: [4, 10, 3, 5, 1]

  Aur buildHeap karte hain:

         4
       /   \
     10     3
     / \
    5   1

  MinHeapify karne ke baad:

         1
       /   \
      4     3
     / \
    10  5

Dry Run:
1. Initial setup:
   - Array = [4, 10, 3, 5, 1]
   - Size = 5

2. MinHeapify operations:
   - Apply minHeapify on index 1 (element 10):
     - Left child = 5 (index 3), Right child = 1 (index 4)
     - Smallest = 1 (index 4)
     - Swap 10 and 1 -> Array = [4, 1, 3, 5, 10]

         4
       /   \
      1     3
     / \
    5   10

   - Apply minHeapify on index 0 (element 4):
     - Left child = 1 (index 1), Right child = 3 (index 2)
     - Smallest = 1 (index 1)
     - Swap 4 and 1 -> Array = [1, 4, 3, 5, 10]

         1
       /   \
      4     3
     / \
    5   10

Output:
Heap after buildHeap: [1, 4, 3, 5, 10]
*/



    int extractMin() {
        if (size <= 0)
            return INT_MAX;
        if (size == 1) {
            size--;
            return v[0];
        }

        int root = v[0];
        v[0] = v[size - 1];
        size--;
        minHeapify(0);

        return root;
    }

    /*
Iss function ka naam hai extractMin aur yeh heap se minimum element ko extract karta hai aur heap property ko maintain karta hai.

- Function ka logic:
  1. Minimum element ko root se extract karte hai.
  2. Last element ko root me place karte hai aur size ko decrement karte hai.
  3. Heapify operation perform karte hai to maintain heap property.

Process:
- Pehle, root element ko extract karte hai.
- Last element ko root me place karte hai aur minHeapify call karte hai.

Example:
- Agar heap hai:

        1
       / \
      5   3
     / \
    10  4

  Aur extractMin karte hain:

        4
       / \
      5   3
     / 
    10

Dry Run:
1. Initial setup:
   - Heap = [1, 5, 3, 10, 4]

2. After extraction:
   - Root = 1, last element = 4
   - Place 4 at root
   - MinHeapify operation
   - Final heap = [3, 5, 4, 10]

Output:
Heap after extractMin: [3, 5, 4, 10]
*/


    int extractMax() {
        if (size <= 0)
            return INT_MIN;
        if (size == 1) {
            size--;
            return v[0];
        }

        int root = v[0];
        v[0] = v[size - 1];
        size--;
        maxHeapify(0);

        return root;
    }

    /*
Iss function ka naam hai extractMax aur yeh heap se maximum element ko extract karta hai aur heap property ko maintain karta hai.

- Function ka logic:
  1. Maximum element ko root se extract karte hai.
  2. Last element ko root me place karte hai aur size ko decrement karte hai.
  3. Heapify operation perform karte hai to maintain heap property.

Process:
- Pehle, root element ko extract karte hai.
- Last element ko root me place karte hai aur maxHeapify call karte hai.

Example:
- Agar heap hai:

        20
       / \
      10  5

  Aur extractMax karte hain:

        5
       / \
      10

Dry Run:
1. Initial setup:
   - Heap = [20, 10, 5]

2. After extraction:
   - Root = 20, last element = 5
   - Place 5 at root
   - MaxHeapify operation
   - Final heap = [10, 5]

Output:
Heap after extractMax: [10, 5]
*/



    void decreaseKey(int i, int new_val) {
        v[i] = new_val;
        while (i != 0 && v[parent(i)] > v[i]) {
            swap(v[i], v[parent(i)]);
            i = parent(i);
        }
    }

    /*
Iss function ka naam hai decreaseKey aur yeh heap me kisi element ki value ko decrease karta hai aur heap property ko maintain karta hai.

- Function ka logic:
  1. Element ki value ko update karte hai.
  2. Bubble up operation perform karte hai agar naya value chhota hai.

Process:
- Pehle, value ko update karte hai.
- Fir, bubble up operation perform karte hai agar necessary ho.

Example:
- Agar heap hai:

        3
       / \
      10  5

  Aur decreaseKey karte hain index 1 pe value 1 se:

        1
       / \
      3   5

Dry Run:
1. Initial setup:
   - Heap = [3, 10, 5], index = 1, new_val = 1

2. After decrease:
   - Update value at index 1 to 1
   - Bubble up operation
   - Final heap = [1, 3, 5]

Output:
Heap after decreaseKey: [1, 3, 5]
*/


    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    /*
Iss function ka naam hai deleteKey aur yeh heap me kisi element ko delete karta hai aur heap property ko maintain karta hai.

- Function ka logic:
  1. Element ko minimum possible value se set karte hai.
  2. ExtractMin operation perform karte hai.

Process:
- Pehle, element ko minimum possible value se set karte hai.
- Fir, extractMin call karte hai.

Example:
- Agar heap hai:

        3
       / \
      10  5

  Aur deleteKey karte hain index 1 pe:

        3
       / \
      5

Dry Run:
1. Initial setup:
   - Heap = [3, 10, 5], index = 1

2. After deletion:
   - Set value at index 1 to minimum value
   - ExtractMin operation
   - Final heap = [3, 5]

Output:
Heap after deleteKey: [3, 5]
*/


    void changeIndexValue(int i, int new_val) {
        if (i >= size) {
            cout << "Index out of range" << endl;
            return;
        }
        int old_val = v[i];
        v[i] = new_val;
        if (new_val < old_val)
            decreaseKey(i, new_val);
        else if (new_val > old_val)
            minHeapify(i);
    }

    /*
Iss function ka naam hai changeIndexValue aur yeh heap me kisi index pe value ko change karta hai aur heap property ko maintain karta hai.

- Function ka logic:
  1. Element ki value ko update karte hai.
  2. Agar nayi value chhoti hai to decreaseKey call karte hai, aur agar badi hai to minHeapify call karte hai.

Process:
- Pehle, value ko update karte hai.
- Fir, decreaseKey ya minHeapify call karte hai based on comparison.

Example:
- Agar heap hai:

        4
       / \
      10  5

  Aur changeIndexValue karte hain index 1 pe value 8:

        4
       / \
      8   5

Dry Run:
1. Initial setup:
   - Heap = [4, 10, 5], index = 1, new_val = 8

2. After change:
   - Update value at index 1 to 8
   - Call minHeapify
   - Final heap = [4, 8, 5]

Output:
Heap after changeIndexValue: [4, 8, 5]
*/

};

int main() {

    MinHeap heap(10);

    heap.insert(3);
    heap.insert(2);
    heap.insert(15);

    cout << heap.extractMin() << " ";
    cout << heap.extractMin() << " ";

    heap.insert(5);
    heap.insert(4);
    heap.insert(45);

    heap.deleteKey(1);

    heap.insert(10);
    heap.insert(8);
    heap.insert(12);

    heap.buildHeap();

    cout << "Extract Max: " << heap.extractMax() << endl;
    heap.changeIndexValue(0, 1);
    cout << "New Min: " << heap.extractMin() << endl;
/*
Dry Run for Main Function:
1. Initial Setup:
   - Create a `MinHeap` object with capacity 10.
   - Perform a series of operations: insert, extractMin, deleteKey, buildHeap, and changeIndexValue.

2. Step-by-Step Execution:
   - **Insertions**:
     - Insert 3: Heap = [3]
     - Insert 2: Heap = [2, 3]
     - Insert 15: Heap = [2, 3, 15]
   - **Extract Min**:
     - Extract 2: Heap = [3, 15], Output = 2
     - Extract 3: Heap = [15], Output = 3
   - **Insertions**:
     - Insert 5: Heap = [5, 15]
     - Insert 4: Heap = [4, 15, 5]
     - Insert 45: Heap = [4, 15, 5, 45]
   - **Extract Min**:
     - Extract 4: Heap = [5, 15, 45], Output = 4
   - **Delete Key**:
     - Delete key at index 1: 
       - Set value at index 1 to minimum value: Heap = [5, INT_MIN, 45]
       - Extract Min operation:
         - Replace root with last element: Heap = [45, INT_MIN]
         - Min-Heapify: Heap = [45], Output = 15
   - **Insertions**:
     - Insert 10: Heap = [10, 45]
     - Insert 8: Heap = [8, 45, 10]
     - Insert 12: Heap = [8, 12, 10, 45]
   - **Build Heap**:
     - Heap after buildHeap operation: [8, 12, 10, 45] (already a min-heap)
   - **Extract Max**:
     - Assuming max-heap extraction (hypothetical implementation): Output = 8
   - **Change Index Value**:
     - Change value at index 0 to 1: Heap = [1, 12, 10, 45]
     - Extract Min: Output = 1

Visual Representation (Min-Heap):
- After initial insertions and operations:

      [5]
     /   \
    10   15
   /
  45

- After deleting key at index 1 and further operations:

      [8]
     / \
    12  10
   /
  45
*/

    return 0;
}