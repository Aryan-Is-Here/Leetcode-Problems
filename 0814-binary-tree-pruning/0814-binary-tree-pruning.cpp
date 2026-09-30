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
    bool one = false;
    bool dfs(TreeNode *root) {
        if(!root) return true;
        bool l = dfs(root -> left);
        bool r = dfs(root -> right);
        if(l) root -> left = nullptr;
        if(r) root -> right = nullptr;
        if(root -> val == 1) one = true;
        return (l && r && root -> val == 0);
    }
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        if(!one) return nullptr;
        return root;
    }
};