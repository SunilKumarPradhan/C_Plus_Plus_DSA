#include <bits/stdc++.h>
using namespace std;
/*
void rotateArray(int arr[], int n){
    int temp=arr[0];
    for(int i=0; i<n;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
}

void drotateArray(int arr[], int n ,int d){
    for (int i =0; i<d;i++){
        rotateArray(arr,n);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
*/

/*void drotateArray(int arr[], int n ,int d){ // better
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i =0; i<d;i++){
        arr[i-d+n]=temp[i];
    }             //jiss array pe traverse karna hai loop uske acc likhna hai

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
*/


void reversalAlgo(int arr[], int lo, int hi) {
        while (lo < hi) {
            swap(arr[lo], arr[hi]);
            lo++;
            hi--;
        }
}

void drotateArray(int arr[], int n, int d) {
    reversalAlgo(arr, 0, d - 1);
    reversalAlgo(arr, d, n - 1);
    reversalAlgo(arr, 0, n - 1);
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int d = 2;

    

    drotateArray(arr1, n, d);
    
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}