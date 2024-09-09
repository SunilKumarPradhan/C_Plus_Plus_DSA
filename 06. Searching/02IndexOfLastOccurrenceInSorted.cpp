#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Function to find the first occurrence of a value in an array
int lastOcc(int arr[], int n, int value) {
    for (int i = n-1; i >= 0; --i) {
        if (arr[i] == value) {
            return i; // Return the index of the first occurrence
        }
    }
    return -1; // Return -1 if the value is not found
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
