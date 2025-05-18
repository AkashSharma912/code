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
    // Function to get path from root to node with value x
    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        if (!root)
            return false;

        arr.push_back(root->val);

        if (root->val == x)
            return true;

        if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) {
            return true;
        }

        arr.pop_back();  // remove current node if not in path
        return false;
    }

    // Function to solve: find path from root to B
    vector<int> solve(TreeNode* A, int B) {
        vector<int> arr;
        if (A == nullptr)
            return arr;

        getPath(A, arr, B);
        return arr;
    }
};

// Helper function to build a sample tree for testing
TreeNode* buildSampleTree() {
    // Example Tree:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    Solution sol;

    int target = 5;
    vector<int> path = sol.solve(root, target);

    cout << "Path from root to node " << target << ": ";
    for (int val : path)
        cout << val << " ";
    cout << endl;

    return 0;
}
