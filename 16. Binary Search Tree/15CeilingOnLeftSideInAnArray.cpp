#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> findCeilingOnLeftSide(vector<int>& arr) {
    
    vector<int> res; 
    set<int> seen;   
    for ( auto num : arr) {
        auto it = seen.lower_bound(num); //lower_bound(num): This is a member function that finds the first element in the container that is not less than (i.e., greater than or equal to) the specified value num.

        res.pb(it != seen.end() ? *it : -1);  //action( condion ? if : else) ;
        seen.insert(num);
    }
    return res;
}

int main() {
    vector<int> arr = {2, 8, 30, 15, 25, 12}; 
    vector<int> result = findCeilingOnLeftSide(arr);

    cout << "Ceiling on the left side for each element: ";
    for (auto num : result){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
/*
std::set<int> seen = {1, 3, 5, 7, 9};
int num = 4;

auto it = seen.lower_bound(num);

// The iterator 'it' will now point to the first element that is >= 4
// In this case, it will point to the element 5

*/

/*
Iss function ka naam hai findCeilingOnLeftSide aur yeh function ek array ke har element ke liye uske left side ka ceiling element find karta hai. Ceiling ka matlab hota hai left side ke elements mein se sabse chhota element jo current element se bada ya barabar ho.

- Function ka logic:
  1. Ek result vector banate hain jismein har element ka ceiling store hoga.
  2. Ek set use karte hain jo elements ko sorted order mein store karega. Is set ki madad se hum efficiently ceiling ko dhoond sakte hain.
  3. Har element ke liye:
     - Set mein lower_bound function ka use karke wo element dhoondhte hain jo current element se bada ya barabar ho.
     - Agar aisa element milta hai, toh usko result mein add kar dete hain. Agar nahi milta, toh -1 add karte hain.
     - Current element ko set mein add karte hain taaki agle elements ke liye ye consider ho sake.

Process:
- Pehle element ka koi left side ceiling nahi hota, isliye uske liye result mein -1 add karte hain.
- Baaki elements ke liye, set mein lower_bound ka use karke left side ka sabse chhota bada element dhoondhte hain.
- Jo milta hai usko result mein add karte hain.

Example:
- Agar array hai: [2, 8, 30, 15, 25, 12]
- Toh har element ke liye left side ke ceilings:
  - 2: koi left side mein element nahi hai, toh -1.
  - 8: left side mein 2 hai, 2 chhota hai 8 se, toh -1.
  - 30: left side mein 2, 8 hain, 8 chhota hai 30 se, toh -1.
  - 15: left side mein 2, 8, 30 hain, 30 bada hai 15 se, toh 30.
  - 25: left side mein 2, 8, 30, 15 hain, 30 bada hai 25 se, toh 30.
  - 12: left side mein 2, 8, 30, 15, 25 hain, 15 bada hai 12 se, toh 15.

Dry Run:
1. Input Array: [2, 8, 30, 15, 25, 12]
   Result: []
   Set: {}

2. First Element: 2
   - Left side mein koi element nahi, result = [-1]
   - Set: {2}

3. Second Element: 8
   - Set mein lower_bound(8) => koi element nahi, result = [-1, -1]
   - Set: {2, 8}

4. Third Element: 30
   - Set mein lower_bound(30) => koi element nahi, result = [-1, -1, -1]
   - Set: {2, 8, 30}

5. Fourth Element: 15
   - Set mein lower_bound(15) => 30, result = [-1, -1, -1, 30]
   - Set: {2, 8, 15, 30}

6. Fifth Element: 25
   - Set mein lower_bound(25) => 30, result = [-1, -1, -1, 30, 30]
   - Set: {2, 8, 15, 25, 30}

7. Sixth Element: 12
   - Set mein lower_bound(12) => 15, result = [-1, -1, -1, 30, 30, 15]
   - Set: {2, 8, 12, 15, 25, 30}

Output:
- Ceiling on the left side for each element: -1 -1 -1 30 30 15
*/
