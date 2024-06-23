#include <bits/stdc++.h>
using namespace std;

int findLargest(int arr[], int n) {
    int largest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int getSecondLargest(int arr[], int n) {
    int largest = findLargest(arr, n);
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int largest = findLargest(arr, n);
    int secondLargest = getSecondLargest(arr, n);

    cout << "The largest element in the array is: " << largest << endl;
    cout << "The second largest element in the array is: " << secondLargest << endl;

    return 0;
}
