#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data):data(data),next(nullptr),prev(nullptr){}
};
class DoublyLinkedList
{
public:
    Node* head;
    DoublyLinkedList():head(nullptr){}
    void insertAtEnd(int data)
    {
        Node* newNode=new Node(data);
        if (head ==nullptr)
        {
            head=newNode;
            return;
        }
        Node* temp = head;
        while (temp->next !=nullptr)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
    Node* findMiddle()
    {
        if (head==nullptr)
        {
            return nullptr;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast!=nullptr && fast->next !=nullptr)
        {
            slow= slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void printList()
    {
        Node* temp=head;
        while (temp !=nullptr)
        {
            cout<<temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
    }
};
int main()
{
    DoublyLinkedList list;
    // Inserting elements into the list
    list.insertAtEnd(79);
    list.insertAtEnd(6);
    list.insertAtEnd(45);
    list.insertAtEnd(78);
    list.insertAtEnd(19);
    // Printing the list
    list.printList();
    // Finding and printing the middle element
    Node* middle = list.findMiddle();
    if (middle != nullptr)
    {
        cout<<"Middle element is: "<<middle->data<<endl;
    }
    else
    {
        cout<<"The list is empty."<<endl;
    }
    return 0;
}