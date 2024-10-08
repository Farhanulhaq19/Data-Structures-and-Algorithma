#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void insertatEnd(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void printList(Node* node) {
    cout << "Linked list elements: " << endl;
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

void findMiddle(Node* head){
    if(head == NULL){
        cout<<"The list is empty."<<endl;
        return;
    }
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    int middle = count / 2;
    temp = head;
    for (int i = 0; i < middle; i++) {
        temp = temp->next;
    }

    cout<<"The middle element is: "<<temp->data<<endl;
}
void reverseList(Node** head)
{
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    Node* head = NULL;
    int n, value;
    cout << "How many values do you want to insert at the list? "<<endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Value " << i + 1 << ": ";
        cin >> value;
        insertatEnd(&head, value);
    }
    cout << "Original Linked list: ";
    printList(head);
    findMiddle(head);  
    reverseList(&head);
    cout << "Reversed Linked list: ";
    printList(head);
    return 0;
}
