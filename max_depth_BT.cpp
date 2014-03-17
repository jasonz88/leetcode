/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(NULL == root)
        {
            return 0;
        }
        /*if(root->left && NULL == root->right)
        {
            return maxDepth(root->left)+1;
        }
        if(root->right && NULL == root->left)
        {
            return maxDepth(root->right)+1;
        }*/
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
