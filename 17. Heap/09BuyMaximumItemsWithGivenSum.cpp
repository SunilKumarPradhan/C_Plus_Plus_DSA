#include <bits/stdc++.h>
using namespace std;

int buyMaximumItems(vector<int>& prices, int sum) {
    sort(prices.begin(), prices.end());

    int count = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (sum >= prices[i]) {
            sum -= prices[i];
            count++;
        } else {
            break;
        }
    }

    return count;
}

int main() {
    vector<int> prices = {1, 12, 5, 111, 200, 1000, 10};
    int sum = 50;

    int maxItems = buyMaximumItems(prices, sum);

    cout << "Maximum items that can be bought: " << maxItems << endl;

    return 0;
}


/*
Iss function ka naam hai buyMaximumItems aur yeh function batata hai maximum number of items jo given sum se buy kiye ja sakte hain.

- Function ka logic:
  1. Pehle prices array ko ascending order mein sort karte hain.
  2. Phir sorted array ko traverse karke check karte hain ki given sum se kitne items kharid sakte hain.
  3. Agar current item ki price sum se kam hai, to item ko kharidte hain aur sum ko update karte hain.

Process:
- Pehle, array ko sort karte hain.
- Phir sorted items ko ek-ek karke check karte hain aur sum ko update karte hain jab tak sum sufficient ho.

Example:
- Agar prices array [1, 12, 5, 111, 200, 1000, 10] hai aur sum=50 hai:


then

Sorted prices array: [1, 5, 10, 12, 111, 200, 1000]

Dry Run:
1. Sorted prices: [1, 5, 10, 12, 111, 200, 1000]
2. Initial sum: 50
   - Buy item of price 1, updated sum = 50 - 1 = 49
   - Buy item of price 5, updated sum = 49 - 5 = 44
   - Buy item of price 10, updated sum = 44 - 10 = 34
   - Buy item of price 12, updated sum = 34 - 12 = 22
   - Next item price 111 > remaining sum (22), stop.

Total items bought: 4

Output:
Maximum items that can be bought: 4
*/
