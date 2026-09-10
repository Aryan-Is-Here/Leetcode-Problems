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
// class Solution {
// public:
//     int ans=0;
//     int post(TreeNode *root,int &count)
//     {
//         if(!root)
//         {
//             count=0;
//             return 0;
//         }
//         int leftcount=0,rightcount=0;
//         int left=post(root->left,leftcount);
//         int Right=post(root->right,rightcount);

//         count=leftcount+rightcount+1;
//         int sum=left+Right+root->val;

//         int avg=sum/count;
//         if(avg==root->val)
//         {
//             ans++;
//         }
//         return sum;


//     }
//     int averageOfSubtree(TreeNode* root) {
//         int count;
//         post(root,count);
//         return ans;
        
//     }
// };

class Solution {
public:
    int ans = 0;
    int postorder(TreeNode *root , int &count) {
        if(!root) {
            count = 0;
            return 0;
        }
        int leftcount = 0 , rightcount = 0;
        int left = postorder(root -> left , leftcount);
        int right = postorder(root -> right , rightcount);
        count = leftcount + rightcount + 1;
        int sum = left + right + root -> val;
        if(sum / count  == root -> val) ans++;
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        int c = 0;
        postorder(root , c);
        return ans;
    }
};