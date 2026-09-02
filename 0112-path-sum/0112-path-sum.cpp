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
    bool ans = false;
    void inorder(TreeNode* root , int sum , int t) {
        if(!root -> left && !root -> right) {
            if(sum == t) ans = true;
            return;
        }
        if(root -> left) inorder(root -> left , sum + root -> left -> val , t);
        if(root -> right) inorder(root -> right , sum + root -> right -> val , t);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        inorder(root , root -> val , targetSum);
        return ans;
    }
};