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
    TreeNode* dummy = new TreeNode(0);
    TreeNode* temp = dummy;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        temp->left = NULL;
        temp->right = root;
        temp = temp->right;
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return root;
        inorder(root);
        temp->left = NULL;
        temp->right = NULL;
        return dummy->right;
    }
};