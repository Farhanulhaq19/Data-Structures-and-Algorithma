#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
void insertAtBeginning(Node** head, int data) {
    Node* newNode = new Node{data, NULL, *head};
    if (*head != NULL) (*head)->prev = newNode;
    *head =newNode;
}
void insertAtEnd(Node** head, int data)
{
    Node* newNode=new Node{data, NULL, NULL};
    if (*head==NULL)
    {
        *head=newNode;
        return;
    }
    Node* temp=*head;
    while (temp->next !=NULL)temp= temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void insertAtPosition(Node** head, int data, int position) {
    if (position <=1) {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode=new Node{data, NULL, NULL};
    Node* temp=*head;
    for (int i=1;temp !=NULL && i <position-1; i++)temp=temp->next;

    if (temp==NULL || temp->next==NULL) {
        insertAtEnd(head, data);
    } else {
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
    }
}
// Delete from the beginning
void deleteFromBeginning(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    if (*head !=NULL) (*head)->prev = NULL;
    delete temp;
}
// Delete from the end
void deleteFromEnd(Node** head) {
    if (*head==NULL) return;
    Node* temp=*head;
    while (temp->next !=NULL)temp=temp->next;
    if (temp->prev !=NULL) {
        temp->prev->next =NULL;
    } else
    {
        *head=NULL;
    }
    delete temp;
}
// Delete from a specific position
void deleteFromPosition(Node** head, int position) {
    if (*head==NULL || position <= 0) return;
    if (position== 1) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp=*head;
    for (int i=1; temp !=NULL && i < position; i++) temp = temp->next;
    if (temp == NULL) return;
    if (temp->next !=NULL)temp->next->prev = temp->prev;
    if (temp->prev !=NULL)temp->prev->next = temp->next;
    delete temp;
}

// Print the list
void printList(Node* head) {
    while (head != NULL) {
        cout<<head->data << " ";
        head=head->next;
    }
    cout << endl;
}
int main() {
    Node* head = NULL;
    // Insertions
    insertAtEnd(&head,78);
    insertAtEnd(&head,19);
    insertAtEnd(&head,6);
    insertAtBeginning(&head,9);
    insertAtPosition(&head, 15, 3);
    cout<<"After insertions: ";
    printList(head);

    deleteFromBeginning(&head);
    cout<<"After deleting from beginning: ";
    printList(head);

    deleteFromEnd(&head);
    cout<<"After deleting from end: ";
    printList(head);

    deleteFromPosition(&head, 2);
    cout<<"After deleting from position 2: ";
    printList(head);

    return 0;
}