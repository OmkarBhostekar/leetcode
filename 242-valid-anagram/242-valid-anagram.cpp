class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26,0);
        for(auto x: s) arr[x-'a']++;
        for(auto x: t) arr[x-'a']--;
        for(auto x: arr) if(x!=0) return false;
        return true;
    }
};