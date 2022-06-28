class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        string ans="";
        for(int idx=0;idx<s.length();idx++){
            char x = s[idx];
            for(auto str: strs){
                if(idx>=str.length() || str[idx] != x) return ans;
            }
            ans += x;
        }
        return ans;
    }
};