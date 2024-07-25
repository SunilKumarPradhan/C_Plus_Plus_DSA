#include <bits/stdc++.h>
using namespace std;

vector<int> kLargestElements(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < k; i++) {
        minHeap.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++) {
        if (arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;

    vector<int> result = kLargestElements(arr, k);

    cout << k << " largest elements are: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}


/*
Iss function ka naam hai kLargestElements aur yeh function array ke k sabse bade elements ko dhoondta hai.

- Function ka logic:
  1. Pehle ek min-heap banate hain. Min-heap ek aisa data structure hota hai jahan smallest element hamesha root pe hota hai.
  2. Array ke pehle k elements ko min-heap mein daalte hain. Isse humare paas ab tak ke k elements sabse chhoti value ke saath min-heap mein hain.
  3. Phir, baaki ke elements ko process karte hain. Agar current element min-heap ke top element (sabse chhoti value) se bada hota hai, to hum min-heap ka top element hata dete hain aur current element ko heap mein daal dete hain.
  4. Jab saare elements process ho jaate hain, tab min-heap ke elements ko ek result vector mein daal dete hain. Kyunki min-heap elements ko smallest to largest order mein store karta hai, hum result vector ko reverse kar dete hain taaki largest elements pehle aayein.

Process:
1. Min-Heap ko banate hain aur usme pehle k elements daalte hain.
2. Array ke baaki elements ko check karte hain. Agar element min-heap ke top se bada hai, to top element ko remove karke current element ko add karte hain.
3. Min-Heap se elements ko result vector mein daalte hain aur reverse kar dete hain.

Example:
- Agar array [1, 23, 12, 9, 30, 2, 50] hai aur k=3 hai:

1. Pehle k=3 elements ko min-heap mein daalte hain: [1, 23, 12]
   - Min-Heap: [1, 12, 23]
2. Next elements ko process karte hain:
   - 9: 9 min-heap ke top (1) se bada nahi hai, isliye kuch nahi karte.
   - 30: 30 min-heap ke top (1) se bada hai, to 1 ko remove karte hain aur 30 ko add karte hain.
     - Min-Heap: [12, 23, 30]
   - 2: 2 min-heap ke top (12) se chhota hai, isliye kuch nahi karte.
   - 50: 50 min-heap ke top (12) se bada hai, to 12 ko remove karte hain aur 50 ko add karte hain.
     - Min-Heap: [23, 30, 50]

3. Min-Heap se elements ko result vector mein daalte hain:
   - Result vector: [23, 30, 50]
   - Reverse karte hain: [50, 30, 23]

Output:
3 largest elements are: 50 30 23
*/
