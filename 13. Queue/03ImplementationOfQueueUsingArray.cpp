#include <bits/stdc++.h>
using namespace std;

class Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;

public:
    Queue(unsigned capacity);
    ~Queue();
    void enqueue(int item);
    int dequeue();
    int frontElement();
    int rearElement();
    bool isFull();
    bool isEmpty();
};

Queue::Queue(unsigned capacity) {
    this->capacity = capacity;
    front = size = 0;
    rear = capacity - 1;
    array = new int[this->capacity];
}

Queue::~Queue() {
    delete[] array;
}

bool Queue::isFull() {
    return (size == capacity);
}

bool Queue::isEmpty() {
    return (size == 0);
}

void Queue::enqueue(int item) {
    if (isFull())
        return;
    rear = (rear + 1) % capacity;
    array[rear] = item;
    size = size + 1;
    cout << item << " enqueued to queue\n";
}

int Queue::dequeue() {
    if (isEmpty())
        return INT_MIN;
    int item = array[front];
    front = (front + 1) % capacity;
    size = size - 1;
    return item;
}

int Queue::frontElement() {
    if (isEmpty())
        return INT_MIN;
    return array[front];
}

int Queue::rearElement() {
    if (isFull())
        return INT_MIN;
    return array[rear];
}

int main() {
    Queue queue(1000);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    cout << queue.dequeue() << " dequeued from queue\n";
    cout << "Front item is " << queue.frontElement() << endl;
    cout << "Rear item is " << queue.rearElement() << endl;

    return 0;
}
