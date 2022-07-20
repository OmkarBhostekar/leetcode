class Solution {
public:
    bool compare(string s,string com){
        int k=0;
        for(int i= 0;i<s.size();i++){
             if(s[i]==com[k]) k++;
            if(com.size()==k)return true;
         }
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto it:mp){
            if(compare(s,it.first))ans+=it.second;
        }
        return ans;
    }
};