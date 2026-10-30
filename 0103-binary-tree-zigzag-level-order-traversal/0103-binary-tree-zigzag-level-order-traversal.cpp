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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        bool t = false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int>a;
            for(int i = 0 ; i < n ; i++) {
                auto temp = q.front();
                q.pop();
                a.push_back(temp -> val);
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            if(t) reverse(a.begin() , a.end());
            t =!t;
            ans.push_back(a);
        }
        return ans;
    }
};