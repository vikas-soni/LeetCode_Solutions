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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // idea is that every node in the tree, we will look for p and q in its left branch and right branch
        // if one is present in left branch and one in the right, then the node is common ancestor.
        // else depending on which branch both are present, we will move to that branch.
        // base case
        // if either of p or q matches the root, then we return the root which indicates that either p or q is present
        if((root==nullptr)||(root==p)||(root==q))
            return root;
        
        // look for the given nodes in left and right of the current node
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        
        // if we got both the nodes, that means one of p or q is in the left and other one is in the right
        if(left && right)
            return root;
        // otherwise which ever of left or right node is presnet, return it
        if(left!=nullptr)
            return left;
        else
            return right;
    }
};