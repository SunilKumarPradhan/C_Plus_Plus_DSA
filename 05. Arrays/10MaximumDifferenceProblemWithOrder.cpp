#include <bits/stdc++.h>
using namespace std;


/*
int MaxDiff(int arr[], int n){
    int res= arr[1]-arr[0];
    for(int i =0; i<n;i++){
        for(int j =i+1;j<n;j++){
            res=max(res,arr[j]-arr[i]);
        }
    }
    return res;
}
*/

int MaxDiff(int arr[], int n) {
    if (n < 2) return 0;  // Handle cases where there are less than 2 elements

    int minVal = arr[0];
    int res = arr[1] - arr[0];

    for (int i = 1; i < n; i++) {
        res = max(res, arr[i] - minVal);
        minVal = min(minVal, arr[i]);
    }
    return res;
}

int main() {
    int arr1[] = {6, 7, 2, 3, 1, 5, 4};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << MaxDiff(arr1, n) << endl;
    return 0;
}
