class Solution {
public:
    void f(TreeNode* curr){
        TreeNode* prev=NULL;
        while(curr!=NULL)
        {
            if(curr->left!=NULL){
                prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }


    void flatten(TreeNode* root) {
        f(root);
    }