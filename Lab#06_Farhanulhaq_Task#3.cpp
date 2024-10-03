#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() : head(nullptr) {}
    void deleteFromEmptyList() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
    }

    void insertAtPosition(int data,int position){
        Node* newNode=new Node(data);
        if (position <= 0) {
            cout<<"Invalid position."<<endl;
            return;
        }

        if (head ==nullptr && position > 1)
        {
            cout << "Position is greater than the length of the list." << endl;
            return;
        }
        if (position==1)
        {
            newNode->next=head;
            if (head != nullptr)
            {
                head->prev=newNode;
            }
            head=newNode;
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count<position-1)
        {
            temp = temp->next;
            count++;
        }

        if (temp==nullptr)
        {
            cout<<"Position is greater than the length of the list."<<endl;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next=newNode;
    }
    void deleteAllNodes()
    {
        while (head != nullptr)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        cout<<"All nodes deleted."<<endl;
    }

    void deleteFurther() {
        if (head == nullptr) {
            cout<<"List is empty. Cannot delete further."<<endl;
            return;
        }
    }
};
int main() {
    DoublyLinkedList list;
    // Deleting from an empty list
    list.deleteFromEmptyList();
    // Inserting at a position greater than the length of the list
    list.insertAtPosition(5,10);
    // Adding some node to the list
    list.insertAtPosition(1,1);
    list.insertAtPosition(2,2);
    list.insertAtPosition(3,3);
    //deleting all of the nodes
    list.deleteAllNodes();
    list.deleteFurther();
    return 0;
}