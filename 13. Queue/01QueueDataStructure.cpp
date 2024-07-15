#include <bits/stdc++.h>

using namespace std;


template <typename T>
class Queue {

private:
    queue<T> elements;

public:
    Queue() {}
    ~Queue() {}

    bool empty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }

    T front() const {
        if (empty()) {
            throw out_of_range("Queue<>::front(): empty queue");
        }
        return elements.front();
    }

    T back() const {
        if (empty()) {
            throw out_of_range("Queue<>::back(): empty queue");
        }
        return elements.back();
    }

    void push(const T& value) {
        elements.push(value);
    }

    void pop() {
        if (empty()) {
            throw out_of_range("Queue<>::pop(): empty queue");
        }
        elements.pop();
    }
};



int main() {
    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    q.pop();
    q.pop();

    cout << "Front element after popping: " << q.front() << endl;
    cout << "Back element after popping: " << q.back() << endl;

    return 0;
}
