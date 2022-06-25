class Solution {
public:
    
    void letterHelper(string digits, vector<vector<char>> &keys, vector<string> &ans, string temp, int i, int n){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(char x: keys[digits[i]-'0']){
            letterHelper(digits, keys, ans, (temp+x), i+1, n);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        
        vector<vector<char>> keys = {
            {},{},{ 'a','b','c' }, { 'd','e','f' }, { 'g','h','i' }, { 'j','k','l' }, 
            { 'm','n','o' }, { 'p','q','r','s' }, { 't','u','v' }, { 'w','x','y','z' }
        };
        
        letterHelper(digits, keys, ans, "", 0, digits.size());
        return ans;
    }
};