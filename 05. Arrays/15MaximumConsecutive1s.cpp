#include <bits/stdc++.h>
using namespace std;

int MaxOne(int arr[], int n){
    int count=0;
    for(int i =0;i<n;i++){
        if(arr[i] !=0){count ++;}
        else{count=0;}
    }
    return count;
}
int main() {
    int arr1[] = {0, 1, 1, 0, 1, 1, 1}; 
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout<<"The maximum consectuive one "<<MaxOne(arr1, n)<<endl;
    return 0;
}
