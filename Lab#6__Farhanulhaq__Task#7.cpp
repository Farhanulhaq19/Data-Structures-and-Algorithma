#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
void deleteFromBeginning(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    delete temp;
}
void deleteFromEnd(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }

    delete temp;
}
void deleteFromPosition(Node** head, int position) {
    if (*head==NULL || position <=0) return;

    Node* temp = *head;

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    for (int i = 1;temp !=NULL && i<position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    delete temp;
}
void printList(Node* head) {
    while (head != NULL) {
        cout<<head->data << " ";
        head=head->next;
    }
    cout << endl;
}

int main()
{
    Node* head = new Node{74,NULL,NULL};
    Node* second = new Node{78, head, NULL};
    Node* third = new Node{6,second,NULL};
    Node* fourth = new Node{19,third,NULL};
    Node* fifth = new Node{94,fourth,NULL};

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next = fifth;

    cout << "Original List: ";
    printList(head);
    deleteFromBeginning(&head); 
    deleteFromEnd(&head);      
    deleteFromPosition(&head,2);

    cout << "List after deleting three nodes: ";
    printList(head);

    return 0;
}