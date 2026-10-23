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
    void dfs(TreeNode *root , string &s) {
        if(!root) return;
        int length = s.length();
        s = s + to_string(root -> val);
        if(!root -> left && !root -> right) {
            int x = stoi(s);
            sum += x;
            s.resize(length);
            return;
        }
        dfs(root -> left , s);
        dfs(root -> right , s);
        s.resize(length);
    }


    int sumNumbers(TreeNode* root) {
        string s = "";
        dfs(root , s);
        return sum;
    }
};