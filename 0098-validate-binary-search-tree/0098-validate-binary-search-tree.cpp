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
    bool ans = true;
    TreeNode* prev = NULL;
    void inorder(TreeNode * root) {
        if(!ans) return;
        if(!root) return;
        inorder(root -> left);
        if(prev && prev -> val >= root -> val) ans = false;
        prev = root;
        inorder(root -> right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};