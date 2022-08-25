class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26,0);
        for(auto ch: magazine) v[ch-'a']++;
        for(auto ch: ransomNote) v[ch-'a']--;
        for(int i=0;i<26;i++){
            if(v[i]<0) return false;
        }
        return true;
    }
};