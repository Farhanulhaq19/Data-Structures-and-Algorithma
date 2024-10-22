#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode =new Node();
    newNode->data =value;
    newNode->left =newNode->right = nullptr;
    return newNode;
}
Node* insert(Node* root,int value) {
    if (root ==nullptr) {
        return createNode(value);
    }
    if (value<root->data) {
        root->left =insert(root->left, value);
    } else {
        root->right =insert(root->right, value);
    }
    return root;
}
void inOrderTraversal(Node* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root) {
    if (root==nullptr) return;
    cout<<root->data<< " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root==nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data << " ";
}
int main() {
    Node* root =nullptr;
    int value;
    char choice;
    do {
        cout<<"Enter a value to insert into the BST: ";
        cin>>value;
        root=insert(root, value);

        cout<<"Do you want to insert another value? (y/n): ";
        cin>>choice;
    } while(choice=='y'||choice=='Y');

    cout<<"In-order traversal: ";
    inOrderTraversal(root);
    cout<<"\nPre-order traversal: ";
    preOrderTraversal(root);
    cout<<"\nPost-order traversal: ";
    postOrderTraversal(root);
    cout<<endl;

    return 0;
}