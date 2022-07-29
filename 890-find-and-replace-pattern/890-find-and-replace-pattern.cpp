class Solution {
public:
    
    unordered_map<char,int> m;
    int count = 1;
    string getPattern(string p){
        count = 1;
        m.clear();
        string ans = "";
        for(char ch: p){
            if(m.find(ch) == m.end()){
                m[ch] = count++;
            }
            ans += ('0'+m[ch]);
        }
        return ans;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string p = getPattern(pattern);
        for(auto word: words){
            if(p == getPattern(word))
                ans.push_back(word);
        }
        return ans;
    }
};