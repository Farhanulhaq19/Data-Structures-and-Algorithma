#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void insertAtEnd(Node** head, int data) {
    Node* newNode = new Node{data, NULL};
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void traverseCircularList(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void deleteNode(Node** head, int key) {
    if (*head == NULL) return;

    Node *current = *head, *prev = NULL;

    // If the head node holds the key
    if ((*head)->data == key) {
        // Find the last node to update its next pointer
        while (current->next != *head) {
            current = current->next;
        }
        if (current == *head) {
            delete *head;
            *head = NULL;
            return;
        }
        current->next = (*head)->next;
        delete *head;
        *head = current->next;
        return;
    }
    prev = *head;
    current = (*head)->next;
    while (current != *head && current->data != key) {
        prev = current;
        current = current->next;
    }
    if(current->data==key) {
        prev->next = current->next;
        delete current;
    } else {
        cout<<"Key not found in the list." << endl;
    }
}
int main() {
    Node* head=NULL;

    insertAtEnd(&head,19);
    insertAtEnd(&head,74);
    insertAtEnd(&head,70);
    insertAtEnd(&head,5);

    cout << "Circular Linked List: ";
    traverseCircularList(head);

    deleteNode(&head,74);
    cout<<"After Deletion: ";
    traverseCircularList(head);

    return 0;
}
