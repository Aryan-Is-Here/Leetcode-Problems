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
    pair<int , int> num(string &t , int i) {
        int ans = 0;
        int n = t.length();
        while (i < t.length() && t[i] != '-') {
            ans = ans * 10 + (t[i] - '0');
            i++;
        }
        return {ans , i};
    }
    TreeNode* recoverFromPreorder(string traversal) {
        if(traversal.length() == 0) return nullptr;
        auto val = num(traversal , 0);
        int i = val.second , n = traversal.length();
        TreeNode * root = new TreeNode(val.first);
        TreeNode * curr = root;
        stack<TreeNode *>st;
        st.push(root);
        while(i < n) {
            int count = 0;
            while(i < n && traversal[i] == '-') {
                count++;
                i++;
            }
            auto x = num(traversal , i);
            TreeNode * node = new TreeNode(x.first);
            i = x.second;
            if(count > st.size() - 1) {
                st.top() -> left = node;
                st.push(node);
            }
            else {
                while(st.size() > count) st.pop();
                st.top() -> right = node;
                st.push(node);                
            }
        }
        return root;
    }
};