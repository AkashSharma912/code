#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if (!root)
        return 0;

    int ans = 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        unsigned long long mmin = q.front().second; // Minimum index at current level
        unsigned long long first, last;

        for (int i = 0; i < size; i++) {
            unsigned long long cur_id = q.front().second - mmin; // Normalize to avoid overflow
            TreeNode* node = q.front().first;
            q.pop();

            if (i == 0)
                first = cur_id;
            if (i == size - 1)
                last = cur_id;

            if (node->left)
                q.push({node->left, cur_id * 2 + 1});
            if (node->right)
                q.push({node->right, cur_id * 2 + 2});
        }

        ans = max(ans, (int)(last - first + 1));
    }

    return ans;
}

// Helper function to create a new node
TreeNode* newNode(int data) {
    return new TreeNode(data);
}

// Example usage
int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(2);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->right = newNode(9);

    cout << "Maximum width of binary tree: " << widthOfBinaryTree(root) << endl;

    return 0;
}
