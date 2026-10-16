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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            vector<int>a;
            int n = q.size();
            while(n--) {
                auto t = q.front();
                q.pop();
                a.push_back(t -> val);
                if(t -> left) q.push(t -> left);
                if(t -> right) q.push(t -> right);
            }
            ans.push_back(a);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};