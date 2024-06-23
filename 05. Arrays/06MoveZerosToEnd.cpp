#include <bits/stdc++.h>
using namespace std;

/*
void zeroToEnd(int arr[], int n){
    for (int i =0;i<n;i++){
        if(arr[i]==0){
            for(int j=i+1;j<n;j++){ //zero element and non zero element ko swap kar diya 
                if(arr[j]!=0){
                    swap(arr[i],arr[j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
*///1 8 6 5 3 0 0 0 0 0   iss waale se thoda modification toh ho jaata hai

void zeroToEnd(int arr[], int n){//efficient
int count=0;

    for (int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[count]);  // iss waale ko acche se dekhna ek baar !
            count++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}//1 3 5 6 8 0 0 0 0 0 

int main() {
    int arr1[] = {1, 0, 3, 0,0,0, 5, 6, 0, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    zeroToEnd(arr1, n);
    return 0;
}
