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
    void inorder(TreeNode *root , int sum , int t , vector<int>&a , vector<vector<int>>&ans) {
        if(!root) return;
        a.push_back(root -> val);
        sum = sum + root -> val;
        if(!root -> left && !root -> right) if(sum == t) ans.push_back(a);
        inorder(root -> left , sum , t , a , ans);
        inorder(root -> right , sum , t , a , ans);
        a.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int>a;
        inorder(root , 0 , targetSum , a , ans);
        return ans;
    }
};