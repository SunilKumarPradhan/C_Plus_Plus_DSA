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

int searchNode(Node* head, int value) {
    Node* temp = head;
    int position = 0;

    while (temp) {
        if (temp->data == value) {
            return position; // Return the position if the node is found
        }
        temp = temp->next;
        position++;
    }

    return -1; // Return -1 if the node is not found
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
    insertAtEnd(head, 50);

    std::cout << "Linked List: ";
    display(head);

    int value;
    std::cout << "Enter value to search: ";
    std::cin >> value;

    int position = searchNode(head, value);
    
    if (position != -1) {
        std::cout << "Value " << value << " found at position: " << position << std::endl;
    } else {
        std::cout << "Value " << value << " not found in the linked list." << std::endl;
    }

    cleanup(head);
    return 0;
}

/*
Iss function ka naam hai searchNode aur yeh linked list mein kisi node ko search karta hai aur uska position return karta hai.

- Function ka logic:
  1. Linked list ke head se start karke har node ka data check kiya jata hai.
  2. Agar data milta hai, toh position return kiya jata hai.
  3. Agar linked list ke end tak search karne par data nahi milta, toh -1 return kiya jata hai.

Process:
- Pehle, linked list ko manually create kiya gaya hai jismein nodes 10, 20, 30, 40, aur 50 hain.
- Uske baad, user se search karne ke liye value input liya jata hai.

Example:
- Agar linked list hai:

10 -> 20 -> 30 -> 40 -> 50 -> nullptr

then 

- User enters value = 30, toh output hoga:

Value 30 found at position: 2

Three Iterations:
- Iteration 1:
  - Initial linked list: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
  - User input: 30
  - Value 30 found at position: 2

- Iteration 2:
  - Initial linked list: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
  - User input: 15
  - Value 15 not found in the linked list.

- Iteration 3:
  - Initial linked list: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
  - User input: 50
  - Value 50 found at position: 4

Dry Run:
1. Initial setup and input: Manually created linked list with nodes 10, 20, 30, 40, and 50.
2. User inputs value = 30.
3. Function searches through the linked list, finds value 30 at position 2.
4. Final output: Value 30 found at position: 2.

Output:
Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
Enter value to search: 30
Value 30 found at position: 2
*/
