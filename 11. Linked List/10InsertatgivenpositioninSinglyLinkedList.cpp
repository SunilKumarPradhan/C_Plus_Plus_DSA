#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = createNode(value);
    if (position == 0) { // Insert at the beginning
        newNode->next = head;
        head = newNode;
        return;
    }
    
    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    
    if (temp == nullptr) { // If position is greater than the length of the list
        std::cout << "Position out of bounds. Inserting at the end instead." << std::endl;
        delete newNode; // Clean up the new node since we won't use it
        void insertAtEnd(Node*&head, int value);
        return;
    }

    newNode->next = temp->next; // Link new node to the next node
    temp->next = newNode; // Link the previous node to the new node
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
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
    // Manually creating the linked list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    std::cout << "Initial Linked List: ";
    display(head);

    int value, position;
    std::cout << "Enter value to insert: ";
    std::cin >> value;
    std::cout << "Enter position to insert (0 for beginning, 1 for second, etc.): ";
    std::cin >> position;

    insertAtPosition(head, value, position);

    std::cout << "Updated Linked List: ";
    display(head);

    cleanup(head);
    return 0;
}

/*
Iss function ka naam hai insertAtPosition aur yeh linked list mein kisi bhi desired position par node insert karta hai.

- Function ka logic:
  1. Naya node create kiya jata hai.
  2. Agar position 0 hai, toh naya node ko head bana diya jata hai.
  3. Agar position 0 nahi hai, toh hum linked list traverse karte hain takki hum us position par pahunch sakein.
  4. Agar position valid hai, toh naya node ko us position par insert kiya jata hai.
  5. Agar position out of bounds hai, toh node ko end mein insert kiya jata hai.

Process:
- Pehle, linked list ko manually create kiya gaya hai jismein nodes 10, 20, 30 aur 40 hain.
- Uske baad, user se naya value aur desired position input liya jata hai.

Example:
- Agar linked list hai:

10 -> 20 -> 30 -> 40 -> nullptr

then 

- User enters value = 25 aur position = 2, toh naya linked list hoga:

10 -> 20 -> 25 -> 30 -> 40 -> nullptr

Three Iterations:
- Iteration 1:
  - Initial linked list: 10 -> 20 -> 30 -> 40 -> nullptr
  - User input: value = 25, position = 2
  - Updated linked list: 10 -> 20 -> 25 -> 30 -> 40 -> nullptr

- Iteration 2:
  - Initial linked list: 10 -> 20 -> 30 -> 40 -> nullptr
  - User input: value = 5, position = 0
  - Updated linked list: 5 -> 10 -> 20 -> 30 -> 40 -> nullptr

- Iteration 3:
  - Initial linked list: 10 -> 20 -> 30 -> 40 -> nullptr
  - User input: value = 50, position = 5 (out of bounds)
  - Updated linked list: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr

Dry Run:
1. Initial setup and input: Manually created linked list with nodes 10, 20, 30, and 40.
2. User inputs value = 25 and position = 2.
3. New node with value 25 is inserted at position 2.
4. Final output after insertion: 10 -> 20 -> 25 -> 30 -> 40 -> nullptr.

Output:
Initial Linked List: 10 -> 20 -> 30 -> 40 -> nullptr
Enter value to insert: 25
Enter position to insert (0 for beginning, 1 for second, etc.): 2
Updated Linked List: 10 -> 20 -> 25 -> 30 -> 40 -> nullptr
*/
