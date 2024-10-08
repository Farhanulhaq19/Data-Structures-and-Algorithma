#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
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
void forwardTraversal(Node* node) {
    cout << "Forward: ";
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
void backwardTraversal(Node* node) {
    if (node == NULL) return;

    while (node->next != NULL) {
        node = node->next;
    }

    cout << "Backward: ";
    while (node != NULL) {
        cout << node->data << " ";
        node = node->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    forwardTraversal(head); 
    backwardTraversal(head);

    return 0;
}
