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
    void inorder(TreeNode *root , int sum , int t , vector<int>a , vector<vector<int>>&ans) {
        if(!root -> left && !root -> right) {
            if(sum == t) ans.push_back(a);
            return;
        }
        if(root -> left) {
            vector<int>temp = a;
            temp.push_back(root -> left -> val);
            inorder(root -> left , sum + root -> left -> val , t , temp , ans);
        }
        if(root -> right) {
            vector<int>temp = a;
            temp.push_back(root -> right -> val);
            inorder(root -> right , sum + root -> right -> val , t , temp , ans);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int>a;
        a.push_back(root -> val);
        inorder(root , root -> val , targetSum , a , ans);
        return ans;
    }
};