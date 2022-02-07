class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for(int i=0; i<t.size(); i++){
            ans += (int) t[i];
            if(i<s.size()){
                ans -= (int) s[i];
            }
        }
        return (char) ans;
    }
};