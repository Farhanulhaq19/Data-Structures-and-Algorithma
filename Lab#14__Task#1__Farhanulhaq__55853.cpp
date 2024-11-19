#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;

    Node(int value) {
        next = nullptr;
        data = value;
    }
};

class Queue {
    Node* front;
    Node* rear;
    int size;
    int maxSize;

public:
    Queue(int capacity) {
        front = rear = nullptr;
        size = 0;
        maxSize = capacity;
    }

    bool isFull() {
        return size == maxSize;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return -1;
        }
        Node* temp = front;
        int value = front->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    int count() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Queue cleared." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue contents: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();
    cout << "Queue size: " << q.count() << endl;

    q.enqueue(60);

    cout << "Dequeuing: " << q.dequeue() << endl;
    q.display();

    q.clear();
    q.display();

    return 0;
}
