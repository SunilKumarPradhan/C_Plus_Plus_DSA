#include <bits/stdc++.h>
using namespace std;
void Reverse(int arr[], int n){
    int hi=n-1;
    int lo=0;
    while(lo<hi){
        swap(arr[lo],arr[hi]);
        lo++;
        hi--;
    }
}
int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    Reverse(arr1,n);
    for (int i =0; i<n;i++){
        cout<<arr1[i]<<endl;
    }
    return 0;
}
