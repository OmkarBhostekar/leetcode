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
    void dfs(TreeNode* root, TreeNode* parent, int x, int y, pair<TreeNode*, int> &a, pair<TreeNode*, int> &b, int lvl){
        if(!root) return;
        if(root->val == x) a = {parent, lvl};
        if(root->val == y) b = {parent, lvl};
        dfs(root->left, root, x, y, a, b, lvl+1);
        dfs(root->right, root, x, y, a, b, lvl+1);
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*, int> a,b;
        dfs(root, NULL, x, y, a, b, 0);
        return a.first != b.first and a.second == b.second;
    }
};