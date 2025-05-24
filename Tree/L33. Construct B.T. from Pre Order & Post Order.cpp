#include <iostream>
<<<<<<< HEAD
#include <vector>
#include <map>
using namespace std;

// Definition for a binary tree node
=======
using namespace std;

// Definition for a binary tree node.
>>>>>>> 5453007b96322afb2be5926752e157a1c54f6fd0
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

<<<<<<< HEAD
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
=======
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
>>>>>>> 5453007b96322afb2be5926752e157a1c54f6fd0
}
