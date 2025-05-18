#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isSymmetricHelp(root->left, root->right);
    }

private:
    bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
        if (left == nullptr || right == nullptr)
            return left == right;

        if (left->val != right->val)
            return false;

        return isSymmetricHelp(left->left, right->right)
            && isSymmetricHelp(left->right, right->left);
    }
};

// Helper function to build a symmetric tree for testing
TreeNode* buildSymmetricTree() {
    // Example Symmetric Tree:
    //       1
    //      / \
    //     2   2
    //    / \ / \
    //   3  4 4  3

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right
