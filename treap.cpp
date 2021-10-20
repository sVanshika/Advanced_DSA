/*
Ques: 
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int priority;
    int key;
    Node* left;
    Node* right;
};

Node* getNewNode(int key, int priority){
    Node* newNode = new Node();
    newNode->priority = priority;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node* ptr){
    if(ptr == NULL)
        return;
    inorder(ptr->left);
    cout << ptr->key << "," << ptr->priority << endl;
    inorder(ptr->right);
}

Node* leftRotation(Node* ptr){
    Node* ptr2 = ptr->right;
    Node* ptr3 = ptr2->left;
    ptr2->left = ptr;
    ptr->right = ptr3;
    return ptr2;
}

Node* rightRotation(Node* ptr){
    Node* ptr2 = ptr->left;
    Node* ptr3 = ptr2->right;
    ptr2->right = ptr;
    ptr->left = ptr3;
    return ptr2;
}

Node* insert(Node* root, int key, int priority){
    // root is null
    if (root == NULL)
        root = getNewNode(key, priority);
    
    // key < root
    else if (key < root->key){
        root->left = insert(root->left, key, priority);
        if (root->left->priority > root->priority)
            root = rightRotation(root);
    }

    // key > root
    else{
        root->right = insert(root->right, key, priority);
        if (root->right->priority > root->priority)
            root = leftRotation(root);
    }
    return root;
}

int main(){
    Node* root = NULL;
    root = insert(root, 43, 3);
    root = insert(root, 14, 25);
    root = insert(root, 35, 99);
    root = insert(root, 86, 47);
    root = insert(root, 3, 80);
    root = insert(root, 1, 53);
    inorder(root);
    return 0;
}