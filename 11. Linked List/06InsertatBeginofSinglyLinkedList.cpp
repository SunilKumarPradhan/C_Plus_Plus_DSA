#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insert(Node *&head, int value)
{
    Node *newNode = createNode(value);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtBeginning(Node *&head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

void cleanup(Node *head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *head = nullptr;
    int value;
    char choice;

    do
    {
        std::cout << "Enter a value to insert at the end: ";
        std::cin >> value;
        insert(head, value);

        std::cout << "Do you want to insert another value at the end? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Do you want to insert a value at the beginning? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        std::cout << "Enter a value to insert at the beginning: ";
        std::cin >> value;
        insertAtBeginning(head, value);
    }

    std::cout << "Linked List: ";
    display(head);

    cleanup(head);

    return 0;
}




/*
Iss function ka naam hai createNode aur yeh ek naya node create karta hai jo linked list mein use hoga.

- Function ka logic:
  1. Yeh function ek integer value leta hai aur ek naya Node object create karta hai.
  2. Naye node ka data member is value se initialize hota hai aur uska next pointer nullptr par set hota hai.

Iss function ka naam hai insert aur yeh linked list mein naya node add karta hai.

- Function ka logic:
  1. Yeh function ek reference head pointer aur ek integer value leta hai.
  2. Pehle yeh ek naya node create karta hai using createNode function.
  3. Agar head pointer nullptr hai, to naya node head pointer ban jaata hai.
  4. Agar list khali nahi hai, to yeh last node tak traverse karta hai aur naye node ko last node ke next pointer par set karta hai.

Iss function ka naam hai insertAtBeginning aur yeh linked list ke beginning mein naya node add karta hai.

- Function ka logic:
  1. Yeh function ek reference head pointer aur ek integer value leta hai.
  2. Pehle yeh ek naya node create karta hai.
  3. Naya node ka next pointer current head pointer par set hota hai.
  4. Head pointer ko naye node par point karne ke liye update karta hai.

Iss function ka naam hai display aur yeh linked list ke nodes ke data ko print karta hai.

- Function ka logic:
  1. Yeh function head pointer leta hai aur linked list ko traverse karta hai.
  2. Har node ka data print karta hai jab tak wo nullptr nahi ho jaata.

Iss function ka naam hai cleanup aur yeh linked list ke saare nodes ko delete karta hai.

- Function ka logic:
  1. Yeh function head pointer ko leta hai aur list ke har node ko delete karta hai jab tak head pointer nullptr nahi ho jaata.

Dry Run:
1. Initial setup: Linked list khali hai, head pointer nullptr hai.
2. User input lete hain: Pehle user value enter karta hai (e.g., 10).
   - insert function call hota hai, naya node create hota hai aur head pointer ab naya node ban jaata hai.
   - List ab 10 -> nullptr hai.

3. User phir se input le raha hai: dusri value enter karta hai (e.g., 20).
   - Dusra insert function call hota hai, naya node create hota hai, last node ke next pointer par set hota hai.
   - List ab 10 -> 20 -> nullptr hai.

4. User ek value beginning mein insert karna chahta hai: (e.g., 5).
   - insertAtBeginning function call hota hai, naya node create hota hai aur head pointer update hota hai.
   - List ab 5 -> 10 -> 20 -> nullptr hai.

Output:
Linked List: 5 -> 10 -> 20 -> nullptr
*/
