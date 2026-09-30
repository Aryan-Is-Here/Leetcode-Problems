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
    bool check(TreeNode *root , int h , int n) {
        int b = 1 << (h - 1);
        while(b > 0) {
            if(b & n) root = root -> right;
            else root = root -> left;
            if(!root) return false;
            b >>= 1;
        }
        return true;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *temp = root;
        int h = 0;
        while(temp -> left) {
            temp = temp -> left;
            h++;
        }
        if(h == 0) return 1;
        int low = 0 , high = (1 << h) - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(root , h , mid)) low = mid + 1;
            else high = mid - 1;
        }
        return (int)(1 << h) + low - 1;
    } 
};