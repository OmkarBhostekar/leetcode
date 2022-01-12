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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* pnode = new TreeNode(val);
            return pnode;
        }
        if(val > root->val){
            if(root->right != NULL)
                insertIntoBST(root->right,val);
            else{
                TreeNode* pnode = new TreeNode(val);
                root->right = pnode;
            }
        }else{
            if(root->left != NULL)
                insertIntoBST(root->left,val);
            else{
                TreeNode* pnode = new TreeNode(val);
                root->left = pnode;
            }
        }
        return root;
    }
};