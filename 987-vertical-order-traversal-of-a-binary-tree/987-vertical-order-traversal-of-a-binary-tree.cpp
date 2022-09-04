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
    void preOrder(TreeNode* root, map<int,vector<pair<int,int>>> &m, int lvl, int depth){
        if(!root) return;
        m[lvl].push_back({depth, root->val});
        if(root->left) preOrder(root->left,m,lvl-1, depth+1);
        if(root->right) preOrder(root->right,m,lvl+1, depth+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int,vector<pair<int,int>>> m;
        preOrder(root,m,0,0);
        for(auto x: m){
            auto y = x.second;
            sort(y.begin(),y.end());
            vector<int> temp;
            for(auto z: y) temp.push_back(z.second);
            ans.push_back(temp);
        }
        return ans;
    }
};