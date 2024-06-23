#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        if (arr[i] > arr[i+1])
            return false;
    }
    return true;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[] = {1, 2, 7, 8, 3, 4, 5, 6};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    cout << "Is array sorted (arr1): " << isSorted(arr1, n) << endl;
    cout << "Is array sorted (arr2): " << isSorted(arr2, n) << endl;

    return 0;
}
