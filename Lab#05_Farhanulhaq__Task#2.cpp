#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void addNode(Node** head, int data) {
    Node* newNode = new Node{data, NULL};
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head; 
    Node* fast = head; 
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
bool isEmpty(Node* head) {
    return head == NULL;
}
void printList(Node* head) {
    if (isEmpty(head)) {
        cout<<"The list is empty!"<<endl;
        return;
    }
    while (head !=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout << endl;
}

int main() {
    Node* head=NULL;

    if (isEmpty(head))
    {
        cout<<"The list is initially empty."<<endl; 
    }
    
    addNode(&head,24);
    addNode(&head,6);
    addNode(&head, 90);
    addNode(&head,19);
    addNode(&head,78);

    cout << "Linked List: ";
    printList(head); 

    Node* middle = findMiddle(head);
    if (middle != NULL) {
        cout<<"Middle element: "<<middle->data<<endl;
    } else
    {
        cout<<"The list is empty!"<<endl;
    }

    return 0;
}