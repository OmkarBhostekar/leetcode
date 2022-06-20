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
    void rec(TreeNode* root, int lvl, int &ans){
        if(!root) return;
        if(!root->left && !root->right){
            ans = min(ans,lvl);
        }
        rec(root->left, lvl+1, ans);
        rec(root->right, lvl+1, ans);
    }
    
    int minDepth(TreeNode* root) {
        int ans = INT_MAX;
        rec(root, 1, ans);
        return ans == INT_MAX ? 0 : ans;
    }
};