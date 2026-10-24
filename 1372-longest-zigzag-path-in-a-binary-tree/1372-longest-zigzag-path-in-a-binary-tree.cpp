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
    int maxcount = 0;
    pair<int , int> dfs(TreeNode* root) {
        if(!root) return {-1 , -1};
        auto l = dfs(root -> left) , r = dfs(root -> right);
        maxcount = max(maxcount , max(l.second , r.first) + 1);
        return {l.second + 1 , r.first + 1};
        
    }

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return maxcount;
    }
};