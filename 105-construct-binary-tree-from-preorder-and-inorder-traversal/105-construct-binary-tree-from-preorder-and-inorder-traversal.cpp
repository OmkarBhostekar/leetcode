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
    
    TreeNode* build(vector<int>& preorder, int prestart,int preend, vector<int> inorder, int instart, int inend, map<int,int> &m){
        if(prestart>preend || instart>inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = m[preorder[prestart]];
        if(inroot-instart>0) root->left = build(preorder, prestart+1, preend, inorder, instart, inroot-1,m);
        if(inend-inroot>0) root->right = build(preorder, prestart+inroot-instart+1, preend, inorder, inroot+1, inend,m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        return build(preorder,0, preorder.size()-1, inorder, 0, inorder.size()-1, m);
    }
};