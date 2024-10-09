#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
//  insertion at the end of list
void insertAtEnd(Node** head, int data) {
    Node* newNode = new Node{data, NULL, NULL};
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp=*head;
    while(temp->next !=NULL) {
        temp=temp->next;
    }
    temp->next =newNode;
    newNode->prev = temp;
}
// Function to check if the list is empty
bool isEmpty(Node* head) {
    return head==NULL;
}
// Function to traverse the list forward
void traverseForward(Node* head)
{
    while(head !=NULL)
    {
        cout<<head->data<< " ";
        head=head->next;
    }
    cout << endl;
}
// Function to traverse the list backward
void traverseBackward(Node* tail)
{
    while(tail !=NULL)
    {
        cout<<tail->data <<" ";
        tail=tail->prev;
    }
    cout<<endl;
}
int main() {
    Node* head=NULL;
    insertAtEnd(&head,45);
    insertAtEnd(&head,87);
    insertAtEnd(&head,9);
    insertAtEnd(&head,19);
    insertAtEnd(&head,78);

    cout<<"Forward Traversal: ";
    traverseForward(head); 

    Node* tail = head;
    while (tail->next !=NULL)tail=tail->next;

    cout<<"Backward Traversal: ";
    traverseBackward(tail);

    return 0;
}
