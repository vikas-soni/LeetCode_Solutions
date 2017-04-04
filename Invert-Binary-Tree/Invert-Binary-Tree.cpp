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
    TreeNode* invertTree(TreeNode* root) {
        // most of the tree problems are solved with the recursion
        // here we simply need to do a depth traversal and during our traversal swap left and right nodes
        // of tree
        if(root == nullptr)
            return nullptr;
        // simply do a depth traversal
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        // once we have left and right node, swap them
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};