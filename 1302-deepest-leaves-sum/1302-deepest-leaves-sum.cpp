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
    int level = 0;
    int ans = 0;
    void getLevel(TreeNode* root, int temp){
        if(!root) return;
        else if(!root->left and !root->right){
            level = max(level,temp+1);
            return;
        }
        if(root->left) getLevel(root->left,temp+1);
        if(root->right) getLevel(root->right,temp+1);
    }
    
    void leavesSum(TreeNode* root, int temp){
        if(!root) return;
        else if(level == temp){
            ans += root->val;
            return;
        }
        if(root->left) leavesSum(root->left,temp+1);
        if(root->right) leavesSum(root->right,temp+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        getLevel(root,0);
        leavesSum(root,1);
        return ans;
    }
};