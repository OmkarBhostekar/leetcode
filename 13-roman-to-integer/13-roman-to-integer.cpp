class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans = 0;
        for(int i=0; i<s.length()-1; i++){
            if(table[s[i]] < table[s[i+1]]){
                ans -= table[s[i]];
            }else
                ans += table[s[i]];
        }
        ans += table[s.back()];
        return ans;
    }
};