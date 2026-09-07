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
    unordered_map<int , int> mp;
    int freq = 0;
    int dfs(TreeNode *root) {
        if(!root) return 0;
        int sum = root -> val + dfs(root -> left) + dfs(root -> right);
        mp[sum]++;
        freq = max(mp[sum] , freq);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        for(auto i : mp) if(i.second == freq) ans.push_back(i.first);
        return ans;
    }
};