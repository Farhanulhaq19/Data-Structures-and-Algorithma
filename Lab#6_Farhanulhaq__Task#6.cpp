#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
void insertAtBeginning(Node** head, int newData)
{
    Node* newNode=new Node();
    newNode->data=newData;
    newNode->next=*head;
    newNode->prev=NULL;
    if (*head != NULL) {
        (*head)->prev=newNode;
    }
    *head = newNode;
}

void insertAtEnd(Node** head,int newData)
{
    Node* newNode=new Node();
    Node* last=*head;
    newNode->data=newData;
    newNode->next=NULL;
    if (*head==NULL)
    {
        newNode->prev=NULL;
        *head=newNode;
        return;
    }
    while(last->next !=NULL)
    {
        last=last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data;
        if (node->next != NULL) {
            cout << "->";
        }
        node = node->next;
    }
    cout << "->NULL" << endl;
}
int main() {
    Node* head = NULL;

    insertAtBeginning(&head,6);
    insertAtBeginning(&head,9); 
    insertAtEnd(&head,19);     

    printList(head);

    return 0;
}