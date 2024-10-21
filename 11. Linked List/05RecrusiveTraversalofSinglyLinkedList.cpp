#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void reverseTraversal(Node* head) {
    if (head == nullptr) {
        return;
    }
    reverseTraversal(head->next);
    cout << head->data << " ";
}

int main() {
    Node* head = nullptr;
    int n, value;

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insert(&head, value);
    }

    cout << "Reverse Traversal of the list: ";
    reverseTraversal(head);
    cout << endl;

    return 0;
}







/*
Iss function ka naam hai reverseTraversal aur yeh function singly linked list ko reverse order mein traverse karta hai aur nodes ke data ko print karta hai.

- Function ka logic:
  1. reverseTraversal(Node* head) ek recursive function hai jo singly linked list ke nodes ko reverse order mein traverse karta hai.
  2. Jab head nullptr hota hai (yaani list ka end aa gaya), function wapas return kar jata hai bina kuch print kiye.
  3. Jaise hi base case se return hota hai, har node ka data wapas recursion ke stack se pop hone par print hota hai.

Process:
- Pehle, function last node tak traverse karta hai.
- Uske baad, jaise jaise function wapas recursive stack se pop hota hai, data reverse order mein print hota hai.

Example:
- Agar linked list hai:

  10 -> 20 -> 30 -> 40 -> nullptr
  
then

reverseTraversal call pehle 40 par aayega, phir wapas 30, phir 20, aur aakhir mein 10 print karega.

- Explanation of example with function calls and outputs:
  reverseTraversal(10)
    -> reverseTraversal(20)
      -> reverseTraversal(30)
        -> reverseTraversal(40)
          -> reverseTraversal(nullptr)
          <- print 40
        <- print 30
      <- print 20
    <- print 10

Three Iterations:
1. First recursive call:
   - Function last node tak pahuchta hai:
   
     10 -> 20 -> 30 -> 40 -> nullptr
     
   - Stack:
     reverseTraversal(10)
     reverseTraversal(20)
     reverseTraversal(30)
     reverseTraversal(40)

2. Pop from recursion:
   - reverseTraversal stack se wapas aata hai aur reverse mein nodes ke data ko print karta hai.

   Pehle 40 print hoga, fir 30, fir 20, fir 10.

   Output so far: 40 30 20 10

3. Final output:
   - Sabhi nodes print hone ke baad recursion end hota hai, aur final output:
   
   40 30 20 10

Dry Run:
1. Input:
   Enter the number of nodes: 4
   Enter value for node 1: 10
   Enter value for node 2: 20
   Enter value for node 3: 30
   Enter value for node 4: 40

2. Step-by-step execution:
   - Node values insert hote hain:
     10 -> 20 -> 30 -> 40 -> nullptr
   - reverseTraversal(10) call hota hai aur recursively last node (40) tak jaata hai.
   - Stack se pop hone par values reverse mein print hoti hain: 40 30 20 10

3. Final output:
   Reverse Traversal of the list: 40 30 20 10
*/
