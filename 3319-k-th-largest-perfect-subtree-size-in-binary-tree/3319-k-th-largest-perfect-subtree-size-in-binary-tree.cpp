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
    pair<int , bool> dfs(TreeNode *root) {
        if(!root) return {0 , true};
        auto l = dfs(root -> left) , r = dfs(root -> right);
        if(!l.second || !r.second) return {0 , false};
        if(l.first != r.first) return {0 , false};
        ans.push_back((1 << (l.first + 1)) - 1);
        return {l.first + 1 , true};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(ans.begin() , ans.end() , greater<int>());
        if(ans.size() < k) return -1;
        return ans[k - 1];
    }
};