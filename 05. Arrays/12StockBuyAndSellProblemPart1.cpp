#include <bits/stdc++.h>
using namespace std;

int sellStock(int price[], int st, int end) {
    int profit = 0;
    if (end <= st) return 0;

    for (int i = st; i < end; ++i) {
        for (int j = i + 1; j <= end; ++j) {
            if (price[j] > price[i]) {
                int curr_profit = (price[j] - price[i]) +
                                  sellStock(price, st, i - 1) +
                                  sellStock(price, j + 1, end);

                profit = max(curr_profit, profit);
            }
        }
    }
    return profit;
}

int main() {
    int arr1[] = { 6, 2, 3, 1, 5, 4,7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int max_profit = sellStock(arr1,n);
    cout << "Maximum profit: " << max_profit << endl;
    return 0;
}
