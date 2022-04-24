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
    TreeNode* addTrees(TreeNode* t1, TreeNode* t2){
        if(!t1 and !t2) return NULL;
        int total = 0;
        if(t1) total+=t1->val;
        if(t2) total+=t2->val;
        TreeNode* dummy = new TreeNode(total);
        if(t1 and t2){
            dummy->left = addTrees(t1->left,t2->left);
            dummy->right = addTrees(t1->right,t2->right);
        }else if(!t1){
            dummy->left = addTrees(NULL,t2->left);
            dummy->right = addTrees(NULL,t2->right);
        }else if(!t2){
            dummy->left = addTrees(t1->left,NULL);
            dummy->right = addTrees(t1->right,NULL);
        }
        return dummy;
    } 
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* dummy;
        dummy = addTrees(root1,root2);
        return dummy;
    }
};