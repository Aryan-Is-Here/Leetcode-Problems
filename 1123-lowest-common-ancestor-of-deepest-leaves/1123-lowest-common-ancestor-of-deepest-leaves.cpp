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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode *> q;
        TreeNode * first , *last;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0 ; i < n ; i++) {
                auto t = q.front();
                q.pop();
                if(i == 0) first = t;
                if(i == n - 1) last = t;
                if(t -> left) q.push(t -> left);
                if(t -> right) q.push(t -> right);
            }
        }
        if(first == last) return last;
        return lca(root , first , last);
    }
};