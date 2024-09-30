#include <iostream>
using namespace std;
struct Node
{
    int data;   
    Node* next; 
};
class LinkedList
{
public:
    LinkedList():head(nullptr) {}
    void addNodetoEnd(int value)
    {
        Node* newNode=new Node{value,nullptr};
        if(isEmpty())
        {
            head=newNode;
        }
        else
        {
            Node* temp=head;
            while (temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void reverseList()
    {
        if (isEmpty())
        {
            cout << "List is empty. Cannot reverse.\n";
            return;
        }
        Node* previous=nullptr;
        Node* current=head;
        Node* next=nullptr;
        while (current !=nullptr) {
            next=current->next;
            current->next=previous;
            previous=current;    
            current=next;        
        }
        head = previous;
    }
    void displayList()
    {
        if (isEmpty())
        {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
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
        while(head!=nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;       
        }
    }
private:
    Node* head;
};
int main() {
    LinkedList list;
    list.addNodetoEnd(9);
    list.addNodetoEnd(19);
    list.addNodetoEnd(29);
    list.addNodetoEnd(16);
    list.addNodetoEnd(24);
    // Displaying the original list
    cout << "Original ";
    list.displayList();
    // Reversing the list
    list.reverseList();
    // Display the reversed list
    cout << "Reversed ";
    list.displayList();
    return 0;
}