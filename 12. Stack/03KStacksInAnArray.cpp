#include <bits/stdc++.h>
using namespace std;

class KStacks {
private:
    int *arr;       // Array of size n to store actual content to be stored in stacks
    int *top;       // Array of size k to store indexes of top elements of stacks
    int *next;      // Array of size n to store next entry in all stacks and free list
    int n, k;       // n is the size of the array arr, k is the number of stacks
    int free;       // To store the beginning index of the free list

public:
    // Constructor to initialize k stacks in an array of size n
    KStacks(int k, int n) {
        this->k = k;
        this->n = n;
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // Initialize all stacks as empty
        for (int i = 0; i < k; i++) {
            top[i] = -1;
        }

        // Initialize all spaces as free
        free = 0;
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1; // -1 indicates end of the free list
    }

    // Function to push an element x to stack number sn (stack number is 0-based)
    void push(int x, int sn) {
        if (free == -1) {
            throw overflow_error("Stack Overflow");
        }

        // Get the first free position
        int i = free;

        // Update the free position
        free = next[i];

        // Insert x into the free position
        arr[i] = x;

        // Update next to point to the old top of stack
        next[i] = top[sn];

        // Update the top to point to the new top of stack
        top[sn] = i;
    }

    // Function to pop an element from stack number sn (stack number is 0-based)
    int pop(int sn) {
        if (top[sn] == -1) {
            throw underflow_error("Stack Underflow");
        }

        // Get the top index of stack sn
        int i = top[sn];

        // Update the top to point to the next element in the stack
        top[sn] = next[i];

        // Add the free index to the beginning of the free list
        next[i] = free;
        free = i;

        // Return the popped element
        return arr[i];
    }

    // Destructor to free allocated memory
    ~KStacks() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    // Create 3 stacks in an array of size 10
    int k = 3, n = 10;
    KStacks ks(k, n);

    // Push elements to different stacks
    ks.push(15, 2);
    ks.push(45, 2);
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    // Pop elements from different stacks
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}
