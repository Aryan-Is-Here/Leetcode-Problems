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
        stack<TreeNode*>st;
        TreeNode* curr = root , *prev = nullptr;
        while(curr || !st.empty()) {
            while(curr) {
                st.push(curr);
                curr = curr -> left;
            }
            TreeNode* node = st.top();
            if(node -> right && node -> right != prev) curr = node -> right;
            else {
                ans.push_back(node -> val);
                st.pop();
                prev = node;
            }
        }
        return ans;
    }
};