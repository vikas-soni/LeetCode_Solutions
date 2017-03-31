/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // idea is to recursively get the depth of left tree and right tree and choose max each time
        // end condition
        if(root == nullptr)
            return 0;
        int l_depth = maxDepth(root->left);
        int r_depth = maxDepth(root->right);
        if(l_depth > r_depth)
            return l_depth+1;
        else
            return r_depth+1;
    }
};