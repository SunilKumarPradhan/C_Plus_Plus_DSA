#include <iostream>
using namespace std;

int findLargestElement(int arr[], int size) {
    if (size <= 0) {        
        cerr << "Error: Invalid array size." << endl;
        return -1; 
    }

    int maxElement = arr[0]; 
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i]; 
        }
    }

    return maxElement; 
}

int main() {
    int arr[] = {1, 2, 6, 3, 4, 5}; 
    int size = sizeof(arr) / sizeof(arr[0]); 

    int largest = findLargestElement(arr, size);
    cout << "The largest element in the array is: " << largest << endl;
    return 0;
}
