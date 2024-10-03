#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList():head(nullptr),tail(nullptr){}
    void insertAtBeginning(int val) 
    {
        Node* newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        printList();
    }

    void insertAtEnd(int val)
    {
        Node* newNode = new Node(val);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        printList();
    }

    void insertAtPosition(int val, int pos)
    {
        if (pos<= 0) {
            cout<<"Invalid position!"<< endl;
            return;
        }
        if (pos==1)
        {
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1;i++)
        {
            temp=temp->next;
        }
        if (!temp) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        if (!newNode->next) {
            tail = newNode;
        }
        printList();
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        printList();
    }

    void deleteFromEnd() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp=tail;
        tail=tail->prev;
        if (tail)
        {
            tail->next=nullptr;
        } else 
        {
            head=nullptr;
        }
        delete temp;
        printList();
    }

    void deleteFromPosition(int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1)
        {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos; ++i)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "Position out of bounds!" << endl;
            return;
        }
        if (temp->prev)
        {
            temp->prev->next = temp->next;
        }
        if (temp->next)
        {
            temp->next->prev = temp->prev;
        }
        if (temp == tail)
        {
            tail = temp->prev;
        }
        delete temp;
        printList();
    }
    bool isEmpty() {
    return head == nullptr;
}

    void printList()
    {
        Node* temp=head;
        while (temp)
        {
            cout<<temp->data<< " ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    DoublyLinkedList List;
    List.insertAtBeginning(8);
    List.insertAtEnd(5);
    List.insertAtBeginning(7);
    List.insertAtEnd(45);
    List.insertAtPosition(78, 1); 
    List.insertAtPosition(30, 6);
    
    // Deletion in the List
    List.deleteFromBeginning(); 
    List.deleteFromEnd(); 
    List.deleteFromPosition(2); 
    List.printList();
    
    return 0;
}