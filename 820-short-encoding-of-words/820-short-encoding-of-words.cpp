class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s;
        for(auto w: words) s.insert(w);
        for(auto w: words){
            for(int i=1; i<w.size(); i++)
                s.erase(w.substr(i));
        }
        int ans = 0;
        for(auto x: s)
            ans += x.length()+1;
        return ans;
    }
};