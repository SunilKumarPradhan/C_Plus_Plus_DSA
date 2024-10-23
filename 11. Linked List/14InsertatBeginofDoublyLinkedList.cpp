#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

void cleanup(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);

    std::cout << "Doubly Linked List after inserting nodes at the beginning: ";
    display(head);

    cleanup(head);
    return 0;
}

/*
Iss function ka naam hai insertAtBeginning aur yeh doubly linked list ke starting mein node ko insert karta hai.

- Function ka logic:
  1. Pehle ek naya node create hota hai jisme user ka input value hota hai.
  2. Agar linked list khali hai (head == nullptr), toh yeh node head ban jata hai.
  3. Agar linked list khali nahi hai, toh naya node head ke pehle attach ho jata hai aur uske next pointer ko purane head par point kar diya jata hai.
  4. Head ke prev pointer ko nayi node pe point kar diya jata hai, aur naya node list ka head ban jata hai.

Process:
- Pehle, hum manually nodes ko beginning mein insert kar rahe hain.
- Phir, doubly linked list ko display kar rahe hain.

Example:
- Agar doubly linked list initially empty hai aur hum nodes 30, 20, aur 10 ko insert karte hain:

30 <-> nullptr (First insert)
20 <-> 30 <-> nullptr (Second insert)
10 <-> 20 <-> 30 <-> nullptr (Third insert)

Three Iterations:
- Iteration 1:
  - Node 30 insert hota hai, list: 30 <-> nullptr
- Iteration 2:
  - Node 20 insert hota hai, list: 20 <-> 30 <-> nullptr
- Iteration 3:
  - Node 10 insert hota hai, list: 10 <-> 20 <-> 30 <-> nullptr

Dry Run:
1. Initial setup: Doubly linked list is empty.
2. Insert node 30 -> Doubly linked list becomes 30 <-> nullptr.
3. Insert node 20 -> Doubly linked list becomes 20 <-> 30 <-> nullptr.
4. Insert node 10 -> Doubly linked list becomes 10 <-> 20 <-> 30 <-> nullptr.

Output:
Doubly Linked List after inserting nodes at the beginning: 
10 <-> 20 <-> 30 <-> nullptr
*/
