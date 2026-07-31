/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev;
    void inorder(TreeNode * root) {
        if(!root) return;
        inorder(root -> left);
        root -> left = NULL;
        prev -> right = root;
        prev = root;
        inorder(root -> right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        prev = dummy;
        inorder(root);
        prev -> right = NULL;
        return dummy -> right;
    }
};