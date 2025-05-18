    #include <bits/stdc++.h>
    using namespace std;

    // Node structure
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = right = NULL;
        }
    };

    // Solution class with topView function
    class Solution {
    public:
        vector<int> topView(Node* root) {
            vector<int> ans;
            if (root == NULL)
                return ans;

            map<int, int> mp;
            queue<pair<Node*, int>> q;
            q.push({root, 0});

            while (!q.empty()) {
                auto it = q.front();
                q.pop();
                Node* node = it.first;
                int line = it.second;

                if (mp.find(line) == mp.end())
                    mp[line] = node->data;

                if (node->left != NULL)
                    q.push({node->left, line - 1});
                if (node->right != NULL)
                    q.push({node->right, line + 1});
            }

            for (auto it : mp) {
                ans.push_back(it.second);
            }
            return ans;
        }
    };

    // Utility function to build a simple binary tree for testing
    Node* buildSampleTree() {
        /*
            1
            / \
        2   3
            \  / \
            4 5  6
        */
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->right = new Node(4);
        root->right->left = new Node(5);
        root->right->right = new Node(6);
        return root;
    }

    // Main function
    int main() {
        Node* root = buildSampleTree();
        Solution sol;
        vector<int> res = sol.topView(root);

        cout << "Top View of the Binary Tree: ";
        for (int val : res) {
            cout << val << " ";
        }
        cout << endl;

        return 0;
    }
