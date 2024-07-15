#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> s;
    
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

void printQueue(queue<int>& q) {
    queue<int> temp = q; 
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original Queue: ";
    printQueue(q);
    reverseQueue(q);

    cout << "Reversed Queue: ";
    printQueue(q);
    return 0;
}