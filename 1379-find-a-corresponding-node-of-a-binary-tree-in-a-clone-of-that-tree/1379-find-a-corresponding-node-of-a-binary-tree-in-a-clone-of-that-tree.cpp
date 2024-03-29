/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* og, TreeNode* copy, TreeNode* target, TreeNode*& ans) {
        if(!og) return;
        
        if(og == target) {
            ans = copy;
            return;
        }
        
        dfs(og->left, copy->left, target, ans);
        dfs(og->right, copy->right, target, ans);
        
        return;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = nullptr;
        dfs(original, cloned, target, ans);
        return ans;
    }
};