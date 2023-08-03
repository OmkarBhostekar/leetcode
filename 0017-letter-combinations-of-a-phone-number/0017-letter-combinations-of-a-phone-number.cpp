class Solution {
public:
    vector<vector<char>> dict = {
        {},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}
    };
    
    void rec(string digits, int i, string temp, vector<string> &ans){
        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }
        for(char c: dict[digits[i]-'0'-1]){
            rec(digits, i+1, temp+c,ans);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        rec(digits, 0, "", ans);
        return ans;
    }
};