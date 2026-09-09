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
    TreeNode *prev = nullptr;
    int sum = 0;
    void dfs(TreeNode *root) {
        if(!root) return;
        if((!root -> left && !root -> right) && prev && prev -> left == root) sum += root -> val;
        prev = root;
        dfs(root -> left);
        dfs(root -> right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return sum;
    }
};