#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void insertAtBeginning(Node** head, int data)
{
    Node* newNode = new Node{data, NULL};
    if (*head==NULL) {
        *head=newNode;
        newNode->next = *head;
        return;
    }
    Node* temp=*head;
    while(temp->next != *head) {
        temp=temp->next;
    }
    newNode->next=*head;
    temp->next=newNode;
    *head=newNode;
}

void traverseCircularList(Node* head) {
    if (head==NULL) {
        cout<<"List is empty." << endl;
        return;
    }
    Node* temp=head;
    do
    {
        cout<<temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = NULL;
    insertAtBeginning(&head,478);
    insertAtBeginning(&head,71);
    insertAtBeginning(&head,1);

    cout<<"Circular Linked List: ";
    traverseCircularList(head);

    return 0;
}