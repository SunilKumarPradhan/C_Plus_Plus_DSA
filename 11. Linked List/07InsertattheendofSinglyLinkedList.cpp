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
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    std::cout << "Initial Linked List: ";
    display(head);

    char choice;
    std::cout << "Do you want to insert a value at the end? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int value;
        std::cout << "Enter a value to insert at the end: ";
        std::cin >> value;
        insertAtEnd(head, value);
    }

    std::cout << "Updated Linked List: ";
    display(head);

    cleanup(head);
    return 0;
}

/*
Iss function ka naam hai createNode aur yeh ek naya node create karta hai jismein specified value hoti hai.

- Function ka logic:
  1. Yeh function ek naya Node banata hai aur usmein value set karta hai.
  2. Yeh function naya node ka next pointer null set karta hai.

Iss function ka naam hai insertAtEnd aur yeh linked list ke end mein naya node insert karta hai.

- Function ka logic:
  1. Yeh function naya node banata hai.
  2. Agar head null hai, toh yeh naya node ko head set karta hai.
  3. Agar head null nahi hai, toh yeh list ko traverse karke last node tak pahunchta hai aur naya node ko wahan insert karta hai.

Process:
- Pehle, linked list ko manually create kiya gaya hai jismein nodes 10, 20, 30 aur 40 hain.
- Uske baad, linked list ko display kiya gaya hai.

Example:
- Agar linked list hai:

10 -> 20 -> 30 -> 40 -> nullptr

then 

- User se poocha jayega ki kya wo end mein ek naya value insert karna chahta hai.

Three Iterations:
- Iteration 1:
  - Initial linked list: 10 -> 20 -> 30 -> 40 -> nullptr
  - User input: y
  - User inserts value 50.
  - Updated linked list: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr

- Iteration 2:
  - Initial linked list: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
  - User input: y
  - User inserts value 60.
  - Updated linked list: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> nullptr

- Iteration 3:
  - Initial linked list: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> nullptr
  - User input: n
  - Updated linked list remains: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> nullptr

Dry Run:
1. Initial setup and input: Manually created linked list with nodes 10, 20, 30, and 40.
2. User inputs 'y' to insert a value, then inputs 50.
3. Final output after insertion: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr.

Output:
Initial Linked List: 10 -> 20 -> 30 -> 40 -> nullptr
Do you want to insert a value at the end? (y/n): y
Enter a value to insert at the end: 50
Updated Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
*/
