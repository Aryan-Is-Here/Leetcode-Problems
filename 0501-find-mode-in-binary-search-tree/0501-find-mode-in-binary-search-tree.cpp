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
    unordered_map<int , int>mp;
    void traverse(TreeNode * root) {
        if(!root) return;
        mp[root -> val]++;
        traverse(root -> left);
        traverse(root -> right);
    }
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        int x = 0;
        vector<int> ans;
        for(auto i : mp) x = max(x , i.second);
        for(auto i : mp) if(i.second == x) ans.push_back(i.first);
        return ans;
    }
};