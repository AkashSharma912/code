#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to serialize a tree into a string
string Serializer(TreeNode* root)
{
    if (!root)
        return "";

    string s = "";
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* curNode = q.front();
        q.pop();

        if (curNode == NULL)
            s.append("#,");
        else {
            s.append(to_string(curNode->val) + ',');
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }

    return s;
}

// Function to deserialize a string back into a tree
TreeNode* deserialize(string data)
{
    if (data.size() == 0)
        return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ','); // first value is root

    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* curNode = q.front();
        q.pop();

        // Left child
        if (getline(s, str, ','))
        {
            if (str == "#")
                curNode->left = NULL;
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                curNode->left = leftNode;
                q.push(leftNode);
            }
        }

        // Right child
        if (getline(s, str, ','))
        {
            if (str == "#")
                curNode->right = NULL;
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                curNode->right = rightNode;
                q.push(rightNode);
            }
        }
    }

    return root;
}
