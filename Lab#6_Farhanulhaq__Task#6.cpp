#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}
void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();
    Node* last = *head;
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}
void insertAtPosition(Node** head, int newData, int position) {
    Node* newNode = new Node();
    newNode->data = newData;
    
    if (position == 1) {
        insertAtBeginning(head, newData);
        return;
    }

    Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range." << endl;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 40);
    insertAtPosition(&head, 30, 2); 

    printList(head);
    return 0;
}
