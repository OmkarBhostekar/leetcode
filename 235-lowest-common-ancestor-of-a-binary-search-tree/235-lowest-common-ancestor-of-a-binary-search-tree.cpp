/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void preorder(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> &curPath, vector<TreeNode*> &path1, vector<TreeNode*> &path2){
        if(!root) return;
        curPath.push_back(root);
        if(root == p) path1 = curPath;
        if(root == q) path2 = curPath;
        preorder(root->left, p, q, curPath, path1, path2);
        preorder(root->right, p, q, curPath, path1, path2);
        curPath.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        vector<TreeNode*> path1,path2,curPath;
        preorder(root, p, q, curPath, path1, path2);
        int i=0;
        TreeNode* temp = NULL;
        while(i<min(path1.size(),path2.size())){
            if(path1[i] != path2[i]) return temp;
            temp = path1[i];
            i++;
        }
        return temp;
    }
};