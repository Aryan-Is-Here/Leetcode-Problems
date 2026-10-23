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
    int sum = 0;
    void dfs(TreeNode *root , string s) {
        if(!root) return;
        if(!root -> left && !root -> right) {
            s = s + to_string(root -> val);
            int x = stoi(s);
            sum += x;
            return;
        }
        s = s + to_string(root -> val);
        dfs(root -> left , s);
        dfs(root -> right , s);
    }


    int sumNumbers(TreeNode* root) {
        dfs(root , "");
        return sum;
    }
};