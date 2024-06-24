#include <bits/stdc++.h>
using namespace std;

int sellStock(int price[],int n){
    int profit=0;
    for(int i =0; i<n;i++){
        if(price[i]>price[i-1]){
            profit+=(price[i]-price[i-1]);
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