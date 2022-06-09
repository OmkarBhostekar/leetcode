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
    void dfs(TreeNode* root, int cur, int t,vector<int> path, vector<vector<int>> &ans){
        if(!root) return;
        cur += root->val;
        path.push_back(root->val);
        if(cur==t and !root->left and !root->right){
            ans.push_back(path);
            return;
        }
        dfs(root->left,cur,t,path,ans); 
        dfs(root->right,cur,t,path,ans);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        dfs(root,0,t,{},ans);
        return ans;
    }
};