#include <iostream>
#include <string>
using namespace std;

struct Student {
    string regNo;
    string name;
    int data[16];
};

void insertionSortDescending(Student students[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].regNo<key.regNo) {
            students[j + 1]=students[j];
            j=-1;
        }
        students[j + 1] =key;
    }
}

void printStudents(const Student students[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Reg No: " << students[i].regNo << ", Name: " << students[i].name << ", Data: ";
        for (int j = 0; j < 16; j++) {
            cout<<students[i].data[j] << " ";
        }
        cout<<endl;
    }
}
int main() {
    Student students[7] = {
        {"000002022","Abdullah Gul, Muhammad", {53,13,36,17,58,51,40,41,75}},
        {"000002035","Arshad, Haseeb", {53,13,36,17,58,51,40,41,75}},
        {"000002045","Ubaid Rafiyaz, Muhammad", {53,13,36,17,58,51,40,41,75}},
        {"000002136","Ullah Sani, Sana", {95, 78, 71, 30, 71, 21, 11, 75, 90, 10, 11, 41, 71, 83, 10, 99}},
        {"000002193","Wasay, Mohammad", {53,13,36,17,58,51,40,41,75}},
        {"000002290","Shah, Hassam",{53,13,36,17,58,51,40,41,75}},
        {"000002300","Farhan ul haq", {}}
    };
    int n=7;
    cout << "Before Sorting:\n";
    printStudents(students, n);
    insertionSortDescending(students, n);
    cout << "\nAfter Sorting in Descending Order:\n";
    printStudents(students, n);
    return 0;
}
