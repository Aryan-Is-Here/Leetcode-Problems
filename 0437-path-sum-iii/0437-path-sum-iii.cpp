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
    int count = 0;
    void dfs(TreeNode * root , long long sum , int t , unordered_map<long long , int>&mp) {
        if(!root) return;
        sum += root -> val;
        if(mp.find(sum - t) != mp.end()) count += mp[sum - t];
        mp[sum]++;
        dfs(root -> left , sum , t , mp);
        dfs(root -> right , sum , t , mp);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long , int> mp;
        mp[0] = 1;
        dfs(root , 0 , targetSum , mp);
        return count;
    }
};