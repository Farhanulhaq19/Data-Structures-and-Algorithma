#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    int regno;
    string name;
    float cgpa;

public:
    Student():regno(0),name(""),cgpa(0.0) {}
    void input()
    {
        cout << "Enter Registration No: ";
        cin >> regno;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin,name);
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void output() const {
        cout<<"Registration No: "<<regno<<",Name: " <<name<<",CGPA: "<<cgpa<<endl;
    }
};
class Stack
{
private:
    Student* arr;
    int top;
    int size;

public:
    Stack(int n):size(n),top(-1) {
        arr=new Student[size];
    }
    ~Stack()
    {
        delete[] arr;
    }
    void push() {
        if (top >= size - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        Student s;
        s.input();
        arr[++top] = s;
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        arr[top--].output();
    }
};
int main()
{
    int n;
    cout<<"Enter the size of the stack: ";
    cin>>n;
    Stack stack(n);
    int choice;
    do {
        cout<<"1.Push Student\n2.Pop Student\n3. Exit\nEnter choice: ";
        cin>>choice;
        switch (choice) {
            case 1: stack.push(); break;
            case 2: stack.pop(); break;
            case 3: cout<<"Exiting..."<<endl;break;
            default: cout<<"Invalid choice!" << endl;
        }
    } while (choice !=3);
    return 0;
}