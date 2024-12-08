#include <bits/stdc++.h>
using namespace std;
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
        std::cout << "Enter a value to insert: ";
        std::cin >> value;
        insert(head, value);

        std::cout << "Do you want to insert another value? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Linked List: ";
    display(head);
    cleanup(head);

    return 0;
}

/*
Iss function ka naam hai insert aur yeh linked list mein naya node insert karta hai.

- Function ka logic:
  1. Yeh function pehle naya node create karta hai.
  2. Agar linked list khali hai (head nullptr hai), toh head ko naya node assign karta hai.
  3. Agar list khali nahi hai, toh yeh last node tak traverse karta hai aur wahan naya node attach karta hai.

Process:
- Pehle, naya node create hota hai.
- Uske baad, agar list khali hai, toh head ko set kiya jata hai; nahi toh last node tak jaakar new node attach kiya jata hai.

Example:
- Agar initially list khali hai:

then

Linked List structure:

nullptr

then

- insert function call hota hai with value 10, linked list ab aise dikhai degi:

      +-------+
      | 10    | -> nullptr
      +-------+

Three Iterations:
1. First call: insert(head, 10)
   - head set hota hai 10 se.

2. Second call: insert(head, 20)
   - Traverse karke last node tak jate hain aur new node 20 attach karte hain.

3. Third call: insert(head, 30)
   - Last node (20) ke next pointer mein 30 attach hota hai.

Dry Run:
1. Initial setup: Node* head = nullptr.
2. Function call: insert(head, 10).
3. Final output: head ab 10 se point karta hai.

Output:
Linked List: 10 -> nullptr
*/

/*
Iss function ka naam hai display aur yeh linked list ke elements ko print karta hai.

- Function ka logic:
  1. Yeh function linked list ke head pointer se start hota hai.
  2. Yeh list ke har node ko traverse karta hai aur unka data print karta hai.

Process:
- Pehle, head node se traversal shuru hota hai.
- Uske baad, jab tak current node nullptr nahi hota, data print hota rehta hai.

Example:
- Agar linked list hai:

then

Linked List structure:

      +-------+
      | 10    | -> +-------+
      |       |    | 20    | -> nullptr
      +-------+    +-------+

then

- display function call hota hai aur output hota hai:

      10 -> 20 -> nullptr

Three Iterations:
- Nahi hai; yeh function linked list ke saare nodes ko ek hi baar traverse karta hai.

Dry Run:
1. Initial setup: head pointer jo pehle node ko point karta hai.
2. Function call: display(head).
3. Final output: Print hota hai 10 -> 20 -> nullptr.

Output:
Linked List: 10 -> 20 -> nullptr
*/

/*
Iss function ka naam hai cleanup aur yeh linked list ke nodes ki memory free karta hai.

- Function ka logic:
  1. Yeh function head pointer se start hota hai aur nodes ko deallocate karta hai.
  2. Jab tak current node nullptr nahi hota, har node ko delete karta hai.

Process:
- Pehle, head node se traversal shuru hota hai.
- Uske baad, har node ko delete karke memory free ki jati hai.

Example:
- Agar linked list hai:

then

Linked List structure:

      +-------+
      | 10    | -> +-------+
      |       |    | 20    | -> nullptr
      +-------+    +-------+

then

- cleanup function call hota hai aur saari nodes ki memory free hoti hai.

Three Iterations:
- Nahi hai; yeh function linked list ko deallocate karne ke liye saari nodes ko traverse karta hai.

Dry Run:
1. Initial setup: head pointer jo pehle node ko point karta hai.
2. Function call: cleanup(head).
3. Final output: Saari nodes ki memory free hoti hai.

Output:
Memory freed for all nodes.
*/
