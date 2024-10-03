#include <iostream>
using namespace std;
struct Node {
    int data;   
    Node* next;
};
class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    void addNodeToEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (isEmpty())
        {
            head=newNode;
        }
        else
        {
            Node* temp = head; 
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void findMiddle()
    {
        if (isEmpty())
        {
            cout << "List is empty. No middle element.\n";
            return;
        }

        Node* slow=head;
        Node* fast=head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow=slow->next;          
            fast=fast->next->next;     
        }
        cout << "Middle element: " << slow->data << "\n";
    }
    void displayList()
    {
        if (isEmpty())
        {
            cout<<"List is empty.\n";
            return;
        }
        Node* temp=head;
        cout<< "Linked List: ";
        while(temp !=nullptr)
        {
            cout<<temp->data << " ";
            temp=temp->next; 
        }
        cout << "\n";
    }
    bool isEmpty() const
    {
        return head==nullptr;
    }
    ~LinkedList()
    {
        Node* temp;
        while(head !=nullptr)
        {
            temp=head;
            head=head->next; 
            delete temp;
        }
    }
private:
    Node* head;
};
int main() {
    LinkedList list;
    list.addNodeToEnd(9);
    list.addNodeToEnd(19);
    list.addNodeToEnd(29);
    list.addNodeToEnd(16);
    list.addNodeToEnd(24);
    list.addNodeToEnd(78);
    // Displaying the linked list
    list.displayList();
    // Finding the middle element
    list.findMiddle();
    return 0;
}