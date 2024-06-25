#include <bits/stdc++.h>
using namespace std;

class TwoStacks {
private:
    int* arr;
    int size;
    int top1, top2;

public:
    // Constructor to initialize the array and the stack pointers
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    // Method to push an element to the first stack
    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            throw overflow_error("Stack Overflow");
        }
    }

    // Method to push an element to the second stack
    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            throw overflow_error("Stack Overflow");
        }
    }

    // Method to pop an element from the first stack
    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1--];
            return x;
        } else {
            throw underflow_error("Stack Underflow");
        }
    }

    // Method to pop an element from the second stack
    int pop2() {
        if (top2 < size) {
            int x = arr[top2++];
            return x;
        } else {
            throw underflow_error("Stack Underflow");
        }
    }

    // Destructor to free allocated memory
    ~TwoStacks() {
        delete[] arr;
    }
};

int main() {
    TwoStacks ts(10);

    ts.push1(5);
    ts.push2(10);
    ts.push1(15);
    ts.push2(20);
    ts.push1(25);
    ts.push2(30);

    cout << "Popped element from stack1 is: " << ts.pop1() << endl;
    cout << "Popped element from stack2 is: " << ts.pop2() << endl;

    return 0;
}
