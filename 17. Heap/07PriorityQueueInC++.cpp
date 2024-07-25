#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(5);

    cout << "Max-Heap elements: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(5);

    cout << "Min-Heap elements: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}

/*
Iss code mein hum max-heap aur min-heap ka use kar rahe hain using priority_queue in C++.

- Max-Heap:
  1. priority_queue<int> maxHeap ke through banate hain, jo defaultly max-heap hota hai.
  2. Elements ko push karte hain aur top() se largest element ko access karte hain.

- Min-Heap:
  1. priority_queue<int, vector<int>, greater<int>> minHeap ke through banate hain.
  2. Elements ko push karte hain aur top() se smallest element ko access karte hain.

Process:
- Max-Heap:
  1. Elements 10, 30, 20, 5 ko push karte hain.
  2. maxHeap.top() se largest element ko print karte hain aur pop karte hain.
- Min-Heap:
  1. Elements 10, 30, 20, 5 ko push karte hain.
  2. minHeap.top() se smallest element ko print karte hain aur pop karte hain.

Example:
- Max-Heap:
  1. Push: 10, 30, 20, 5
  2. Max-Heap: [30, 20, 10, 5]

- Min-Heap:
  1. Push: 10, 30, 20, 5
  2. Min-Heap: [5, 10, 20, 30]

Dry Run:
1. Max-Heap initial elements: 10, 30, 20, 5
   - Max-Heap after push: [30, 20, 10, 5]
   - Output: 30 20 10 5

2. Min-Heap initial elements: 10, 30, 20, 5
   - Min-Heap after push: [5, 10, 20, 30]
   - Output: 5 10 20 30

Output:
Max-Heap elements: 30 20 10 5 
Min-Heap elements: 5 10 20 30
*/

