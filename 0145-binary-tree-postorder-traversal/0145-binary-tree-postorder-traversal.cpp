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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*>st1 , st2;
        TreeNode* curr = root;
        st1.push(curr);
        while(!st1.empty()) {
            curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr -> left) st1.push(curr -> left);
            if(curr -> right) st1.push(curr -> right);
        }
        while(!st2.empty()) {
            ans.push_back(st2.top() -> val);
            st2.pop();
        }
        return ans;
    }
};