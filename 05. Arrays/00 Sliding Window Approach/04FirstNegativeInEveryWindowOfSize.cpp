// #include <bits/stdc++.h>
// using namespace std;

// int firstNeg(int arr[], int n,int k){
//     int l=0;
//     int r=0;
//     int winSize=r-l+1;

//     vector<int>negative;

//     while(r<n){
//         if(arr[r]<0){
//             negative.push_back(arr[r]);
//         }
//     }

// }

// int main() {
//     int arr[] = {2, -3, 1, -2, 4, 3}; 
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int k = 3; // window size hai ye
//     vector<int> result= firstNeg(arr,n,k);

//     for (int x : result) {
//         cout<<x<< " "<<endl;
//     }    
//     return 0;
// }









#include <iostream>
#include <vector>
using namespace std;

vector<int> firstNeg(int arr[], int n, int k){
    vector<int> result;
    vector<int> negatives;
    
    int l = 0;
    int r = 0;
    int winSize= r -l+1;
    
    while (r < n) {
        if (arr[r] < 0) {
            negatives.push_back(arr[r]);
        }
        
        if (winSize== k) {
            if (negatives.empty()) {
                result.push_back(0); 
            } 
            
            else {
                result.push_back(negatives.front());

                if (arr[l] < 0) {
                    negatives.erase(negatives.begin());
                }
            }
                       // Slide the window
            l++;
        }     
        r++;
    }   
    return result;
}

int main() {
    int arr[] = {2, -3, 1, -2, 4, -3}; // Example array with negative numbers
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Window size

    vector<int> result = firstNeg(arr, n, k);

    cout << "The First negative in each window of size " << k << " : ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
