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
Node* insert(Node* root, int value) {
    if (root ==nullptr) {
        return createNode(value);
    }
    if (value <root->data) {
        root->left =insert(root->left, value);
    } else {
        root->right =insert(root->right, value);
    }
    return root;
}
void inOrderTraversal(Node* root) {
    if (root ==nullptr) return;
    inOrderTraversal(root->left);
    cout<<root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if (root ==nullptr) return;
    cout<<root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root ==nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data << " ";
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

    cout<<"In-order traversal of the BST: ";
    inOrderTraversal(root);
    cout<<endl;
    cout<<"Pre-order traversal of the BST: ";
    preOrderTraversal(root);
    cout<<endl;
    cout<<"Post-order traversal of the BST: ";
    postOrderTraversal(root);
    cout<<endl;
    return 0;
}