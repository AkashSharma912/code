#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }

private:
    void recursion(TreeNode* root, int level, vector<int>& res) {
        if (root == nullptr)
            return;

        if (res.size() == level)
            res.push_back(root->val);

        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }
};

// Helper function to build a simple tree for testing
TreeNode* buildSampleTree() {
    // Example Tree:
    //      1
    //     / \
    //    2   3
    //     \    \
    //      5    4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    return root;
}

int main() {
    TreeNode* root = buildSampleTree();

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
