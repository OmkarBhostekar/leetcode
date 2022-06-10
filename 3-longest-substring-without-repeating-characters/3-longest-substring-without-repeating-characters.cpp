class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256, -1);
        int ans = 0, start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (v[s[i]] > start)
                start = v[s[i]];
            v[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};