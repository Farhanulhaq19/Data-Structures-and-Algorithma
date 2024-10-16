#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
    int capacity;

public:
    Queue(int cap) : front(nullptr), rear(nullptr), size(0), capacity(cap) {}

    bool isFull() const {
        return size == capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
        } else {
            Node* newNode = new Node(value);
            if (isEmpty()) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        } else {
            Node* temp = front;
            int value = temp->data;
            front = front->next;
            delete temp;
            size--;
            return value;
        }
    }
};

int main() {
    Queue q1(5), q2(5);
    int choice, value;

    do {
        cout << "\n1. Enqueue to Queue 1\n2. Dequeue from Queue 1 and Enqueue to Queue 2\n3. Dequeue from Queue 2\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue in Queue 1: ";
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            value = q1.dequeue();
            if (value != -1) {
                q2.enqueue(value);
            }
            break;
        case 3:
            q2.dequeue();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
