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
    pair<int , int> dfs(TreeNode *root) {
        if(!root) return {0 , INT_MIN};
        auto left = dfs(root -> left);
        auto right = dfs(root -> right);
        int extend_max = root -> val + max(0 , max(left.first , right.first));
        int curr_max = root -> val + max(0 , left.first) + max(0 , right.first);
        int max_sum = max(curr_max , max(left.second , right.second));
        return {extend_max , max_sum};
    }
    int maxPathSum(TreeNode* root) {
        return dfs(root).second;
    }
};