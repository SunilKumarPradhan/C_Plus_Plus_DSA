#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> maxHeap;

/*
priority_queue<int> maxHeap;

Iss line ka matlab hai:
1. `priority_queue<int>`: Yeh ek priority queue banata hai jisme elements ka type `int` hota hai. Yeh defaultly max-heap hota hai, jisme largest element top pe hota hai.

Humne `vector<int>` ka explicitly mention nahi kiya kyunki yeh default container hota hai priority_queue ke liye. Matlab, jab hum kuch nahi specify karte, tab bhi internally yeh `vector<int>` ka hi use karta hai elements ko store karne ke liye.

Default priority_queue definition kuch aise hoti hai:
template < class T, class Container = vector<T>, class Compare = less<typename Container::value_type> > class priority_queue;

Iska matlab, agar hum sirf `priority_queue<int>` likhte hain, to:
- `T` hota hai `int`.
- `Container` hota hai `vector<int>`.
- `Compare` hota hai `less<int>`.

Example:
Agar hum elements 10, 30, 20, 5 insert karte hain:
- Insert 10: [10]
- Insert 30: [30, 10]
- Insert 20: [30, 10, 20]
- Insert 5:  [30, 10, 20, 5]

In steps ke baad, max-heap structure ye hoga:
          30
         /  \
        10   20
       / 
      5

maxHeap.top() 30 return karega kyunki max-heap mein largest element top pe hota hai.

Summary:
- `priority_queue<int>`: Elements type `int` aur defaultly `vector<int>` use karta hai internally.
- `less<int>` comparator use karta hai to make it a max-heap.

Humne vector explicitly mention nahi kiya kyunki yeh already default container hai priority_queue ke liye.
*/


    priority_queue<int, vector<int>, greater<int>> minHeap;

    /*
priority_queue<int, vector<int>, greater<int>> minHeap;

Iss line ka matlab hai:
1. `priority_queue<int>`: Yeh ek priority queue banata hai jisme elements ka type `int` hota hai. 
2. `vector<int>`: Yeh priority queue ko internally elements store karne ke liye `vector<int>` ka use karne ke liye specify karta hai.
3. `greater<int>`: Yeh comparator function hai jo priority queue ko min-heap ki tarah behave karne ke liye specify karta hai.

Default behavior mein, `priority_queue` max-heap hota hai, jisme largest element top pe hota hai. Lekin agar hum chahte hain ki priority queue min-heap ki tarah behave kare, to humein comparator function `greater<int>` use karna padta hai. 

Iska matlab hai:
- Jab bhi hum element insert karte hain, `greater<int>` comparator check karega ki naya element pehle se existing elements se chhota hai ya nahi. Chhota element root/top pe rakha jayega.

Example:
Agar hum elements 10, 30, 20, 5 insert karte hain:
- Insert 10: [10]
- Insert 30: [10, 30]
- Insert 20: [10, 30, 20]
- Insert 5:  [5, 10, 20, 30]

In steps ke baad, min-heap structure ye hoga:
          5
         / \
        10  20
       / 
      30

minHeap.top() 5 return karega kyunki min-heap mein smallest element top pe hota hai.

Summary:
- `priority_queue<int>`: Elements type `int`.
- `vector<int>`: Internally vector ka use.
- `greater<int>`: Min-heap behavior ke liye comparator.

Ye line ek min-heap implement kar rahi hai using priority_queue in C++.
*/


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








//YE WAALA EK NORMAL CODE HAI !!

/*
int main() {
    // Max-Heap using priority_queue (default behavior)
    priority_queue<int> maxHeap;

    // Elements insert karte hain
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(5);

    cout << "Max-Heap elements: ";
    while (!maxHeap.empty()) {
        // top() largest element ko return karega
        cout << maxHeap.top() << " ";
        // pop() top element ko remove karega
        maxHeap.pop();
    }
    cout << endl;

    return 0;
}

*/








