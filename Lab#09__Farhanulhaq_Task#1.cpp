#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int per_id;
    string per_name;
    int per_age;

public:
    Person() : per_id(0), per_name(""), per_age(0) {}

    void input() {
        cout << "Enter Person ID: ";
        cin >> per_id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, per_name);
        cout << "Enter Age: ";
        cin >> per_age;
    }

    void output() const {
        cout << "ID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << endl;
    }
};

struct Node {
    Person person;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void addQueue() {
        Node* newNode = new Node();
        newNode->person.input();
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void removeQueue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        temp->person.output();
        delete temp;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    Queue queue;
    int choice;
    do {
        cout << "1. Add Person to Queue\n2. Remove Person from Queue\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: queue.addQueue(); break;
            case 2: queue.removeQueue(); break;
            case 3: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}