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
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    
    void bfs(TreeNode* root,vector<vector<int>> &ans,int lvl){
        if(!root) return;
        ans[lvl].push_back(root->val);
        bfs(root->left,ans,lvl+1);
        bfs(root->right,ans,lvl+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        if(h==0) return {};
        vector<vector<int>> ans(h);
        bfs(root,ans,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};