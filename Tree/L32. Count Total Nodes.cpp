#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find height by going left
int findHeightLeft(TreeNode* node)
{
    int hght = 0;
    while (node)
    {
        hght++;
        node = node->left;
    }
    return hght;
}

// Function to find height by going right
int findHeightRight(TreeNode* node)
{
    int hght = 0;
    while (node)
    {
        hght++;
        node = node->right;
    }
    return hght;
}

// Function to count nodes in a Complete Binary Tree
int countNodes(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if (lh == rh)
        return (1 << lh) - 1; // 2^height - 1

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Driver function to test the code
int main()
{
    // Creating the following Complete Binary Tree:
    //         1
    //       /   \
    //      2     3
    //     / \   /
    //    4   5 6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // Count the total number of nodes
    int totalNodes = countNodes(root);
    cout << "Total number of nodes in the tree: " << totalNodes << endl;

    return 0;
}
