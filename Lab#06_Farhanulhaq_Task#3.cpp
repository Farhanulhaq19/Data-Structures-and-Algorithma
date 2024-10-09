#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
};
void insertAtEnd(Node** head, int data)
{
    Node* newNode = new Node{data,NULL,NULL};
    if (*head==NULL)
    {
        *head=newNode;
        return;
    }
    Node* temp=*head;
    while (temp->next !=NULL)
    {
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insertAtPosition(Node** head, int data, int position)
{
    Node* newNode = new Node{data,NULL,NULL};

    if (position <= 0)
    { 
        cout<<"Invalid position for insertion!"<<endl;
        delete newNode; 
        return;
    }
    if (*head==NULL && position> 1) {
        cout<<"List is empty. Inserting at position 1."<<endl;
        *head=newNode;
        return;
    }
    if (position==1)
    { 
        newNode->next=*head;
        if (*head !=NULL)
        {
            (*head)->prev= newNode;
        }
        *head =newNode;
        return;
    }
    Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Position exceeds the length of the list. Inserting at the end." << endl;
        insertAtEnd(head, data);
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteFromBeginning(Node** head)
{
    if (*head == NULL) {
        cout << "List is empty. Cannot delete from beginning." << endl;
        return; 
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    delete temp;
}
void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        cout << "List is empty. Cannot delete from end." << endl;
        return; 
    }
    if ((*head)->next == NULL)
    {
        delete *head;
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    delete temp;
    temp->prev->next = NULL;
}
void deleteFromPosition(Node** head, int position)
{
    if (*head == NULL) {
        cout << "List is empty. Cannot delete from position " << position << "." << endl;
        return;
    }
    if (position <= 0) {
        cout << "Invalid position for deletion!" << endl;
        return;
    }
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = *head;
    for (int i=1;temp !=NULL && i<position;i++) {
        temp = temp->next;
    }
    if (temp == NULL) { 
        cout <<"Position"<< position <<"exceeds the length of the list. No deletion performed."<<endl;
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next=temp->next;
    }
    if (temp->next !=NULL)
    {
        temp->next->prev=temp->prev;
    }
    delete temp;
}
bool isEmpty(Node* head) {
    return head== NULL; 
}
void traverseForward(Node* head) {
    while(head != NULL) {
        cout<< head->data << " ";
        head= head->next;
    }
    cout <<endl;
}
void traverseBackward(Node* tail) {
    while (tail !=NULL) {
        cout<<tail->data<<" ";
        tail=tail->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    cout << "Trying to delete from an empty list:" << endl;
    deleteFromBeginning(&head);

    insertAtPosition(&head,7,1);
    insertAtPosition(&head,9,2);
    insertAtPosition(&head,4,3);
    insertAtPosition(&head,98,4);
    insertAtPosition(&head,478,5);

    cout<<"Current list after insertions: ";
    traverseForward(head); 

    insertAtPosition(&head, 60, 10);

    cout<<"List after attempting to insert at invalid position: ";
    traverseForward(head);

    deleteFromBeginning(&head); 
    deleteFromBeginning(&head); 
    deleteFromBeginning(&head); 
    deleteFromBeginning(&head); 
    deleteFromBeginning(&head); 
    cout<<"List after deleting all nodes: ";
    traverseForward(head);

    deleteFromBeginning(&head);

    return 0;
}