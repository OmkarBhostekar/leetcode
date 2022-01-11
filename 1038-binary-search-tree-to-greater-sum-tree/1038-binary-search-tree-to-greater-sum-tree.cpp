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
    void bstToGst(TreeNode* root, int &maxsum){
        if(root == NULL)
            return;
        bstToGst(root->right,maxsum);
        maxsum += root->val;
        root->val = maxsum;
        bstToGst(root->left,maxsum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        bstToGst(root,sum);
        return root;
    }
};