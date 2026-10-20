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
    vector<TreeNode*> ans;
    unordered_map<string , int>check;
    string dfs(TreeNode* root) {
        if(!root) return "#";
        auto left = dfs(root -> left) , right = dfs(root -> right);
        string curr = to_string(root -> val) + ',' + left + ',' + right;
        if(check[curr] == 1) ans.push_back(root);
        check[curr]++;
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};