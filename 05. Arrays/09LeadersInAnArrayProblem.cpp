#include <bits/stdc++.h>
using namespace std;

/*void Leader(int arr[], int n) {  7 5 4
    for (int i = 0; i < n; i++) {
        bool isLeader = true;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                isLeader = false;
                break;
            }
        }
        if (isLeader) {
            cout << arr[i] << " ";
        }
    }
}
*/
void Leader(int arr[],int n){ //45 7 
    int ldr=n-1;
    cout<<arr[ldr];
    for(int i=n-2; i>=0;i--){
        if(arr[ldr]<arr[i]){
            arr[ldr]=arr[i];
            cout<<arr[ldr]<<" "; 
        }
    }
}

int main() {
    int arr1[] = {6, 7, 2, 3, 1, 5, 4};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    Leader(arr1, n);
    return 0;
}
