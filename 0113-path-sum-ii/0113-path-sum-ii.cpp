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
    void traverse(vector<int> path , TreeNode* root , vector<vector<int>>&ans , int sum , int currsum) {
        if(!root) return;
        currsum += root -> val;
        path.push_back(root -> val);
        if(!root -> right && !root -> left && currsum == sum) {
            ans.push_back(path);
            path.clear();
            return;
        }
        else if(!root -> right && !root -> left) {
            path.clear();
            return;
        }
        if(root -> left) traverse(path , root -> left , ans , sum , currsum);
        if(root -> right) traverse(path , root -> right , ans , sum , currsum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        traverse(path , root , ans , targetSum , 0);
        return ans;
    }
};