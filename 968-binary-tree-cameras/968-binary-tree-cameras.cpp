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
    void dfs(TreeNode* root, TreeNode* parent, unordered_set<TreeNode*> &s, int &ans){
        if(!root) return;
        dfs(root->left, root, s, ans);
        dfs(root->right, root, s, ans);
        
        if((!parent and s.find(root) == s.end()) or s.find(root->left) == s.end() or s.find(root->right) == s.end()){
            ans++;
            s.insert(root);
            s.insert(parent);
            s.insert(root->left);
            s.insert(root->right);
        }
    }
    
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        unordered_set<TreeNode*> s;
        int ans = 0;
        s.insert(NULL);
        dfs(root,NULL, s, ans);
        return ans;
    }
};