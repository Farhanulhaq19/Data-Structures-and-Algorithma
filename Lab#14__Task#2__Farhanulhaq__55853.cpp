#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
private:
    struct Node {
        char data;
        Node* next;
    };
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        clear();
    }

    void push(char item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    char peek() const {
        if (!isEmpty()) {
            return top->data;
        } else {
            cout << "Stack is empty." << endl;
            throw runtime_error("Empty stack");
        }
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

string reverseString(const string& str) {
    Stack stack;
    for (char c : str) {
        stack.push(c);
    }
    string reversed;
    while (!stack.isEmpty()) {
        reversed += stack.peek();
        stack.pop();
    }
    return reversed;
}

int main() {
    string str;
    cout << "Enter a string to reverse: ";
    getline(cin, str);
    string reversed = reverseString(str);
    cout << "Reversed string: " << reversed << endl;
    return 0;
}
