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

// Helper function to recursively build tree from inorder and postorder
TreeNode* buildTreePostIn(vector<int>& inOrder, int is, int ie,
                          vector<int>& postOrder, int ps, int pe,
                          map<int, int>& hm)
{
    // Base case: no elements to process
    if (is > ie || ps > pe)
        return nullptr;

    // Create root from last element of postorder
    TreeNode* root = new TreeNode(postOrder[pe]);

    // Find root's index in inorder using hashmap
    int inRoot = hm[root->val];

    // Number of elements in left subtree
    int numsLeft = inRoot - is;

    // Recursively build left subtree
    root->left = buildTreePostIn(inOrder, is, inRoot - 1,
                                 postOrder, ps, ps + numsLeft - 1, hm);

    // Recursively build right subtree
    root->right = buildTreePostIn(inOrder, inRoot + 1, ie,
                                  postOrder, ps + numsLeft, pe - 1, hm);

    // Return root node
    return root;
}

// Main function to build tree from inorder and postorder traversals
TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder)
{
    if (inOrder.size() != postOrder.size())
        return nullptr;

    // Map to store value->index positions from inorder traversal
    map<int, int> hm;
    for (int i = 0; i < inOrder.size(); i++)
        hm[inOrder[i]] = i;

    // Call recursive helper with initial indices
    return buildTreePostIn(inOrder, 0, inOrder.size() - 1,
                           postOrder, 0, postOrder.size() - 1, hm);
}
