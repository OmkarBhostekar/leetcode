class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v1(26,0),v2(26,0);
        for(auto ch: ransomNote) v1[ch-'a']++;
        for(auto ch: magazine) v2[ch-'a']++;
        for(int i=0;i<26;i++){
            if(v1[i]>v2[i]) return false;
        }
        return true;
    }
};