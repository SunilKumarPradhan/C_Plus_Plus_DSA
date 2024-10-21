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
