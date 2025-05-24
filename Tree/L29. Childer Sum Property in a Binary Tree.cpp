#include <iostream>
using namespace std;

// Definition for a Binary Tree Node
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Function to change the tree to satisfy the Children Sum Property
void changeTree(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return;

    int child = 0;

    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    // If children's sum is greater or equal, update root
    if (child >= root->data)
        root->data = child;
    else {
        // Else propagate root's data down to its children
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    // Recursively call for left and right subtrees
    changeTree(root->left);
    changeTree(root->right);

    // After recursion, update root's data as the sum of its children's data
    int total = 0;
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;

    if (root->left || root->right)
        root->data = total;
}

// Helper function to create a new node
BinaryTreeNode<int>* newNode(int data) {
    return new BinaryTreeNode<int>(data);
}

// Function to do Inorder Traversal (for checking final tree)
void inorder(BinaryTreeNode<int>* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Example usage
int main() {
    BinaryTreeNode<int>* root = newNode(50);
    root->left = newNode(7);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(1);
    root->right->right = newNode(30);

    cout << "Inorder traversal before change: ";
    inorder(root);
    cout << endl;

    changeTree(root);

    cout << "Inorder traversal after change: ";
    inorder(root);
    cout << endl;

    return 0;
}
