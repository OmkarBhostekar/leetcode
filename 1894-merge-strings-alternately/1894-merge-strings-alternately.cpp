class Solution {
public:
    string mergeAlternately(string s, string t) {
        string ans = "";
        int n = s.length(), m = t.length();
        int i=0,j=0;
        while(i<min(n,m) && j<min(n,m)){
            ans += s[i];
            ans += t[j];
            i++,j++;
        }
        while(i<n) ans += s[i++];
        while(j<m) ans += t[j++];
        return ans;
    }
};