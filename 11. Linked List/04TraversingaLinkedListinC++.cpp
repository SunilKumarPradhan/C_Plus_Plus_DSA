#include <bits/stdc++.h>
using namespace std;

#include <iostream>

struct Node {
    int data;
    Node *next;
};

Node *createNode(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insert(Node *&head, int value) {
    Node *newNode = createNode(value);
    if (!head) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void traverse(Node *head) {
    Node *temp = head;
    std::cout << "Linked List: ";
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

void cleanup(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *head = nullptr;
    int value;
    char choice;

    do {
        std::cout << "Enter a value to insert: ";
        std::cin >> value;
        insert(head, value);

        std::cout << "Do you want to insert another value? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    traverse(head);
    cleanup(head);

    return 0;
}


/*
Iss function ka naam hai createNode, aur yeh ek naya node create karta hai jismein ek integer value hoti hai.

- Function ka logic:
  1. Yeh function ek naya node banata hai aur usmein data ko assign karta hai.
  2. Node ke next pointer ko nullptr se initialize karta hai.

Iss function ka naam hai insert, aur yeh linked list mein ek naya node insert karta hai.

- Function ka logic:
  1. Agar linked list khaali hai (head = nullptr), toh naya node head ban jaata hai.
  2. Agar linked list khaali nahi hai, toh woh last node tak jata hai aur naya node wahan add karta hai.

Iss function ka naam hai traverse, aur yeh linked list ke saare nodes ko traverse karke unka data print karta hai.

- Function ka logic:
  1. Yeh function linked list ke head se shuru hota hai aur har node ka data print karta hai.
  2. Jab tak current node null nahi hota, woh next node par move karta hai.

Iss function ka naam hai cleanup, aur yeh linked list ke saare nodes ki memory ko free karta hai.

- Function ka logic:
  1. Yeh function har node ko deallocate karta hai jab tak linked list khaali nahi ho jaata.

Process:
- Pehle, user values input karta hai aur woh values linked list mein insert hoti hain.
- Uske baad, linked list ko traverse kiya jaata hai aur saare elements print hote hain.

Example:
- Agar user ne values 10, 20, aur 30 enter kiye hain:

Linked List structure:
10 -> 20 -> 30 -> nullptr

then

- Insert function call hota hai jab user value enter karta hai. Pehle 10 insert hota hai, phir 20, aur finally 30.

Three Iterations:
- Pehli Iteration: User 10 enter karta hai.
  
  Linked List: 10 -> nullptr

- Doosri Iteration: User 20 enter karta hai.
  
  Linked List: 10 -> 20 -> nullptr

- Teesri Iteration: User 30 enter karta hai.
  
  Linked List: 10 -> 20 -> 30 -> nullptr

Dry Run:
1. Initial setup: head = nullptr.
2. User enters 10:
   - createNode(10) se naya node banta hai.
   - insert function mein head ab 10 ho jaata hai.
3. User enters 20:
   - createNode(20) se naya node banta hai.
   - insert function mein last node (10) ke next mein 20 set hota hai.
4. User enters 30:
   - createNode(30) se naya node banta hai.
   - insert function mein last node (20) ke next mein 30 set hota hai.
5. Traverse function call hota hai:
   - Linked List print hota hai: "Linked List: 10 -> 20 -> 30 -> nullptr".
6. Cleanup function call hota hai:
   - Saare nodes ki memory free hoti hai.

Output:
Linked List: 10 -> 20 -> 30 -> nullptr
*/
