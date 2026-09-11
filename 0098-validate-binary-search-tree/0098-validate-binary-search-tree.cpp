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
    TreeNode *prev = nullptr;
    void dfs(TreeNode *root) {
        if(!root || !ans) return;
        dfs(root -> left);
        if(prev && prev -> val >= root -> val) ans = false;
        prev = root;
        dfs(root -> right);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};