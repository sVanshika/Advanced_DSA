/*
Ques: 
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;     
};

Node* getNewNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* ptr, int value){
    // empty tree
    if(ptr == NULL) 
        ptr = getNewNode(value);
    // insert in left subtree
    else if(value < ptr->data) 
        ptr->left = insert(ptr->left, value);
    // insert in right subtree
    else    
        ptr->right = insert(ptr->right, value);
    return ptr;
}

bool search(Node* ptr, int value){
    if(ptr == NULL)
        return false;
    if(ptr->data == value)
        return true;
    else if(value < ptr->data)
        return search(ptr->left, value);
    else 
        return search(ptr->right, value);
}

// Node* delete(Node* ptr, int value){
//     // root node
//     if(ptr->left == NULL && ptr->right == NULL)
//         return NULL;

//     if(ptr->data == value){
//         // leaf node
//         if(ptr->left == NULL && ptr->right == NULL)
//             ptr = NULL;
        
//         // node with 1 child - left
//         else if(ptr->left != NULL && ptr->right == NULL){
//             ptr->data = ptr->left->data;
//             ptr->left = ptr->left->left;
//         }
//         // node with 2 child
//     }
// }

void inorder(Node* ptr){
    if(ptr == NULL)
        return;
    inorder(ptr->left);
    cout << ptr->data << " ";
    inorder(ptr->right);
}

void preorder(Node* ptr){
    if(ptr == NULL)
        return;
    cout << ptr->data << " ";
    preorder(ptr->left);
    preorder(ptr->right);
}

void postorder(Node* ptr){
    if(ptr == NULL)
        return;
    preorder(ptr->left);
    preorder(ptr->right);
    cout << ptr->data << " ";
}

int main(){
    Node* root = NULL;

    int values[6] = {12, 10, 14, 16, 11, 9};
    for(int i: values)
        root = insert(root, i);

    inorder(root);

    cout << "\nsearch 15: " << search(root, 15);
    
    cout << endl;
    
    return 0;
}