#include <bits/stdc++.h>
using namespace std;

void rotateArray(int arr[], int n){
    int temp=arr[0];
    for(int i=0; i<n;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    rotateArray(arr1,n);
    return 0;
}
