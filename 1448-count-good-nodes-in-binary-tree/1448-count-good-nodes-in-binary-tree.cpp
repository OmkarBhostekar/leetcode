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
    int preOrder(TreeNode* root, int mx){
        if(!root) return 0;
        int ans=0;
        if(root->val >= mx) ans++;
        ans += preOrder(root->left,max(mx,root->val));
        ans += preOrder(root->right,max(mx,root->val));
        return ans;
    }
    
    int goodNodes(TreeNode* root) {
        return preOrder(root, INT_MIN);
    }
};