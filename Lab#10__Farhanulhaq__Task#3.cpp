#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* insert(Node* root,int value) {
    if (root ==nullptr) {
        root =new Node();
        root->data =value;
        root->left =root->right = nullptr;
    } else if (value < root->data) {
        root->left =insert(root->left, value);
    } else {
        root->right =insert(root->right, value);
    }
    return root;
}

bool search(Node* root,int value) {
    if (root ==nullptr) return false;
    if (root->data ==value) return true;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}
int main() {
    Node* root =nullptr;
    root =insert(root,50);
    root =insert(root,30);
    root =insert(root,70);
    root =insert(root,20);
    root =insert(root,40);
    root =insert(root,60);
    root =insert(root,80);

    int key;
    cout<<"Enter a value to search in the BST: ";
    cin>>key;

    if (search(root,key)) {
        cout<<key<<" found in the BST." << endl;
    } else {
        cout<<key<<" not found in the BST." << endl;
    }
    return 0;
}