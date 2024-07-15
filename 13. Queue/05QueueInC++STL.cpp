#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Size of queue: " << q.size() << endl;
    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.back() << endl;
    q.pop();

    cout << "Queue after one dequeue: ";
    queue<int> temp = q; 
    
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    cout << "New front element: " << q.front() << endl;
    cout << "New rear element: " << q.back() << endl;

    return 0;
}
