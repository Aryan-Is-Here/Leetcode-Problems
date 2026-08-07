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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        TreeNode *current = root , *prev;
        while(current) {
            if(!current -> left) {
                ans.push_back(current -> val);
                current = current -> right;
            }
            else {
                prev = current -> left;
                while(prev -> right && prev -> right != current) prev = prev -> right;
                if(!prev -> right) {
                    prev -> right = current;
                    current = current -> left;
                }
                else {
                    prev -> right = nullptr;
                    ans.push_back(current -> val);
                    current = current -> right;
                }
            }
        }
        return ans;
    }
};