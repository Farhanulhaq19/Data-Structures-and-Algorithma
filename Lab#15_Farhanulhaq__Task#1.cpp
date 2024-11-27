#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class LinkedList
{
public:
    LinkedList() : head(nullptr) {}

    void createList(int n)
    {
        Node* temp=nullptr;
        for (int i = 0;i<n;i++)
        {
            int value;
            cout << "Enter value for node " <<(i + 1)<< ": ";
            cin >> value;
            Node* newNode=new Node{value, nullptr};
            if (head == nullptr) {
                head = newNode;
            } else {
                temp->next=newNode;
            }
            temp = newNode;
        }
    }
    void insertingNode(int value)
    {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
        }
        else
    {
            Node* temp=head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void deleteNode(int value) 
    {
        if (head == nullptr)
        {
            cout<<"List is empty.\n";
            return;
        }
        if (head->data==value)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
            cout<<"Node with value "<<value<<" deleted.\n";
            return;
        }

        Node* current=head;
        Node* previous=nullptr;
        while (current !=nullptr && current->data != value) {
            previous=current;
            current=current->next;
        }

        if (current == nullptr)
        {
            cout<<"Node with value "<<value<<"not found.\n";
            return;
        }

        previous->next=current->next;
        delete current;
        cout<<"Node with value "<<value<< " deleted.\n";
    }
    void searchNode(int value)
    {
        Node* temp=head;
        while (temp!=nullptr) {
            if (temp->data==value)
            {
                cout<<"Node with value "<<value<< " found.\n";
                return;
            }
            temp = temp->next;
        }
        cout<<"Node with value " <<value<< " not found.\n";
    }

    void displayList()
    {
        Node* temp=head;
        if (temp==nullptr)
        {
            cout<<"List is empty.\n";
            return;
        }

        cout<<"Linked List: ";
        while(temp != nullptr)
        {
            cout<<temp->data << " ";
            temp=temp->next;
        }
        cout<< "\n";
    }
    ~LinkedList()
    {
        Node* temp;
        while (head!=nullptr)
        {
            temp=head;
            head=head->next;
            delete temp;
        }
    }
    // checking if the list is empty
    bool isEmpty() const {
        return head == nullptr;
    }
private:
    Node* head;
};
int main()
{
    LinkedList list;
    list.createList(5);
    list.displayList();
    int value;
    // Inserting a node
    cout << "Enter value to insert: ";
    cin >> value;
    list.insertingNode(value);
    list.displayList();
    // Deleting a node
    cout << "Enter value to delete: ";
    cin >> value;
    list.deleteNode(value);
    list.displayList();
    // Searching for node
    cout << "Enter value to search: ";
    cin >> value;
    list.searchNode(value);
    return 0;
}