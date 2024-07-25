#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap; // max-heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap for the upper half

public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
};

int main() {
    MedianFinder mf;
    vector<int> nums = {41, 35, 62, 4, 97, 108};

    for (int num : nums) {
        mf.addNum(num);
        cout << "Median after adding " << num << " is: " << mf.findMedian() << endl;
    }

    return 0;
}


/*
Iss class ka naam hai MedianFinder aur yeh class stream of numbers ko handle karti hai aur unka median efficiently find karti hai.

- Class ka logic:
  1. **Data Structures**:
     - `maxHeap`: Yeh max-heap hota hai jo lower half ke elements ko store karta hai. Iska top element sabse bada hota hai jo lower half ka maximum value hota hai.
     - `minHeap`: Yeh min-heap hota hai jo upper half ke elements ko store karta hai. Iska top element sabse chhota hota hai jo upper half ka minimum value hota hai.

  2. **addNum(int num)**:
     - Agar `maxHeap` empty hai ya `num` `maxHeap` ke top element se chhota ya barabar hai, to `num` ko `maxHeap` mein daal dete hain.
     - Agar `num` `maxHeap` ke top se bada hai, to `num` ko `minHeap` mein daal dete hain.
     - **Balancing Heaps**:
       - Agar `maxHeap` ka size `minHeap` se ek element bada hai, to `maxHeap` ka top element `minHeap` mein shift karte hain.
       - Agar `minHeap` ka size `maxHeap` se bada hai, to `minHeap` ka top element `maxHeap` mein shift karte hain.
     - Yeh balancing ensure karta hai ki `maxHeap` aur `minHeap` ka size difference maximum 1 hota hai.

  3. **findMedian()**:
     - Agar `maxHeap` aur `minHeap` ka size barabar hai, to median inka average hota hai: `(maxHeap.top() + minHeap.top()) / 2.0`.
     - Agar `maxHeap` ka size `minHeap` se bada hai, to median `maxHeap` ka top element hota hai.

Process:
- **Adding Numbers**:
  - Pehle, number ko appropriate heap mein daalte hain.
  - Heaps ko balance karte hain, agar size ka difference 1 se zyada hai to.
- **Finding Median**:
  - Agar heaps ka size barabar hai, to do tops ka average return karte hain.
  - Agar `maxHeap` ka size bada hai, to `maxHeap` ka top element median hota hai.

Example:
- Agar numbers [41, 35, 62, 4, 97, 108] hain:

1. Add 41:
   - `maxHeap`: [41]
   - `minHeap`: []
   - Median: 41

2. Add 35:
   - `maxHeap`: [35]
   - `minHeap`: [41]
   - Median: (35 + 41) / 2.0 = 36.0

3. Add 62:
   - `maxHeap`: [41, 35]
   - `minHeap`: [62]
   - Median: 41

4. Add 4:
   - `maxHeap`: [35, 4]
   - `minHeap`: [62, 41]
   - Median: (35 + 41) / 2.0 = 36.0

5. Add 97:
   - `maxHeap`: [41, 97, 4]
   - `minHeap`: [62]
   - Median: 41

6. Add 108:
   - `maxHeap`: [41, 97, 4]
   - `minHeap`: [62, 108]
   - Median: (41 + 62) / 2.0 = 51.5

Output:
Median after adding 41 is: 41
Median after adding 35 is: 36.0
Median after adding 62 is: 41
Median after adding 4 is: 36.0
Median after adding 97 is: 41
Median after adding 108 is: 51.5
*/
