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
    bool dfs(TreeNode* root, int cur, int t){
        if(!root) return false;
        cur += root->val;
        if(cur==t and !root->left and !root->right){
            return true;
        }
        return dfs(root->left,cur,t) || dfs(root->right,cur,t);
        
    }
    
    bool hasPathSum(TreeNode* root, int t) {
        return dfs(root,0,t);
    }
};