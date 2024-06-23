#include <bits/stdc++.h>
using namespace std; // iss code ko kaam karne ke liye array ka sorted hona zaroori hai

void removeDup(int arr[], int n){
    if (n == 0) return;

    sort(arr, arr + n); // Sort the array first

    int res = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[res - 1]){
            arr[res] = arr[i];
            res++;
        }
    }
    
    for (int i = 0; i < res; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 3, 6, 7, 2, 1, 4, 5, 6, 7, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    removeDup(arr1, n);
    return 0;
}
