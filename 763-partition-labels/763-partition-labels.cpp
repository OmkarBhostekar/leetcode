class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mpp;
        for(int i=0; i<s.length(); i++){
            mpp[s[i]] = i;
        }
        
        int m=0, prev = -1;
        vector<int> ans;
        
        for(int i=0; i<s.length(); i++){
            m = max(m,mpp[s[i]]);
            if(m == i){
                ans.push_back(m-prev);
                prev = m;
            }
        }
        return ans;
    }
};