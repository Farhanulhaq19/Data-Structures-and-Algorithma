#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val)
    {
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};
class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList()
    {
        head=nullptr;
        tail=nullptr;
    }
    void insert(int val)
    {
        Node* newNode=new Node(val);
        if (head==nullptr) {
            head=tail=newNode;
        } else {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    void forwardTraversal()
    {
        Node* temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->data << " ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void backwardTraversal()
    {
        Node* temp=tail;
        while(temp!=nullptr) {
            cout<<temp->data << " ";
            temp=temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList List;
    List.insert(8);
    List.insert(29);
    List.insert(19);
    List.insert(9);
    List.insert(24);
    cout << "Forward Traversal: ";
    List.forwardTraversal();

    cout << "Backward Traversal: ";
    List.backwardTraversal();

    return 0;
}