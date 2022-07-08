class Solution {
public:
    void generate(int n, int o, int c, string s, vector<string> &ans){
        if(o==n && c==n){
            ans.push_back(s);
            return;
        }
        if(o < n){
            generate(n, o+1, c, s+'(', ans);
        }
        if(o > c){
            generate(n, o, c+1, s+')', ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, 0, 0, "", ans);
        return ans;
    }
};