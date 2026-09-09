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
    vector<int>ans;
    int count = 0 , maxcount = 0;
    TreeNode* prev = nullptr;
    void traverse(TreeNode * root) {
        if(!root) return;
        traverse(root -> left);
        if(prev && root -> val != prev -> val) count = 1;
        else count++;
        prev = root;
        if(count > maxcount) {
            maxcount = count;
            ans.clear();
            ans.push_back(root -> val);
        }
        else if(count == maxcount) ans.push_back(root -> val);
        traverse(root -> right);
    }
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        return ans;
    }
};