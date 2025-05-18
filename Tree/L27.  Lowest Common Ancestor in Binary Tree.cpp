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
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);

        if (left == nullptr)
            return right;
        else if (right == nullptr)
            return left;
        else
            return root;
    }
};

// Helper function to build a sample tree for testing
TreeNode* buildSampleTree() {
    // Example Tree:
    //      3
    //     / \
    //    5   1
    //   / \  / \
    //  6  2 0  8
    //    / \
    //   7   4

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    return root;
}

// Function to find a node by value (for testing)
TreeNode* findNode(TreeNode* root, int val) {
    if (!root)
        return nullptr;
    if (root->val == val)
        return root;
    TreeNode* left = findNode(root->left, val);
    if (left)
        return left;
    return findNode(root->right, val);
}

int main() {
    TreeNode* root = buildSampleTree();
    Solution sol;

    // Find nodes with values 5 and 1
    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 1);

    TreeNode* lca = sol.LCA(root, p, q);

    if (lca)
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
