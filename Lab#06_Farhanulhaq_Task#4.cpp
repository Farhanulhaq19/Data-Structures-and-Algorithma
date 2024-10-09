#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
void insertAtEnd(Node** head, int data) {
    Node* newNode = new Node{data,NULL,NULL};
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    Node* slow = head; 
    Node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast =fast->next->next;
    }

    return slow; 
}

void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Inserting nodes in the list
    insertAtEnd(&head,9);
    insertAtEnd(&head,19);
    insertAtEnd(&head,24);
    insertAtEnd(&head,48);
    insertAtEnd(&head,784);

    // Printing the list
    cout<<"Linked List: ";
    printList(head);
    Node* middle = findMiddle(head);
    if (middle != NULL) {
        cout<<"Middle node: "<<middle->data << endl;
    } else {
        cout<<"The list is empty."<<endl;
    }

    return 0;
}
