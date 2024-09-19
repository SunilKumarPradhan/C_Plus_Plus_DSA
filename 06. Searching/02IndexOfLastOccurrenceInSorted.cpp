#include <bits/stdc++.h>
using namespace std;

int lastOcc(int arr[], int n, int value) {
    for (int i = n-1; i >= 0; --i) {
        if (arr[i] == value) {
            return i; 
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 3, 7, 9, 3, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int valueToFind = 3;

    int index = lastOcc(arr, n, valueToFind);
    
    if (index != -1) {
        cout << "Last occurrence of value " << valueToFind << " is at index " << index << "." << endl;
    } else {
        cout << "Value " << valueToFind << " not found in the array." << endl;
    }

    return 0;
}
