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

void deleteLastNode(Node*& head) {
    if (!head) return; // If the list is empty, do nothing
    if (!head->next) { // If there's only one node
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->next) {
        temp = temp->next;
    }
    delete temp->next; // Delete the last node
    temp->next = nullptr; // Set the new last node's next to nullptr
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
    std::cout << "Do you want to delete the last node? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        deleteLastNode(head);
    }

    std::cout << "Linked List after deletion: ";
    display(head);

    choice = 'n'; // Reset choice for further operations
    std::cout << "Do you want to insert a value at the end? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int value;
        std::cout << "Enter a value to insert at the end: ";
        std::cin >> value;
        insertAtEnd(head, value);
    }

    std::cout << "Final Linked List: ";
    display(head);

    cleanup(head);
    return 0;
}

/*
Iss function ka naam hai deleteLastNode aur yeh linked list ke aakhri node ko delete karta hai.

- Function ka logic:
  1. Agar head null hai, toh kuch nahi kiya jata.
  2. Agar sirf ek node hai, toh usko delete karte hain aur head ko null set karte hain.
  3. Agar do ya usse zyada nodes hain, toh list ke aakhri node tak pahunchne ke liye loop chalayenge.
  4. Aakhri node ko delete karne ke baad, second last node ka next pointer null set karte hain.

Process:
- Pehle, linked list ko manually create kiya gaya hai jismein nodes 10, 20, 30 aur 40 hain.
- Uske baad, user se poocha jayega ki kya wo aakhri node delete karna chahta hai.

Example:
- Agar linked list hai:

10 -> 20 -> 30 -> 40 -> nullptr

then 

- User se poocha jayega ki kya wo aakhri node delete karna chahta hai.

Three Iterations:
- Iteration 1:
  - Initial linked list: 10 -> 20 -> 30 -> 40 -> nullptr
  - User input: y
  - Aakhri node (40) delete hota hai.
  - Updated linked list: 10 -> 20 -> 30 -> nullptr

- Iteration 2:
  - Initial linked list: 10 -> 20 -> 30 -> nullptr
  - User input: y
  - Aakhri node (30) delete hota hai.
  - Updated linked list: 10 -> 20 -> nullptr

- Iteration 3:
  - Initial linked list: 10 -> 20 -> nullptr
  - User input: n
  - Updated linked list remains: 10 -> 20 -> nullptr

Dry Run:
1. Initial setup and input: Manually created linked list with nodes 10, 20, 30, and 40.
2. User inputs 'y' to delete the last node, which is 40.
3. Final output after deletion: 10 -> 20 -> 30 -> nullptr.

Output:
Initial Linked List: 10 -> 20 -> 30 -> 40 -> nullptr
Do you want to delete the last node? (y/n): y
Linked List after deletion: 10 -> 20 -> 30 -> nullptr
Do you want to insert a value at the end? (y/n): y
Enter a value to insert at the end: 50
Final Linked List: 10 -> 20 -> 50 -> nullptr
*/
