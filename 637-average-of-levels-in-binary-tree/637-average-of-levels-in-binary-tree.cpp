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
    void dfs(TreeNode* root, int lvl, map<int,pair<double,double>> &m){
        if(!root) return;
        m[lvl].first += root->val;
        m[lvl].second++;
        if(root->left) dfs(root->left,lvl+1,m);
        if(root->right) dfs(root->right,lvl+1,m);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        map<int,pair<double,double>> m;
        dfs(root, 1, m);
        for(auto x: m){
            ans.push_back(x.second.first/x.second.second);
        }
        return ans;
    }
};