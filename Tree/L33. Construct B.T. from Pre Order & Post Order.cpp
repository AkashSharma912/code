#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to recursively build the tree from preorder and inorder
TreeNode* buildTreeHelper(vector<int>& preOrder, int preStart, int preEnd,
                          vector<int>& inOrder, int inStart, int inEnd,
                          map<int, int>& inMap)
{
    // Base case: if there are no elements to construct the tree
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;

    // Create the root node using the first element of preorder
    TreeNode* root = new TreeNode(preOrder[preStart]);

    // Find the root value's index in inorder array
    int inRoot = inMap[root->val];

    // Calculate number of nodes in the left subtree
    int numsLeft = inRoot - inStart;

    // Recursively build the left subtree
    root->left = buildTreeHelper(preOrder, preStart + 1, preStart + numsLeft,
                                 inOrder, inStart, inRoot - 1, inMap);

    // Recursively build the right subtree
    root->right = buildTreeHelper(preOrder, preStart + numsLeft + 1, preEnd,
                                  inOrder, inRoot + 1, inEnd, inMap);

    // Return the constructed subtree rooted at 'root'
    return root;
}

// Main function to build the tree from preorder and inorder traversals
TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder)
{
    // Map to store the index of each value in inorder traversal for fast lookup
    map<int, int> inMap;
    for (int i = 0; i < inOrder.size(); i++)
    {
        inMap[inOrder[i]] = i;
    }

    // Call the recursive helper function to build the entire tree
    return buildTreeHelper(preOrder, 0, preOrder.size() - 1,
                           inOrder, 0, inOrder.size() - 1, inMap);
}
