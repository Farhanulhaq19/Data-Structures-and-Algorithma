#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode =new Node();
    newNode->data =value;
    newNode->left =newNode->right;
    newNode->right =nullptr;
    return newNode;
}
Node* insert(Node* root,int value) {
    if (root ==nullptr) {
        return createNode(value);
    }
    if (value<root->data) {
        root->left=insert(root->left, value);
    } else {
        root->right=insert(root->right, value);
    }
    return root;
}
Node* findMin(Node* root) {
    while (root && root->left !=nullptr) {
        root=root->left;
    }
    return root;
}
Node* deleteNode(Node* root,int value) {
    if (root == nullptr) return root;
    if (value < root->data) {
        root->left =deleteNode(root->left, value);
    } else if (value>root->data) {
        root->right =deleteNode(root->right, value);
    } else {
        if (root->left ==nullptr) {
            Node* temp =root->right;
            delete root;
            return temp;
        } else if (root->right ==nullptr) {
            Node* temp =root->left;
            delete root;
            return temp;
        }
        Node* temp =findMin(root->right);
        root->data =temp->data;
        root->right =deleteNode(root->right, temp->data);
    }
    return root;
}
void inOrderTraversal(Node* root) {
    if (root ==nullptr) return;
    inOrderTraversal(root->left);
    cout<<root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    root =insert(root,50);
    root =insert(root,30);
    root =insert(root,70);
    root =insert(root,20);
    root =insert(root,40);
    root =insert(root,60);
    root =insert(root,80);

    cout<<"Initial in-order traversal of the BST: ";
    inOrderTraversal(root);
    cout<<endl;

    int value;
    cout<<"Enter a value to delete from the BST: ";
    cin>>value;

    root =deleteNode(root, value);
    cout<<"In-order traversal after deletion: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}