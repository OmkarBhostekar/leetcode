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
    void preOrder(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> &path, vector<TreeNode*> &pp, vector<TreeNode*> &pq){
        if(!root) return;
        path.push_back(root);
        if(root == p)
            pp = path;
        else if(root == q)
            pq = path;
        preOrder(root->left,p,q,path,pp,pq);
        preOrder(root->right,p,q,path,pp,pq);
        path.pop_back();
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pp,pq,temp;
        preOrder(root,p,q,temp,pp,pq);
        TreeNode* lca = root;
        int i=0;
        while(i<pp.size() && i<pq.size()){
            if(pp[i] != pq[i])
                return lca;
            lca = pp[i++];
        }
        return lca;
    }
};