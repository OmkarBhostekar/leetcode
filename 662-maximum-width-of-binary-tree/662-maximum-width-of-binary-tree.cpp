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
    int widthOfBinaryTree(TreeNode* root) {
        int size;
        int minIdx, maxIdx;
        int ans=1;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        pair<TreeNode*, int> temp;
        while(!q.empty()){
            size = q.size();
            minIdx = q.front().second;
            maxIdx = q.back().second;
            while(size--){
                temp = q.front();
                q.pop();
                if(temp.first->left)
                    q.push({temp.first->left,2*(temp.second-maxIdx)});
                if(temp.first->right)
                    q.push({temp.first->right,2*(temp.second-maxIdx)+1});
                ans = max(ans,(maxIdx-minIdx+1));
            }
        }
        return ans;
    }
};