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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        TreeNode * prev1;
        TreeNode* prev2 = nullptr;
        TreeNode * curr = root;
        bool ans = true;
        while(curr) {
            if(!curr -> left) {
                if(prev2 && curr -> val <= prev2 -> val) ans = false;
                prev2 = curr;
                curr = curr -> right;
            }
            else {
                prev1 = curr -> left;
                while(prev1 -> right && prev1 -> right != curr) prev1 = prev1 -> right;
                if(!prev1 -> right) {
                    prev1 -> right = curr;
                    curr = curr -> left;
                }
                else {
                    prev1 -> right = nullptr;
                    if(prev2 && curr -> val <= prev2 -> val) ans = false;
                    prev2 = curr;
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};